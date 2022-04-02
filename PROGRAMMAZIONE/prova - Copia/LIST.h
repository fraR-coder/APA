#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

typedef struct list* LIST;

LIST        list_init(void);
void        list_free(LIST l);
void        list_insHeadP(LIST l,int val);
void        list_print(LIST l);

void        purge(LIST l,int div);

#endif