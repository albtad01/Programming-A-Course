
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    int A[5],B[5],i;
    for(i=0;i<5;i++){
        printf("A[%d]: ",i);
        scanf("%d",&A[i]);
        printf("B[%d]: ",i);
        scanf("%d",&B[i]);
    }
    for(i=0;i<5;i++){
        printf("%d %d ",A[i],B[4-i]);
    }
    printf("\n");
    return 0;
}
