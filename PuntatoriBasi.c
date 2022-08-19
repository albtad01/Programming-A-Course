#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main(int argc, const char * argv[]) {
    int *punt,count;
    count=3;
    // associamo a punt l'indirizzo di memoria di count (sovrascrive i dati dentro count)
    punt=&count;
    // se cambiamo quindi il valore di punt cambieremo anche il valore di count
    *punt=4;
    printf("Indirizzo punt: %p \nIndirizzo count: %p \n Valore punt: %d \n Valore count: %d \n",punt,&count,*punt,count);
    //output: entrambi 4 cvd
    return 0;
}
/* RECAP PUNTATORI E CHIAMATE FUNZIONI

 -PER IL PASSAGGIO PER RIFERIMENTO
 Devo sempre associare ad un puntatore un indirizzo a cui punta;
 Alla funzione passo L'INDIRIZZO del puntatore (& o nome).
 Così il puntatore punta alla sua area di memoria e lo modifica direttamente.

 -PER IL PASSAGGIO PER VALORE
 La funziona copia il valore in input per svolgere dei procedimenti
 e restituire UN ALTRO valore, che andrà nel return.
 Avrò bisogno un valore nel chiamante a cui associare la variabile di
 output omogenea. Passo quindi la stessa identica variabile, non l'indirizzo.

 */
