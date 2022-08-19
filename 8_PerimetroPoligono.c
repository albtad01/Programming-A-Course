#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//Dato un punto nel piano cartesiano, individuato dalle coordinate intere x, y e da una lettera (ad esempio, A(5,2)), si chiede di definire un'opportuna struttura dati ed il relativo tipo punto_t che lo rappresenti. Si chiede poi di definire una nuova struttura dati che permetta di rappresentare un poligono come una lista di punti. Scrivere quindi un programma, che facendo uso della rappresentazione di poligono introdotta: 1) acquisisca i vertici di un poligono, 2) calcoli il perimetro del poligono, 3) stampi a video il valore del perimetro calcolato.
typedef struct{
    char let;
    int x;
    int y;
}punto_t;

typedef struct punto_pol{
    punto_t p;
    struct punto_pol * next;
}poligono;
typedef poligono * ptrPol;

ptrPol InsInTestaPunto(ptrPol p, int x, int y, int c);
void VisualizzaLista( ptrPol pol );
ptrPol AcquisisciVertici(void);
double Perimetro (ptrPol pol);
double distanzaPunti(int x1,int x2,int y1,int y2);
void Stampa (double);

int main(int argc, const char * argv[]) {
    ptrPol pol=NULL;
    double per;
    pol=AcquisisciVertici();
    VisualizzaLista(pol);
    per=Perimetro(pol);
    Stampa(per);
    return 0;
}
ptrPol InsInTestaPunto(ptrPol p, int x, int y, int c){
    ptrPol n;
    n=(ptrPol)malloc(sizeof(poligono));
    n->p.let=c;
    n->p.x=x;
    n->p.y=y;
    n->next=p;
    return n;
}
ptrPol AcquisisciVertici(void){
    int ver=0,i,tempx,tempy;
    char tempc;
    ptrPol poligono=NULL;
    do{
        printf("Num Vertici: ");
        scanf("%d",&ver);
    }while(ver<3);
    for(i=0;i<ver;i++){
        printf("NomeVertice%d: ",i+1);
        scanf(" %c",&tempc);
        printf("Xver%d: ",i+1);
        scanf("%d",&tempx);
        printf("Yver%d: ",i+1);
        scanf("%d",&tempy);
        poligono=InsInTestaPunto(poligono,tempx,tempy,tempc);
    }
    return poligono;
}
void VisualizzaLista( ptrPol pol ) {
    if ( pol==NULL )
        printf(" ---| \n");
    else {
        printf("%c(%d;%d) ---> ",pol->p.let,pol->p.x,pol->p.y);
        VisualizzaLista(pol->next);
    }
}
double Perimetro (ptrPol pol){
    ptrPol primoPunto=pol;
    double perimetro=0;
    while(pol!=NULL){
        if(pol->next!=NULL)
            perimetro+=distanzaPunti(pol->p.x,pol->next->p.x,pol->p.y,pol->next->p.y);
        else
            perimetro+=distanzaPunti(pol->p.x,primoPunto->p.x,pol->p.y,primoPunto->p.y);
        //printf("%lf\n",perimetro);
        pol=pol->next;
    }
    return perimetro;
}
double distanzaPunti(int x1,int x2,int y1,int y2){
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}
void Stampa (double p){
    printf("Perimetro Poligono: %lf\n",p);
}
