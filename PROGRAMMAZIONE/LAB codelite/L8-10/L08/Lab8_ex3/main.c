#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#define MAXL 200
#define MAXS 50
#define MAXE 8
#define FP "pg.txt"
#define FI "inventario.txt"


typedef struct{          //STATISTICHE  Stat_t;
    int hp;
    int mp;
    int atk;
    int def;
    int mag;
    int spr;
    
}stat_t;


typedef struct{    //INVENTARIO inv_t
    char nome[MAXS];
    char tipo[MAXS];
    stat_t stat;
    
}inv_t;


typedef struct{           //INVENTARIO WRAPPER tabInv_t
    int nInv;
    
    inv_t  *vettInv;
    
}tabInv_t;
typedef tabInv_t  *tabInv;

typedef struct{     //EQUIPAGGIAMENTO tabEquip_t 
    
    inv_t inUso;
    inv_t *vettEq[MAXE];
    
}tabEquip_t ;

typedef struct{            //PERSONAGGIO pg_t
    char codice[6+1];
    char nome[MAXS];
    char classe[MAXS];
    stat_t  stat;
    tabEquip_t  *equip;
    int e, n;
    
    
}pg_t;

typedef struct nodo* link;
typedef struct nodo{        //NODO DELLA LISTA CONTIENE VAL (PERSONAGGIO)  E LINK nodoPg_t
    pg_t personaggio;
    
    link next; 
    
}nodoPg_t;


typedef struct{    //LISTA CON PUNTATORI AI NODI E NUMERO NODI TabPg_t
    
    link head;
    link tail;
    int nPg;
    
}tabPg_t;

typedef tabPg_t * tabPg;

void set_inUso(link target);
int check_equip(link x);
void componi_equip(tabPg listap, tabInv invp);
void aggiorna_stat(link target, inv_t oggetto,int k);
void stampa_equipaggiamento(link x);
link ricerca_codice(tabPg listap,char* scelta,link *prev);

void inserisci_lista(tabPg listap, pg_t pers);
void elimina_personaggio(tabPg listap);
void libera_nodo(link x);
void aggiungi_personaggio(tabPg listap, tabInv invp,char *file);
void libera_lista(tabPg listap);
void stampa_personaggio(link x);
void stampa_personaggi(tabPg listap);
pg_t leggi_personaggio(FILE *f);
void carica_persoanggi(tabPg listap,tabInv invp);
int  conta_personaggi(tabPg listap,FILE * f);
link new_node(pg_t val , link next);

void stampa_inventario(tabInv invp);
void stampa_oggetto(inv_t oggetto);
void stampa_stat(stat_t stat,int min);
void libera_inventario(tabInv invp);
void carica_inventario(tabInv invp);
stat_t leggi_stat(FILE *f);


int main()
{
    tabPg listap=malloc(sizeof(tabPg_t));
    tabInv invp=malloc(sizeof(tabInv_t));
    int scelta;
    char file[MAXS];
    link test,p;
    char t[MAXS];
    
    carica_inventario(invp);
    carica_persoanggi(listap,invp);
    
do{
    printf("MENU\nstampa elenco personaggi-1\nstampa inventario-2\naggiungi/rimuovi oggetto-3\naggiungi personaggio-4\nelimina personaggio-5\nstampa personaggio con il suo equipaggiamento-6\ntermina-0\n");
    scanf("%d",&scelta);
    
    switch(scelta){
        case 0:
            printf("finito!\n");
            break;
     
        case 1:
            stampa_personaggi(listap);         
            break;
            
        case 2:
          stampa_inventario(invp);
            break;
        
        case 3:
                componi_equip( listap, invp);
            break;
            
            case 4:
                    printf("da dove vuoilegerlo?\n");
                    scanf("%s",file);
                    aggiungi_personaggio(listap,invp,file);
                    break;
            case 5:
            elimina_personaggio(listap);
            break;
            case 6:
            printf("codice personagio ");
            scanf("%s",t);
            test=ricerca_codice(listap,t,&p);
            stampa_personaggio(test);
            stampa_equipaggiamento(test);
            break;
        default: 
            printf("non hai inserito un comando corretto\n");
    }
    

}while(scelta!=0);
    
    
    libera_inventario(invp);
    libera_lista(listap); 
    
    
	return 0;
}

