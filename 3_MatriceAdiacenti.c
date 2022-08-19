
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    int M[3][3]={{1,2,3},{4,4,6},{7,8,9}},RIS[3][3],i,j,sum=0;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            sum=M[i][j];
            if((i-1)>=0) sum+=M[i-1][j];
            if((i+1)<3) sum+=M[i+1][j];
            if((j-1)>=0) sum+=M[i][j-1];
            if((j+1)<3) sum+=M[i][j+1];
            if((i-1)>=0 && (j-1)>=0) sum+=M[i-1][j-1];
            if((i-1)>=0 && (j+1)<3) sum+=M[i-1][j+1];
            if((i+1)<3 && (j-1)>=0) sum+=M[i+1][j-1];
            if((i+1)<3 && (j+1)<3) sum+=M[i+1][j+1];
            RIS[i][j]=sum;
        }
    }
    for(i=0;i<3;i++){
        for(j=0;j<3;j++)
            printf("%d ",RIS[i][j]);
        printf("\n");
    }
    return 0;
}
