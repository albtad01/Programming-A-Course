
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 3

void riempiMatrice(int A[N][N]);
void stampaMatrice(int A[N][N]);
void analizzaMatrice(int A[N][N]);
int massimoRiga(int A[N][N],int, int);
int massimoColonna(int A[N][N], int, int);
int massimoDiagonali(int D[N][N], int, int);

int main(int argc, const char * argv[]) {
    int A[N][N];
    riempiMatrice(A);
    stampaMatrice(A);
    analizzaMatrice(A);
    return 0;
}
void analizzaMatrice(int A[N][N]){
    int i,j;
    printf("Elementi Massimo Riga, Colonna e Diagonale:\n");
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(massimoRiga(A,i,j) == 1 && massimoColonna(A,i,j) == 1 && massimoDiagonali(A,i,j) == 1)
                printf("%d\n",A[i][j]);
        }
    }
}
int massimoRiga(int A[N][N],int in, int jn){
    int j;
    for(j=0;j<N;j++)
        if(A[in][jn]<A[in][j]) return 0;
    return 1;
}
int massimoColonna(int A[N][N], int in, int jn){
    int i;
    for(i=0;i<N;i++)
        if(A[in][jn]<A[i][jn]) return 0;
    return 1;
}
int massimoDiagonali(int D[N][N], int i, int j){
    int ii;
    for(ii=1;ii<N;ii++){
        if(i-ii>=0 && j-ii>=0) //alto sinistra
            if(D[i][j]<D[i-ii][j-ii]) return 0;
        if(i-ii>=0 && j+ii<N) // alto destra
            if(D[i][j]<D[i-ii][j+ii]) return 0;
        if(i+ii<N && j-ii>=0) // basso sinistra
            if(D[i][j]<D[i+ii][j-ii]) return 0;
        if(i+ii<N && j+ii<N) // basso destra
            if(D[i][j]<D[i+ii][j+ii]) return 0;
    }
    return 1;
}
void riempiMatrice(int A[N][N]){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("A[%d][%d]: ",i,j);
            scanf("%d",&A[i][j]);
        }
    }
}
void stampaMatrice(int A[N][N]){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++)
            printf("%d\t",A[i][j]);
        printf("\n");
    }
}
