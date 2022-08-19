// ESERCIZI MAXLOC
// sostituire i 5 con 100
#include<stdio.h>
#include<stdlib.h>
typedef struct EL{
    int val;
    int i;
    int j;
    struct EL * next;
}Nodo;
typedef Nodo * Lista;
Lista estraiMassimiLocali(float M[5][5]);
void VisualizzaLista( Lista lista );
int verificaMaxLoc(float MAT[5][5], int i, int j);
Lista InsInTesta( Lista lista, int ii,int jj, int vval );
int main(){
    float M[5][5]=
    {{1.0,0,1.0,2.0,3.0},{5.0,7.0,6.0,2.5,2.3},{55,7.0,8.1,9.01,2.0},{1.1,2.1,3.4,5.7,7.8}};
    Lista l=NULL;
    l=estraiMassimiLocali(M);
    VisualizzaLista(l);
    return 0;
}
Lista estraiMassimiLocali(float M[5][5]){
    Lista l=NULL;
    int i,j;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(verificaMaxLoc(M, i, j))
                l=InsInTesta(l, i, j, M[i][j]);
        }
    }
    return l;
}
void VisualizzaLista( Lista lista ) {
    if ( lista==NULL )
        printf(" ---| \n");
    else {
        printf(" %d [%d][%d] ---> ",lista->val,lista->i,lista->j);
        VisualizzaLista(lista->next);
    }
}
int verificaMaxLoc(float MAT[5][5], int i, int j){
    int check=1;
    // riga sopra
    if(i-1>=0){
        if(j-1>=0)
            if(MAT[i-1][j-1]>MAT[i][j])
                check=0;
        if(MAT[i-1][j]>MAT[i][j])
            check=0;
        if(j+1<5)
            if(MAT[i-1][j+1]>MAT[i][j])
                check=0;
    }
    // riga centrale
    if(j-1>=0)
        if(MAT[i][j-1]>MAT[i][j])
            check=0;
    if(j+1<5)
        if(MAT[i][j+1]>MAT[i][j])
            check=0;
    // riga sotto
    if(i+1<5){
        if(j-1>=0)
            if(MAT[i+1][j-1]>MAT[i][j])
                check=0;
        if(MAT[i+1][j]>MAT[i][j])
            check=0;
        if(j+1<5)
            if(MAT[i+1][j+1]>MAT[i][j])
                check=0;
    }
    return check;
}
Lista InsInTesta( Lista lista, int ii,int jj, int vval ) {
    Lista punt;
    punt = (Lista) malloc(sizeof(Nodo));
    punt->i = ii;
    punt->j = jj;
    punt->val=vval;
    punt->next=lista;
    return  punt;
}

// ESERCIZIO COGNOME PIU DIFFUSO ALBERI

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node_s {
    char nome[100],cognome[100];
    struct node_s * left, *right;
} node_t;
typedef node_t * tree;
typedef struct node_cognome{
    char cognome[100];
    struct node_cognome * next;
} node_c;
typedef node_c * lista;
void cognomeDiffuso(tree T, char str[]);
lista RiempiConValoriAlbero(tree T, lista l);
int main(){
    char cog[100];
    tree T=NULL;
    cognomeDiffuso(T,cog);
    printf("%s\n",cog);
    return 0;
}
void cognomeDiffuso(tree T, char str[]){
    lista head=NULL,scroll=NULL,scrolll=NULL;
    int max=0,cont=0;
    head=RiempiConValoriAlbero(T, head);
    scroll=head;
    scrolll=head;
    while(scrolll!=NULL){
        while(scroll!=NULL){
            if(strcmp(scrolll->cognome,scroll->cognome)==0)
                cont++;
            scroll=scroll->next;
        }
        if(cont>max){
            strcpy(str,scroll->cognome);
            max=cont;
        }
        cont=0;
        scroll=head;
        scrolll=scrolll->next;
    }
}
lista InsInTesta( lista l, char par[100] ) {
    lista punt;
    punt = (lista) malloc(sizeof(node_c));
    strcpy(punt->cognome,par);
    punt->next = l;
    return  punt;
}
lista RiempiConValoriAlbero(tree T, lista l){
    if(T==NULL)
        return l;
    l=InsInTesta(l,T->cognome);
    l=RiempiConValoriAlbero(T->right, l);
    l=RiempiConValoriAlbero(T->left, l);
    return l;
}
