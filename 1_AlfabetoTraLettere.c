#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    char a,b;
    char i;
    printf("Inserisci carattere 1: ");
    scanf(" %c",&a);
    printf("Inserisci carattere 2: ");
    scanf(" %c",&b);
    if(a==b) printf("I due caratteri sono uguali!");
    else{
        if(b>a){
            printf("%c viene prima di %c\n",a,b);
            for(i=a;i<=b;i++)
                printf("%c",i);
        }
        else{
            printf("%c viene prima di %c\n",b,a);
            for(i=b;i<=a;i++)
                printf("%c",i);
        }
    }
    printf("\n");
    return 0;
}
