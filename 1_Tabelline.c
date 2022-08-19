#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    int base,lun,i;
    do{
        printf("Base tabellina (positiva): ");
        scanf("%d",&base);
        printf("Lunghezza tabellina (positiva): ");
        scanf("%d",&lun);
        if(base<=0)
            printf("ERRORE: BASE NON POSITIVA\n");
        if(lun<=0)
            printf("ERRORE: LUNGHEZZA NON POSITIVA\n");
    }while(base<=0 || lun<=0);
    for(i=1;i<=lun;i++)
        printf("%d ",base*i);
    printf("\n");
    return 0;
}
