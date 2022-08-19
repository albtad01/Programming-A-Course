
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct el{
    int info;
    struct el * next;
}nodo;
typedef nodo * ptrLista;

ptrLista InsInTesta(ptrLista l, int num);
void StampaLista(ptrLista l);
int SommaElem(ptrLista l);

int main(int argc, const char * argv[]) {
    ptrLista l=NULL;
    int s;
    l=InsInTesta(l,2);
    l=InsInTesta(l,4);
    l=InsInTesta(l,24);
    StampaLista(l);
    s=SommaElem(l);
    printf("Somma Elementi Lista: %d\n",s);
    return 0;
}
ptrLista InsInTesta(ptrLista l, int num){
    ptrLista n;
    n=(ptrLista) malloc(sizeof(nodo));
    n->info=num;
    n->next=l;
    return n;
}
void StampaLista( ptrLista lista ) {
    if ( lista==NULL )
        printf(" ---| \n");
    else {
        printf(" %d ---> ",lista->info);
        StampaLista(lista->next);
    }
}

int SommaElem(ptrLista l){
    if(l==NULL)
        return 0;
    return l->info+SommaElem(l->next);
}
