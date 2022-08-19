#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Definire un tipo di dato Carta che descrive una carta in un mazzo. Ogni carta è caratterizzata da una stringa del seme, una stringa che descrive il numero sulla carta (o la figura) e un numero che descrive l’ordinamento delle carte dello stesso seme (ad esempio “7” corrisponde a 7, mentre “jack” corrisponde a 8).
// Definire un tipo di dato Mazzo che descrive una lista di carte che sono in mano ad un giocatore durante una giocata.
// 2 Scala: la funzione verifica se è presente una scala (dello stesso colore), che copre l’intero mazzo.

typedef struct{
    char seme[20];
    char numero[20];
    int numeroCorrisp;
}Carta;
typedef struct ElMazzo{
    Carta car;
    struct ElMazzo * next;
}Mazzo;
typedef Mazzo * LisMazzo;

int TrovaMinore(LisMazzo maz, char semeMin[20]){
    LisMazzo scroll=maz;
    int min=10;
    while(scroll!=NULL){
        if(scroll->car.numeroCorrisp<min){
            min=scroll->car.numeroCorrisp;
            strcpy(semeMin,scroll->car.seme);
        }
        scroll=scroll->next;
    }
    return min;
}
int lunghezzaMazzo(LisMazzo maz){
    LisMazzo scroll=maz;
    int i=0;
    while(scroll!=NULL){
        i++;
        scroll=scroll->next;
    }
    return i;
}
int verificaScala(LisMazzo maz){
    int check=0;
    char semeMin[20];
    int min=TrovaMinore(maz,semeMin);
    LisMazzo aux1=maz,aux2=maz;
    while(aux1!=NULL){
        aux2=maz;
        while(aux2!=NULL && check!=1){
            if(aux2->car.numeroCorrisp==min+1 && strcmp(semeMin,aux2->car.seme)==0){
                min=aux2->car.numeroCorrisp;
                check++;
            }
            aux2=aux2->next;
        }
        aux1=aux1->next;
    }
    if(check==lunghezzaMazzo(maz))
        return 1;
    return 0;
}
