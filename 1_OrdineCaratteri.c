#include <stdio.h>

int main(int argc, const char * argv[]) {
    char a,b,c;
    printf("Inserisci carattere 1: ");
    scanf(" %c",&a);
    printf("Inserisci carattere 2: ");
    scanf(" %c",&b);
    printf("Inserisci carattere 3: ");
    scanf(" %c",&c);
    if(a>b){
        if(b>=c) printf("%c %c %c",c,b,a);
        if(c>=b && c<=a) printf("%c %c %c",b,c,a);
        if(c>=b && c>a) printf("%c %c %c",b,a,c);
    }
    if(b>=a){
        if(c>=a && b>=c) printf("%c %c %c",a,c,b);
        if(c>=a && b<c) printf("%c %c %c",a,b,c);
        if(a>=c) printf("%c %c %c",c,a,b);
    }

    printf("\n");
    return 0;
}

// nella soluzione stampavo prima il maggiore, poi gli altri due