void carica_inventario(tabInv invp){
    int i;
  
    
    FILE *fi;
    fi=fopen(FI,"r");
    assert(fi!=NULL);
    
    fscanf(fi,"%d",&invp->nInv);
    
    invp->vettInv=(inv_t *)malloc(invp->nInv * sizeof(inv_t));
    assert(invp->vettInv !=NULL);
    
    for(i=0;i<invp->nInv;i++){
        fscanf(fi,"%s %s", invp->vettInv[i].nome,invp->vettInv[i].tipo);
        
        invp->vettInv[i].stat=leggi_stat(fi);        
    }
    

    
    
    
}

stat_t leggi_stat(FILE *f){
    
    stat_t tmp;
    
    fscanf(f,"%d%d%d%d%d%d",&tmp.hp,&tmp.mp,&tmp.atk,&tmp.def,&tmp.mag,&tmp.spr);
    
    return tmp;
    
}

void libera_inventario(tabInv invp){
    
    free(invp->vettInv);
     free(invp);
}

void stampa_inventario(tabInv invp){
    
    printf("INVENTARIO:\n");
    for(int i=0;i<invp->nInv;i++){
       stampa_oggetto(invp->vettInv[i]);
    }
}
void stampa_oggetto(inv_t oggetto){
     printf("%s %s ",oggetto.nome,oggetto.tipo);
     stampa_stat(oggetto.stat,INT_MIN);
}
void stampa_stat(stat_t tmp,int min){
    
    printf("%d %d %d %d %d %d\n",tmp.hp<min? 0:tmp.hp ,tmp.mp<min? 0:tmp.mp,tmp.atk<min? 0:tmp.atk,tmp.def<min? 0:tmp.def,tmp.mag<min? 0:tmp.mag,tmp.spr<min? 0:tmp.spr);
}

pg_t leggi_personaggio(FILE *f){
    
   
    pg_t tmp;
    
    fscanf(f,"%s %s %s",tmp.codice,tmp.nome,tmp.classe);
    tmp.stat=leggi_stat(f);
    
    
  
    return tmp;
}

void carica_persoanggi(tabPg listap,tabInv invp){
    
    int i;
    int n=0;
    pg_t pers;
    
    FILE *fin=fopen(FP,"r");
    assert(fin!=NULL);
    
    n=conta_personaggi(listap,fin);
    fclose(fin);
    
    listap->nPg=n;
    
    fin=fopen(FP,"r");
    assert(fin!=NULL);
    
  
    
    listap->head=listap->tail=NULL;
    for(i=0;i<listap->nPg;i++){
        
        pers=leggi_personaggio(fin);
        
        inserisci_lista(listap,pers);
        }
       
    
    fclose(fin);
  
    
}

int conta_personaggi(tabPg listap,FILE * f){
    
    char tmp[MAXL];
    int  n=0;
    while(fgets(tmp,MAXL,f)!=NULL) n++;
    
    return n;   
   
    
}

link  new_node(pg_t val , link next){
    
    link x=(link)malloc(sizeof(nodoPg_t));
    if(x==NULL) return NULL;
    
    x->personaggio=val;
    x->next=next;
    

    return x;
}

void stampa_personaggi(tabPg listap){
    
    printf("PERSOANGGI:\n");
    
    link h=listap->head;
    if(h==NULL) printf("lista vuota");
    
    while(h!=NULL){
        
        stampa_personaggio(h);
        
        h=h->next;
    }

}

