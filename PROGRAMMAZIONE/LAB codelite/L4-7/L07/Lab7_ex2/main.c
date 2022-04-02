#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#define NOMEFILE "anag1.txt"
#define MAXL 350
#define L 50

typedef struct{
    int a;
    int m;
    int g;
}DATA_S;

typedef struct {
    char* cod;
    char *n;
    char*c;
    char* data;
    char* via;
    char* city; 
    int cap;
    DATA_S dat_i;
  
}DATI_S;

typedef struct nodo_s *Link;
typedef struct nodo_s {
  DATI_S val;
  Link next;
} LISTA;


Link ricerca_data(DATI_S val, Link head,Link*prev);
void canc_dat(Link *head, Link *tail);
void libera(Link nodo);
Link cancellazione(Link x,Link *head, Link *tail, Link *prev);
void stampa_singolo(Link x);
Link ricerca_codice(Link head, Link *prev);
FILE* acquisizione(int * R);
void inserisci(Link *head, DATI_S * elenco);
Link crea_lista(Link head, Link *f);
int confronta_date(DATI_S x,DATI_S y);
void stampa_lista(Link head);
Link crea_nodo(DATI_S val, Link next);
DATI_S leggi_file(FILE *fp,DATI_S *elenco);
int main()
{


 Link head=NULL;
 Link h=NULL;
 Link x;
 Link prev;
int scelta;

head=crea_lista(head,&h);  // aggiorna i puntatori alla testa e alla coda oltre a creare la lista
stampa_lista(head);


do {
  
    printf("MENU\n\n1-inserisci nuovo elemento\n2-ricerca codice\n3-cancella per data\n4-stampa\n0- fine\n");
    scanf("%d",&scelta);
    
    switch(scelta){
        case 0:
            printf("finito!\n");
            break;
     
        case 1:
            head=crea_lista(head,&h);  // aggiorna i puntatori alla testa e alla coda oltre a creare la lista
            stampa_lista(head);
            break;
            
        case 2:
           x=ricerca_codice(head,&prev);
           if(x==NULL) printf("valore non trovato\n");
          else   {
              
              x=cancellazione(x,&head,&h,&prev);
              
          }
          stampa_lista(head);
            break;
        
        case 3:
      canc_dat( &head, &h);
      stampa_lista(head);
      break;
      
        case 4:
        stampa_lista(head);
           break;
           
        default: 
            printf("non hai inserito un comando corretto\n");
    }
    
}while(scelta!=0);

Link tmp;
if(x==NULL) return 0;
for(x=head ;x->next!=NULL; x=tmp){
    tmp=x->next;
   libera(x);
}


  

	return 0;
}

DATI_S leggi_file(FILE *fp, DATI_S* elenco){


char codice[L],nome[L],cognome[L],nascita[L],v[L],citta[L];

fscanf(fp,"%s %s %s %s %s %s %d",codice,nome,cognome,nascita,v,citta,&elenco->cap) ;

    elenco->cod =strdup(codice);
    elenco->n  =strdup(nome);
    elenco->c  =strdup(cognome);
    elenco->data =strdup(nascita);
    elenco->via  =strdup(v);
    elenco->city =strdup(citta);
    
    
    sscanf(elenco->data,"%d/%d/%d",&elenco->dat_i.g,&elenco->dat_i.m,&elenco->dat_i.a);
  
    return *elenco;
    }

Link crea_lista( Link head,Link *f){
    
FILE *fin;
DATI_S elenco; 
int found;
int R;
Link tail=*f;

 Link x=NULL;
 Link t;
fin=acquisizione(&R);    // sceglie da dove leggere i dati

 

for(int i=0;i<R;i++){
     elenco=leggi_file(fin,&elenco);

      
    if(head==NULL){                      // se lista vuota
    head=crea_nodo(elenco,NULL);
    tail=head;
   
    }
    
   else  if(confronta_date(elenco,tail->val)>0){        //inserimento in coda
    tail->next=crea_nodo(elenco,NULL);
    tail=tail->next;   
  
    }
    
//in testa
    else if(confronta_date(elenco,head->val)<=0){
        head=crea_nodo(elenco,head);
        
    }
    // in mezzo
    else{
        found=0;
        for(x=head;x!=NULL && found==0;  t=x, x=x->next){     
        
           if(confronta_date(elenco,x->val)<=0){
           
                x=crea_nodo(elenco,x);
               t->next=x;
              found=1;
                
            }
            
        }
    }
    
    
}
if(fin!=stdin) {
fclose(fin);

}

*f=tail;
    return head;
}

Link crea_nodo(DATI_S val, Link next){
    
    Link x=(Link)malloc(sizeof(* x));
    if(x==NULL) return NULL;
    else {
     x->val=val;
     x->next=next;
    }
    return x;
}

