#include<stdio.h>
#include<stdlib.h>
typedef struct El{
    int info;
    struct El * next;

}ElemLista;
typedef ElemLista * Lista;
int listePerDue(Lista l){
    if(l==NULL || l->next==NULL)
        return 1;
    if(l->next->info>=2*l->info)
        return listePerDue(l->next);
    return 0;
}
int correggiLista(Lista *l);
Lista InsInTesta( Lista lista, int elem );
Lista crea1(void);
Lista crea2(void);
void VisualizzaLista( Lista lista );

int main() {
    Lista lista1=NULL,lista2=NULL;
    int check=0;
    lista1=crea1();
    lista2=crea2();
    VisualizzaLista(lista1);
    printf("\n\n");
    VisualizzaLista(lista2);
    printf("\n\n");
    if(listePerDue(lista2)==0){
        check=correggiLista(&lista2);
    }
    printf("Incrementi eventuali su lista2: %d \n",check);
    VisualizzaLista(lista2);

    printf("\n\n");
    return 0;
}
void VisualizzaLista( Lista lista ) {
    if ( lista==NULL )
        printf(" ---| \n");
    else {
        printf(" %d ---> ",lista->info);
        VisualizzaLista(lista->next);
    }
}

Lista InsInTesta( Lista lista, int elem ) {
    Lista punt;
    punt = (Lista) malloc(sizeof(ElemLista));
    punt->info = elem;
    punt->next = lista;
    return  punt;
}

Lista crea1() {
    Lista lis=NULL;
    lis=InsInTesta( lis, 8 );
    lis=InsInTesta( lis, 4 );
    lis=InsInTesta( lis, 2 );
    lis=InsInTesta( lis, 0 );

    return lis;
}

Lista crea2() {
    Lista lis=NULL;
    lis=InsInTesta( lis, 7 );
    lis=InsInTesta( lis, 3 );
    lis=InsInTesta( lis, 2 );
    return lis;
}
int correggiLista(Lista *lista){ // passo l'indirizzo così modifico la lista direttamente (col puntatore al valore dell'indirizzo puntato
    int cont=0;
    Lista l=*lista;
    // copio l'indirizzo della lista così la testa rimane intatta e modifico la lista pur rimanendo il punt alla lista
    while(l!=NULL && (l)->next!=NULL){
        if((l)->next->info<2*(l)->info){
            cont+=(2*(l)->info-(l)->next->info);
            (l)->next->info=2*(l)->info;
        }
        (l)=(l)->next;
    }
    return cont;
}