void stampa_personaggio(link x){

    printf("%s %s %s ",x->personaggio.codice, x->personaggio.nome, x->personaggio.classe);
    stampa_stat(x->personaggio.stat,0);
    
    if(x->personaggio.e!=0){
    printf("    |%s %s ",x->personaggio.equip->inUso.nome , x->personaggio.equip->inUso.tipo);
    stampa_stat(x->personaggio.equip->inUso.stat,INT_MIN);
    }

}

void libera_lista(tabPg listap){
    
    link x=listap->head;
    link p;
    while(x!=NULL){
        
        p=x->next;
       libera_nodo(x);
        x=p;
    }
    
    free(listap);
    
    
}

void componi_equip(tabPg listap, tabInv invp){
    char scelta[MAXS];
    int s;
    int i;
    int k;
    link target,p;
    printf("codice personaggio a cui vuoi aggiungere/rimuovere");
    scanf("%s",scelta);
    
    target=ricerca_codice(listap,scelta,&p);
    if (target==NULL) return;
    stampa_personaggio(target);
    
    
    
    printf("vuoi aggiungere(1) o togliere(0) oggetti?\n");
    scanf("%d",&s);
    
    if(s==1){
        if(check_equip(target)==1) {
            stampa_equipaggiamento(target);
            printf("equipaggiamento completo\nvuoi cambiare l'oggetto in uso?(indice della posizione nell'equipaggiamento o -1)\n");
            set_inUso(target);
            
            return;
        } 
        
        k=1;
        printf("scegli quali oggetti mettere nell'equipaggiamento (indici del vettore inventario)\npremi -1 per fermarti\n");
        for(i=0;i<MAXE ;i++){
            if(target->personaggio.equip->vettEq[i]==NULL){
            printf("indice:\n");
            scanf("%d",&s);
            if(s==-1) break;
            stampa_oggetto(invp->vettInv[s]);
            
            target->personaggio.equip->vettEq[i]=&(invp->vettInv[s]);
            }
        }
        target->personaggio.n=i;
        stampa_equipaggiamento(target);
        
        set_inUso(target);
        
    }
    
else{
          if(check_equip(target)==0) {
            printf("equipaggiamento vuoto\n");
            return;
        } 
        k=0;
        stampa_equipaggiamento(target);
        printf("quale vuoi rimuovere (indice del vettore)\n");
        scanf("%d",&s);
        
         if(target->personaggio.equip->vettEq[s] !=NULL){
             
             target->personaggio.n--;
         }
          else {
              printf("oggetto non trovato\n");
              return;
          }
        
        if( strcmp(target->personaggio.equip->vettEq[s]->nome,target->personaggio.equip->inUso.nome)==0) {
            target->personaggio.e=0;
                 
         aggiorna_stat(target,*(target->personaggio.equip->vettEq[s]),k);
         }
         target->personaggio.equip->vettEq[s]=NULL;

    }
}

void stampa_equipaggiamento(link x){
    printf("[in uso ");
    if(x->personaggio.e==1)  stampa_oggetto(x->personaggio.equip->inUso);
    
    
    else printf("VUOTO\n");
    
    
    printf("    equipaggiamento: \n");
    if(x->personaggio.n ==0) printf("    nessun oggetto equipaggiato\n");
    for(int i=0;i< MAXE;i++){
        if(x->personaggio.equip->vettEq[i]==NULL) printf("    vuoto\n");
        else{
        printf("    [ ");
        stampa_oggetto(*(x->personaggio.equip->vettEq[i]));
        }
    }
    
    
}
link ricerca_codice(tabPg listap,char* scelta,link *prev){
    link x;
    link p=NULL;
   
    if(listap->head==NULL){
        printf("lista vuota\n");
        return NULL;
    }
    
    for(x=listap->head;x!=NULL; p=x, x=x->next){
        if(strcmp(x->personaggio.codice,scelta)==0) {
            
            *prev=p;            
            
            return x;
        }
        
    }
    printf("non trovato");
    return NULL;

}

