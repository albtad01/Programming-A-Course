#include<stdio.h>
#include<stdlib.h>

typedef struct EL{
        int info;
        struct EL * prox;
} ElemLista;
typedef ElemLista * ListaDiElem;

ListaDiElem InsInTesta( ListaDiElem lista, int elem );
ListaDiElem InsInFondo(ListaDiElem lista, int elem);
ListaDiElem crea1(void);
ListaDiElem crea2(void);
void VisualizzaLista( ListaDiElem lista );
ListaDiElem div3(ListaDiElem l1, ListaDiElem l2);
int PresenzaElemInLista(ListaDiElem l, int num);

int main() {
    ListaDiElem lista=NULL,lista1=NULL,lista2=NULL;
    lista1=crea1();
    lista2=crea2();
    VisualizzaLista(lista1);
    printf("\n\n");
    VisualizzaLista(lista2);
    printf("\n\n");
    lista=div3(lista1,lista2);

    VisualizzaLista(lista);
    printf("\n\n");
    return 0;
}

void VisualizzaLista( ListaDiElem lista ) {
    if ( lista==NULL )
        printf(" ---| \n");
    else {
        printf(" %d ---> ",lista->info);
        VisualizzaLista(lista->prox);
    }
}

ListaDiElem InsInTesta( ListaDiElem lista, int elem ) {
    ListaDiElem punt;
    punt = (ListaDiElem) malloc(sizeof(ElemLista));
    punt->info = elem;
    punt->prox = lista;
    return  punt;
}
ListaDiElem InsInFondo(ListaDiElem lista, int elem){
    ListaDiElem head=lista,prec=NULL;
    while(lista!=NULL){
        prec=lista;
        lista=lista->prox;
    }
    lista=(ListaDiElem)malloc(sizeof(ElemLista));
    lista->info=elem;
    lista->prox=NULL;
    prec->prox=lista;
    return head;
}
ListaDiElem crea1() {
    ListaDiElem lis=NULL;
    lis=InsInTesta( lis, 2 );
    lis=InsInTesta( lis, 12 );
    lis=InsInTesta( lis, 1 );
    lis=InsInTesta( lis, 4 );
    lis=InsInTesta( lis, 8 );
    lis=InsInTesta( lis, 34 );
    lis=InsInTesta( lis, 78 );
    lis=InsInTesta( lis, 26 );
    lis=InsInTesta( lis, 33 );
    lis=InsInTesta( lis, 11 );
    lis=InsInTesta( lis, 67 );
    lis=InsInTesta( lis, 83 );
    lis=InsInFondo( lis, 92 );
    return lis;
}

ListaDiElem crea2() {
    ListaDiElem lis=NULL;
    lis=InsInTesta( lis, 2 );
    lis=InsInTesta( lis, 10 );
    lis=InsInTesta( lis, 15 );
    lis=InsInTesta( lis, 48 );
    lis=InsInTesta( lis, 82 );
    lis=InsInTesta( lis, 11 );
    lis=InsInTesta( lis, 92 );
    lis=InsInTesta( lis, 22 );
    lis=InsInTesta( lis, 36 );
    lis=InsInTesta( lis, 19 );
    lis=InsInTesta( lis, 69 );
    return lis;
}
int PresenzaElemInLista(ListaDiElem l, int num){
    if(l==NULL)
        return 0;
    if(l->info==num)
        return 1;
    return PresenzaElemInLista(l->prox, num);
}
ListaDiElem div3(ListaDiElem l1, ListaDiElem l2){
    ListaDiElem l=NULL;
    while(l1!=NULL){
        if(l1->info%3==0 && PresenzaElemInLista(l, l1->info)==0)
            l=InsInTesta(l, l1->info);
        l1=l1->prox;
    }
    while(l2!=NULL){
        if(l2->info%3==0 && PresenzaElemInLista(l, l2->info)==0)
            l=InsInTesta(l, l2->info);
        l2=l2->prox;
    }
    return l;
}
