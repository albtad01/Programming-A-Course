
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int leggiInteroPositivo(void);
int sommaDivisori(int num);
int controllaSePerfettoRef(int *num); // da fare con il passaggio per riferimento, se spiegato a lezione
int controllaSeAmici(int num1, int num2);

int main(int argc, const char * argv[]) {
    int n,sd,perf,m,friend;
    n=leggiInteroPositivo();
    sd=sommaDivisori(n);
    perf=controllaSePerfettoRef(&n); // passaggio per riferimento
    if(perf==0) printf("Check: PERFETTO\n");
    if(perf==1) printf("Check: ABBONDANTE\n");
    if(perf==-1) printf("Check: DIFETTIVO\n");
    m=leggiInteroPositivo();
    friend=controllaSeAmici(n,m); // passaggio per copia
    if(friend==0) printf("Check: NON AMICI\n");
    if(friend==1) printf("Check: AMICI\n");
    return 0;
}

int leggiInteroPositivo(void){
    int num;
    do{
        printf("Numero Positivo: ");
        scanf("%d",&num);
    }while(num<=0);
    return num;
}
int sommaDivisori(int num){
    int sdf=0,i;
    for(i=1;i<=num;i++)
        if(num%i==0) sdf+=i;
    return sdf;
}
int controllaSePerfettoRef(int *num){
    int sd;
    sd=sommaDivisori(*num); // passaggio per copia
    if(*num>sd-*num) return 1;
    if(*num<sd-*num) return -1;
    return 0;
}
int controllaSeAmici(int num1, int num2){
    if(sommaDivisori(num1) == sommaDivisori(num2)) return 1;
    return 0;
}