void aggiorna_stat(link target, inv_t oggetto,int k){
    
    if(k==1){
    target->personaggio.stat.atk+=oggetto.stat.atk;
    target->personaggio.stat.def+=oggetto.stat.def;
    target->personaggio.stat.mag+=oggetto.stat.mag;
    target->personaggio.stat.spr+=oggetto.stat.spr;
    target->personaggio.stat.hp+=oggetto.stat.hp;
    target->personaggio.stat.mp+=oggetto.stat.mp;
    
    }
    else{
    target->personaggio.stat.atk-=oggetto.stat.atk;
    target->personaggio.stat.def-=oggetto.stat.def;
    target->personaggio.stat.mag-=oggetto.stat.mag;
    target->personaggio.stat.spr-=oggetto.stat.spr;
    target->personaggio.stat.hp-=oggetto.stat.hp;
    target->personaggio.stat.mp-=oggetto.stat.mp;
    }
}

int check_equip(link x){
    
    if(x->personaggio.n >=8)  return 1;
    
     if(x->personaggio.n ==0)  return 0;
     
     return -1;
}

void aggiungi_personaggio(tabPg listap, tabInv invp,char *file){
    
    int i;
    int n=1;
    pg_t nuovo;
    FILE *fin=fopen(file,"r");
    if(fin==NULL) {
        fin=stdin;
        printf(" codice  nome classe stats\n");
    }
    else{
    n=conta_personaggi(listap,fin);
    fclose(fin);
    fin=fopen(file,"r");
   
    }
    listap->nPg+=n;
    
    for(i=0;i<n;i++){
    nuovo= leggi_personaggio(fin);
    
    inserisci_lista(listap,nuovo);
    }
    
    if(fin!=stdin){
    fclose(fin);
    }
    
   
    
}

void inserisci_lista(tabPg listap, pg_t pers){
    
    int j;
    
     //se lista vuota
        if(listap->head ==NULL){
           listap->head = listap->tail=new_node(pers,NULL);
        }
        
        //inserzione in coda
        else{
        listap->tail->next=new_node(pers,NULL);
        listap->tail=listap->tail->next;
        }
        
        listap->tail->personaggio.equip=(tabEquip_t*)malloc(sizeof(tabEquip_t));
  
        for(j=0;j<MAXE;j++){
        listap->tail->personaggio.equip->vettEq[j]=(inv_t*)malloc(sizeof(inv_t));
        listap->tail->personaggio.equip->vettEq[j]=NULL;
    
  }
        listap->tail->personaggio.e=0;
        listap->tail->personaggio.n=0;
    
}

void elimina_personaggio(tabPg listap){
    
    link target,prev;
    char tmp[MAXS];
    printf("digita il codice del personaggio da eliminare\n");
    scanf("%s",tmp);
    
    target=ricerca_codice(listap,tmp,&prev);
    if(target==NULL) return;

    if(prev==NULL){
        listap->head=target->next;
    }
    else if(target->next==NULL){
        listap->tail=prev;
        listap->tail->next=NULL;
    }
    else{
    prev->next=target->next;
    }
    stampa_personaggio(target);
    
    libera_nodo(target);
    
    listap->nPg--;
    
    
    
    
}
void libera_nodo(link x){
    
    for(int i=0;i<MAXE;i++){
            free(x->personaggio.equip->vettEq[i]);
        }
        free(x->personaggio.equip);
        free(x);
    
}

void set_inUso(link target){
    
    int s;
    
        printf("quale oggetto vuoi IN USO , -1 se non ne vuoi nessuno\n");
        scanf("%d",&s);
        if(s!=-1 && s<target->personaggio.n){
            aggiorna_stat(target,target->personaggio.equip->inUso,-1);
            target->personaggio.equip->inUso=*(target->personaggio.equip->vettEq[s]);
            target->personaggio.e=1;
            aggiorna_stat(target,*(target->personaggio.equip->vettEq[s]),1);
        }
        else printf("oggetto non trovato\n");
        
    
    
}


