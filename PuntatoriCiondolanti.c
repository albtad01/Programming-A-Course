
#include <stdio.h>
int *p;
void boh(void);
void bohboh(void);

int main() {
    int x = 1;
    p = &x;
    boh();
    bohboh(); // 1
    // SENZA 1 stampa semplicemente 55. Dato che la funzione boh si chiude, 
    // e con essa anche la x relativa a boh, appena *p "vede" una nuova variabile y decide di puntarla.
    // Questo è il fenomeno dei puntatori ciondolanti (o dandling references), tipico di una gestione
    // sbagliata dei puntatori che puntano a zone di memoria deallocate e libere;
    printf("risultato= %d\n", *p);
    return 0;
}
void boh() {
    int x = 55;
    p = &x;
}
void bohboh() {
    int y = 100;
}
