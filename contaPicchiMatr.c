#include<stdio.h>
#define N 4
#define M 3
int contaPicchi(float MAT[N][M]);
int main(){
    float MAT[N][M]={{1,0,3},{0,0,0},{4,1,2},{3,2,5}};
    int cont;
    cont=contaPicchi(MAT);
    printf("%d\n",cont);
    return 0;
}
int contaPicchi(float MAT[N][M]){
    int i,j,check=1, c=0;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            // riga sopra
            if(i-1>=0){
                if(j-1>=0)
                    if(MAT[i-1][j-1]>MAT[i][j]/2)
                        check=0;
                if(MAT[i-1][j]>MAT[i][j]/2)
                    check=0;
                if(j+1<M)
                    if(MAT[i-1][j+1]>MAT[i][j]/2)
                        check=0;
            }
            // riga centrale
            if(j-1>=0)
                if(MAT[i][j-1]>MAT[i][j]/2)
                    check=0;
            if(j+1<M)
                if(MAT[i][j+1]>MAT[i][j]/2)
                    check=0;
            // riga sotto
            if(i+1<N){
                if(j-1>=0)
                    if(MAT[i+1][j-1]>MAT[i][j]/2)
                        check=0;
                if(MAT[i+1][j]>MAT[i][j]/2)
                    check=0;
                if(j+1<M)
                    if(MAT[i+1][j+1]>MAT[i][j]/2)
                        check=0;
            }
            if(check==1) c++;
            check=1;
        }
    }
    return c;
}
