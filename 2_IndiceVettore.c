#include <stdio.h>
#include <stdlib.h>
#define N 10
int main(int argc, const char * argv[]) {
    int v[N],X,i,sum=0,pro=1;
    for(i=0;i<N;i++){
        printf("v[%d]: ",i);
        scanf("%d",&v[i]);
    }
    do{
        printf("Indice X: ");
        scanf("%d",&X);
    }while(X<0 || X>9);
    for(i=0;i<N;i++){
        if(i<X) sum+=v[i];
        if(i>X) pro*=v[i];
    }
    printf("Somma 0-%d: %d\n",X-1,sum);
    printf("Prodotto %d-9: %d\n",X+1,pro);
    return 0;
}
