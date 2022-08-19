
// soluzione array

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define N 100
int main(int argc, const char * argv[]) {
    char S1[N], S2[N];
    int i,j=0;
    printf("Stringa: ");
    scanf("%s",S1);
    for(i=0;S1[i]!='\0';i++){
        if(S1[i]>='0' && S1[i]<='9'){
            S2[j]=S1[i];
            j++;
        }
        S2[j]='\0';
    }
    printf("Solo numeri: %s\n",S2);
    return 0;
}

// soluzione aritmetica puntatori


#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define N 100
int main(int argc, const char * argv[]) {
    char S1[N], S2[N];
    int i,j=0;
    printf("Stringa: ");
    scanf("%s",S1);
    for(i=0;*(S1+i)!='\0';i++){
        if(*(S1+i)>='0' && *(S1+i)<='9'){
            *(S2+j)=*(S1+i);
            j++;
        }
        *(S2+j)='\0';
    }
    printf("Solo numeri: %s\n",S2);
    return 0;
}
