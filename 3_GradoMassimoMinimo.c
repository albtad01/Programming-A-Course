
#include <stdio.h>
#include <stdlib.h>
#define N 100
int main(int argc, const char * argv[]) {
    char p[N] ;
    int i,j,g=0,G=0,same;
    printf("Stringa: ");
    scanf("%s",p);
    for(i=0;p[i]!='\0';i++){
        same=0;
        for(j=0;p[j]!='\0';j++){
            if(p[i]==p[j]) same++;
        }
        if(i==0){
            g=same;
            G=same;
        }
        if(same>G) G=same;
        if(same<g) g=same;
    }
    printf("g=%d G=%d\n",g,G);
    return 0;
}