void libera(Link  nodo){
    
free( nodo->val.cod);
free( nodo->val.n   );
free( nodo->val.c    );
free( nodo->val.data);
free( nodo->val.via );
free( nodo->val.city);
free(nodo);
 
}

void stampa_singolo(Link x){
       printf("%s %s %s %s %s %s %d\n",x->val.cod, x->val.n, x->val.c, x->val.data, x->val.via, x->val.city, x->val.cap) ;
}

void stampa_lista(Link head){
    
    Link x;
    
    printf("STAMPO LISTA\n\n");
    for(x=head;x!=NULL;x=x->next){
        
       stampa_singolo(x);
        
    }
}

int  confronta_date(DATI_S x,DATI_S y){
    

     
                  if(x.dat_i.a>y.dat_i.a){
                      return 1;
                     
                    }
                    else if (x.dat_i.a==y.dat_i.a){
                    
                        if(x.dat_i.m>y.dat_i.m){
                           return 1;
                        }
                        else if (x.dat_i.m==y.dat_i.m){
                    
                            if(x.dat_i.g>y.dat_i.g){
                           return 1;
                            }
                        
                            else if (x.dat_i.g==y.dat_i.g){
                    
                            return 0;
                            }
                                            }
                                        }
                            
       return -1;              

}

FILE * acquisizione(int *R){
    
    FILE *fin;
    char prova[MAXL];
    *R=0;


   
    char scelta[MAXL];
    printf("da dove vuoi acquisire? (nome file/ T se da tastiera)\n");
    scanf("%s",scelta);
    if(*scelta=='T'){
    fin=stdin;
    *R=1;
    printf("INSERIMENTO\ncodice  nome  cognome  data(gg/mm/aaaa)  via  città  cap\n");
    }
    else{
        fin=fopen(scelta,"r");
     while(fgets(prova,MAXL,fin)!=NULL){     //conto righe del file
     (* R)++;
     }
 fclose(fin);
    fin=fopen(scelta,"r");
    }
    assert(fin!=NULL);
    
    return fin;
    
        
  

}

Link ricerca_codice(Link head,Link *prev){
    
        if (head==NULL) return NULL;
    char codice[L];
    printf("codice da ricercare: ");
    scanf("%s",codice);
    Link x;
    Link p;

    for(x=head;x!=NULL;p=x, x=x->next){
        if(strcmp(x->val.cod,codice)==0){
            *prev=p;
            return x;
        }
        
    }
    return NULL;
}

Link cancellazione(Link x, Link *head, Link *tail,Link *prev){
    
    int a;
    stampa_singolo(x);
    printf("vuoi cancellarlo? 1-si, 0-no\n");
    
    
    scanf("%d",&a);
    if(a==0) {
        *prev=x;
        return x;
    }
    
    if(x==*head){
        *head=(*head)->next;
        libera(x);
    }
    else if(x==*tail){
       * tail=*prev;
       (* tail)->next=NULL;
       libera(x);
    }
    else{
    (*prev)->next=x->next;
    libera(x);
    }
    
    return x;
    
    
    
}

void canc_dat(Link *head, Link *tail){
    DATI_S elenco1,elenco2,tmp ;
    Link prev;
    Link x,t;
    char d1[L],d2[L];
    printf("prima data gg/mm/aaaa\n");
    scanf("%s",d1);
    sscanf(d1,"%d/%d/%d",&elenco1.dat_i.g,&elenco1.dat_i.m,&elenco1.dat_i.a);
     printf("seconda data gg/mm/aaaa\n");
    scanf("%s",d2);
    sscanf(d2,"%d/%d/%d",&elenco2.dat_i.g,&elenco2.dat_i.m,&elenco2.dat_i.a);
    
    if(confronta_date(elenco1,elenco2)>0){
        tmp=elenco1;
        elenco1=elenco2;
        elenco2=tmp;
    }
    if (confronta_date(elenco1,elenco2)<=0){
        x=ricerca_data(elenco1,*head,&prev);
        while(x!=NULL &&(confronta_date(x->val,elenco2)<=0)){
            t=x->next;
           x=cancellazione(x,head,tail,&prev);
           
            x=t;
            
        }
        
    }
    
    

}

Link ricerca_data(DATI_S val, Link head,Link*prev){
    
    Link p;
Link x;    
  if (head==NULL) return NULL;
  
    for(x=head;x!=NULL; p=x, x=x->next){
        if(confronta_date(val,x->val)<=0){
            *prev=p;
            return x;
            
        }
        
        
        
    }
    printf("non trovato\n");
    return x;
}