
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    int M[3][3],i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("M[%d][%d]: ",i,j);
            scanf("%d",&M[i][j]);
        }
    }
    for(i=0;i<3;i++){
        for(j=0;j<3;j++)
            printf("%d\t", M[i][j]);
        printf("\n");
    }
    printf("Matrice triangolare simmetrica:\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(i>j) M[i][j]=0;
            if(j>i) M[i][j]+=M[j][i];
        }
    }
    for(i=0;i<3;i++){
        for(j=0;j<3;j++)
            printf("%d\t", M[i][j]);
        printf("\n");
    }
    return 0;
}
