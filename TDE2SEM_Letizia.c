// ! ESERCIZIO 1

#include<stdio.h>
int analizzaMatrice(int M[10][10],int k);
int main(){
    int M[10][10] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0, 7, 7, 7, 7, 0},
    {0, 1, 1, 9, 0, 7, 7, 7, 7, 0},
    {0, 1, 9, 1, 0, 7, 7, 7, 7, 0},
    {0, 0, 2, 2, 2, 7, 7, 7, 7, 0},
    {0, 0, 2, 2, 2, 0, 0, 0, 0, 0},
    {0, 0, 2, 2, 2, 0, 0, 0, 4, 0},
    {0, 0, 6, 2, 2, 0, 1, 0, 0, 0},
    {0, 0, 5, 7, 8, 0, 0, 2, 0, 0},
    {0, 0, 2, 5, 2, 0, 0, 0, 3, 0},
    };
    int k=5,check;
    //TODO: invocare la funzione
    check=analizzaMatrice(M, k);
    //TODO: stampare i messaggi come da esempi
    printf("check= %d\n", check);
    return 0;
}
int analizzaMatrice(int M[10][10],int k){
    int i,j,ii,jj,prev=0;
    for(i=0;(i+k)<=10;i++){
        for(j=0;(j+k)<=10;j++){
            for(ii=0;ii<k;ii++){
                for(jj=0;jj<k;jj++){
                    if(ii==0 && jj==0) prev=M[ii+i][jj+j];
                    if(M[ii+i][jj+j]!=prev) break;
                    if(ii+1==k && jj+1==k) return 1;
                }
            }
        }
    }
    return 0;
}

// ! ESERCIZIO 2

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int valore;
    struct nodo* next;
} nodo;
typedef nodo* lista;

lista InsInFondo(lista lis, int elem);
void VisualizzaLista(lista lis);
lista costruisci(void);
lista listapicchi(lista lis);

int main(){
    lista lis = costruisci(), picchiarello=NULL;
    // TODO: visualizzazione lista input
    VisualizzaLista(lis);
    // TODO: invocazione funzione
    picchiarello=listapicchi(lis);
    // TODO: visualizzazione lista output
    VisualizzaLista(picchiarello);
    return 0;
}

lista InsInFondo(lista lis, int elem) {
    lista punt;
    if(lis == NULL){
        punt = malloc(sizeof(nodo));
        punt->next = NULL;
        punt->valore = elem;
        return punt;
    }
    else {
        lis->next = InsInFondo(lis->next, elem);
        return lis;
    }
}

void VisualizzaLista( lista lis ) {
    if ( lis == NULL )
    printf(" ---| \n");
    else {
        printf(" %d ---> ", lis->valore);
        VisualizzaLista( lis->next );
    }
}

lista costruisci(){
    // 1 -> 5 -> 16 -> 11 -> 12 -> 4 -> 5 -> 5 -> 3 -> 1 -> 5
    lista lis = NULL;
    lis = InsInFondo(lis, 1);
    lis = InsInFondo(lis, 5);
    lis = InsInFondo(lis, 16);
    lis = InsInFondo(lis, 11);
    lis = InsInFondo(lis, 12);
    lis = InsInFondo(lis, 4);
    lis = InsInFondo(lis, 5);
    lis = InsInFondo(lis, 5);
    lis = InsInFondo(lis, 3);
    lis = InsInFondo(lis, 1);
    lis = InsInFondo(lis, 5);

    return lis;
}
lista listapicchi(lista lis){
    lista prec=NULL,picchio=NULL;
    while(lis!=NULL){
        if(prec!=NULL && lis->next!=NULL){
            if(prec->valore < lis->valore && lis->valore>lis->next->valore)
                picchio=InsInFondo(picchio, lis->valore);
            }
        prec=lis;
        lis=lis->next;
    }
    return picchio;
}

// ESERCIZIO 3

#include <stdio.h>
#include <stdlib.h>

typedef struct n {
    int val;
    struct n * left;
    struct n * right;
} nodo;
typedef nodo * albero;

