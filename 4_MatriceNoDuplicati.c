
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 3
#define M 4
int main(int argc, const char * argv[]) {
    int MAT[N][M],i,j,ii,jj,duplicato;
    printf("WARNING: NO DUPLICATI!\n");
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            do{
                duplicato=0;
                printf("MAT[%d][%d]: ",i,j);
                scanf("%d",&MAT[i][j]);
                for(ii=0;ii<=i;ii++)
                    for(jj=0;jj<j;jj++)
                        if(MAT[ii][jj]==MAT[i][j]) duplicato=1;
            }while(duplicato==1);
        }
    }
    printf("Risultato NO DUPLICATI:\n");
    for(i=0;i<N;i++){
            for(j=0;j<M;j++)
            printf("%d\t", MAT[i][j]);
            printf("\n");
    }
    return 0;
}
