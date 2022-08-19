#include <stdio.h>
#include <stdlib.h>
#define N 500
int main(int argc, const char * argv[]) {
    int num, div[N],i,j=0,flag=0;
    do{
        printf("Numero da Scomporre: ");
        scanf("%d",&num);
    }while(num<=0);
    do{
        for(i=2;flag==0;i++){
            if(num%i==0){
                div[j]=i;
                j++;
                num/=i;
                flag=1;
            }
        }
        flag=0;
    }while(num!=1);
    for(i=0;i<j;i++){
        if(i==j-1) printf("%d",div[i]);
        else printf("%d*",div[i]);
    }
    printf("\n");
    return 0;
}