albero createVal(int val);
albero creaAlbero1(void);
albero creaAlbero2(void);
albero creaAlbero3(void);
void print(albero t);
void stampa(albero T);
int valoriInComune(albero T1, albero T2);
int main(){
    int ris=0;
    albero T1,T2,T3;
    T1 = creaAlbero1(); T2 = creaAlbero2(); T3 = creaAlbero3();
    printf("\nT1: ");
    stampa(T1);
    printf("\nT2: ");
    stampa(T2);
    printf("\nT3: ");
    stampa(T3);

    //LA FUNZIONE valoriInComune VIENE INVOCATA QUI
    ris=valoriInComune(T3,T1);
    //VIENE STAMPATO IL RISULTATO DELLE INVOCAZIONI PER RESTITUIRE COME DA ESEMPIO
    printf("\n*%d*\n",ris);
    return 0;
}

//
// TODO: SVILUPPARE QUI valoriInComune
//

albero creaAlbero1() {
    albero tmp = createVal(7);
    tmp->left = createVal(3);
    tmp->left->left = createVal(9);
    tmp->left->right = createVal(10);
    tmp->right = createVal(8);
    tmp->right->left = createVal(5);
    tmp->right->right = createVal(12);
    tmp->right->right->left = createVal(11);
    tmp->right->right->right = createVal(6);
    return tmp;
}

albero creaAlbero2() {
    albero tmp = createVal(7);
    tmp->right = createVal(3);
    tmp->right->right = createVal(9);
    tmp->right->left = createVal(10);
    tmp->left = createVal(1);
    tmp->left->right = createVal(5);
    tmp->left->left = createVal(12);
    tmp->left->left->right = createVal(11);
    tmp->left->left->left = createVal(6);
    return tmp;
}

albero creaAlbero3() {
    albero tmp = createVal(7);
    tmp->right = createVal(3);
    tmp->right->right = createVal(9);
    tmp->right->left = createVal(10);
    tmp->left = createVal(4);
    tmp->left->right = createVal(5);
    tmp->left->left = createVal(12);
    tmp->left->left->right = createVal(2);
    tmp->left->left->left = createVal(6);
    return tmp;
}

void print(albero t){
    if(t==NULL)return;
    else{printf(" (");print(t->left);printf(" %d ",t->val);print(t->right);printf(") ");}
}

void stampa(albero T){print(T);printf("\n");}

albero createVal(int val) {
    albero tmp = malloc(sizeof(nodo));
    tmp->val = val; tmp->left = NULL; tmp->right = NULL;
    return tmp;
}
int valoriInComune(albero T1, albero T2){
    if(T1==NULL || T2==NULL)
        return 0;
    if(T1->val==T2->val)
        return 1+valoriInComune(T1->right, T2->left)+valoriInComune(T1->left, T2->right);
    return valoriInComune(T1->right, T2->left)+valoriInComune(T1->left, T2->right);
}


// ! ORALE

Definire due tipi di dato atti a descrivere atleti olimpici e gare olimpiche.
Un atleta olimpico è caratterizzato da nome, nazione, e disciplina.
Una gara olimpica è caratterizzata da specialità, disciplina, e da un lista di atleti partecipanti
ordinati in base alla classifica (dal primo all’ultimo).
Si assuma che ogni gara olimpica abbia almeno 3 partecipanti.
Scrivere una funzione che, data una lista di gare (nuovo tipo di dato da definire), una nazione,
e un tipo di medaglia (oro, argento o bronzo), conta il numero di medaglie di quel tipo vinte
da atleti di quella nazione.

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
typedef struct{
  char nome[100];
  char nazione[100];
  char disciplina[100];
}Atleta;
typedef struct EL{
  Atleta a;
  struct EL * prox;
}NodoLisAtleti;
typedef NodoLisAtleti * LisAtleti;
typedef struct{
  char specialita[100];
  char disciplina[100];
  LisAtleti atl;
}GaraOlimpica;
typedef struct ElGara{
  GaraOlimpica g;
  struct ElGara * prox;
}NodoLisGara;
typedef NodoLisGara * LisGara;

int MedaglieVinteNazione(LisGara lis, char naz[100], char med[100]){
    int i=0,pos=1;
    while(lis!=NULL){
        while(lis->g.atl!=NULL){
            if(pos==1 && strcmp(med,"oro")==0 && strcmp(lis->g.atl->a.nazione,naz)==0)
                i++;
            if(pos==2 && strcmp(med,"argento")==0 && strcmp(lis->g.atl->a.nazione,naz)==0)
                i++;
            if(pos==3 && strcmp(med,"bronzo")==0 && strcmp(lis->g.atl->a.nazione,naz)==0)
                i++;
            pos++;
            lis->g.atl=lis->g.atl->prox;
        }
        lis=lis->prox;
    }
    return i;
}
