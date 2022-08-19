//soluzione matrice classica

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main(int argc, const char * argv[]) {
    int MAT[3][3],i,j,elem=0,sum=0;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("M[%d][%d]: ",i,j);
            scanf("%d",&MAT[i][j]);
        }
    }
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(MAT[i][j]%3==0 && MAT[i][j]!=0){
                sum+=MAT[i][j];
                elem++;
            }
        }
    }
    printf("Media dei Divisibili per 3: %5.2f \n", (float)sum/elem);
    return 0;
}

// soluzione dualità matrice-puntatore


#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main(int argc, const char * argv[]) {
    int MAT[3][3],i,j,elem=0,sum=0;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("M[%d][%d]: ",i,j);
            scanf("%d",&(*(*(MAT+i)+j))); // o scanf("%d",*(MAT+i)+j)
        }
    }
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(*(*(MAT+i)+j)%3==0 && *(*(MAT+i)+j)!=0){
                sum+=*(*(MAT+i)+j);
                elem++;
            }
        }
    }
    printf("Media dei Divisibili per 3: %5.2f \n", (float)sum/elem);
    return 0;
}
