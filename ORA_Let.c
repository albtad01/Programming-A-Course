// Definire due tipi di dato atti a descrivere atleti olimpici e gare olimpiche.
// Un atleta olimpico è caratterizzato da nome, nazione, e disciplina. Una gara olimpica è caratterizzata da specialità, disciplina, e da un lista di atleti partecipanti ordinati in base alla classifica (dal primo all’ultimo).
// (Si assuma che ogni gara olimpica abbia almeno 3 partecipanti)
// Scrivere una funzione che, data una lista di gare (nuovo tipo di dato da definire), una nazione, e un tipo di medaglia (oro, argento o bronzo), conta il numero di medaglie di quel tipo vinte da atleti di quella nazione.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    char nome[20];
    char nazione[20];
    char disciplina[20];
}AtletaOli;
typedef struct ElAtlLis{
    AtletaOli atl;
    struct ElAtlLis * next;
}NodoAtlOli;
typedef NodoAtlOli * ListaOli;
typedef struct ElGarOl{
    char specialita[20];
    char disciplina[20];
    ListaOli ListAtl;
}GaraOlimpica;
typedef struct ElGareLis{
    GaraOlimpica gar;
    struct ElGareLis * next;
}NodoGareOli;
typedef NodoGareOli * LisGareOli;
/// Ai fini del problema era necessaria soltanto la funzione Individua, io ho creato dei nodi apposta per testarlo

LisGareOli Riempi(LisGareOli l);
LisGareOli InsInFondoSpecialità(LisGareOli l, char disc[20]);
ListaOli InsInFondoAtleta(ListaOli gar, char nome[20], char nazione[20]);
void StampaLista(LisGareOli l);
int Individua(LisGareOli lis, char naz[20], char med[20]);
double mediaInglesi(LisGareOli g);
int main(){
    LisGareOli l=NULL;
    double checkd=0;
    l=Riempi(l);
    StampaLista(l);
    checkd=mediaInglesi(l);
    printf("Inglesi media: %lf\n",checkd);
    return 0;
}
LisGareOli Riempi(LisGareOli l){

    l=InsInFondoSpecialità(l, "atletica");
    l=InsInFondoSpecialità(l, "salto");
    l=InsInFondoSpecialità(l, "calcio");
    l->gar.ListAtl=NULL; l->next->gar.ListAtl=NULL; l->next->next->gar.ListAtl=NULL;
    l->gar.ListAtl=InsInFondoAtleta(l->gar.ListAtl, "jacobs", "italia");
    l->gar.ListAtl=InsInFondoAtleta(l->gar.ListAtl, "alby", "italia");
    l->gar.ListAtl=InsInFondoAtleta(l->gar.ListAtl, "itscominghome", "inghilterra");
    l->next->gar.ListAtl=InsInFondoAtleta(l->next->gar.ListAtl, "tizio", "inghilterra");
    l->next->gar.ListAtl=InsInFondoAtleta(l->next->gar.ListAtl, "berettini", "italia");
    l->next->next->gar.ListAtl=InsInFondoAtleta(l->next->next->gar.ListAtl, "jorginho", "italia");
    l->next->next->gar.ListAtl=InsInFondoAtleta(l->next->next->gar.ListAtl, "lukaku", "belgio");
    l->next->next->gar.ListAtl=InsInFondoAtleta(l->next->next->gar.ListAtl, "rashford", "inghilterra");
    return l;
}
ListaOli InsInFondoAtleta(ListaOli latl, char nome[20],char nazione[20]){
    ListaOli head=latl,prec=NULL;
    while(latl!=NULL){
        prec=latl;
        latl=latl->next;
    }
    latl=(ListaOli)malloc(sizeof(NodoAtlOli));
    strcpy(latl->atl.nazione,nazione);
    strcpy(latl->atl.nome, nome);
    latl->next=NULL;
    if(prec!=NULL){
        prec->next=latl;
        return head;
    }
    else
        return latl;
}
LisGareOli InsInFondoSpecialità(LisGareOli l, char disc[20]){
    LisGareOli head=l,prec=NULL;
    while(l!=NULL){
        prec=l;
        l=l->next;
    }
    l=(LisGareOli)malloc(sizeof(NodoGareOli));
    strcpy(l->gar.disciplina,disc);
    l->next=NULL;
    if(prec!=NULL){
        prec->next=l;
        return head;
    }
    else
        return l;
}

int Individua(LisGareOli lis, char naz[20], char med[20]){
    int cont=0,pos=1;
    while(lis!=NULL){
        while(lis->gar.ListAtl!=NULL){
            if(strcmp(lis->gar.ListAtl->atl.nazione,naz)==0){
                if(strcmp("bronzo",med)==0 && pos==3)
                    cont++;
                if(strcmp("argento",med)==0 && pos==2)
                    cont++;
                if(strcmp("oro",med)==0 && pos==1)
                    cont++;
            }
            pos++;
            lis->gar.ListAtl=lis->gar.ListAtl->next;
        }
        pos=1;
        lis=lis->next;
    }
    return cont;
}

void StampaLista(LisGareOli l){
    int pos=1;
    LisGareOli scroll=l;
    while(scroll!=NULL){
        printf("Classifica %s:\n",scroll->gar.disciplina);
        ListaOli scroll2=scroll->gar.ListAtl;
        while(scroll2!=NULL){
            printf("%d) %s\n",pos,scroll2->atl.nome);
            pos++;
            scroll2=scroll2->next;
        }
        pos=1;
        printf("\n");
        scroll=scroll->next;
    }

}
// fondamentale fare lo scroll con una variabile ausiliaria, altrimenti il puntatore alla fine
// punterà a NULL in entrambe le liste (quella principale e la sottolista).

// 3) Media posizioni inglesi, ammesso che non sia il calcio
double mediaInglesi(LisGareOli g){
    int pos=1,numInglesi=0;
    double sum=0;
    while(g!=NULL){
        if(strcmp(g->gar.disciplina,"calcio")!=0){
            while(g->gar.ListAtl!=NULL){
                if(strcmp(g->gar.ListAtl->atl.nazione,"inghilterra")==0){
                    sum+=pos;
                    numInglesi++;
                }
                pos++;
                g->gar.ListAtl=g->gar.ListAtl->next;
            }
        }
        pos=1;
        g=g->next;
    }
    return sum/numInglesi;
}
