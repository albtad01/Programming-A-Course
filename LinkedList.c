#include<stdio.h>
#include<stdlib.h>

typedef struct EL{
        int info;
        struct EL * prox;
} ElemLista;
typedef ElemLista * ListaDiElem;

int ListaVuota( ListaDiElem lista );
ListaDiElem InsInTesta( ListaDiElem lista, int elem );
ListaDiElem crea1();
ListaDiElem crea2();
void VisualizzaLista( ListaDiElem lista );

int main() {
    ListaDiElem lista=NULL,lista1=NULL,lista2=NULL;     
    lista1=crea1();
    lista2=crea2();
    VisualizzaLista(lista1);
    printf("\n\n");
    VisualizzaLista(lista2);
    printf("\n\n");
    
    //inserire qui il codice
    
    VisualizzaLista(lista);
    printf("\n\n");
    
    getch();
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
ListaDiElem InsInFondo( ListaDiElem lista, int elem ){
    ListaDiElem punt;
    if(lista==NULL){
        punt=malloc(sizeof(ElemLista));
        punt->prox=NULL;
        punt->info=elem;
        return punt;
    }
    else{
        lista->prox=InsInFondo(lista->prox,elem);
        return lista;
    }
}

int ListaVuota( ListaDiElem lista ) {
    return lista == NULL;
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
    lis=InsInTesta( lis, 92 );
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
