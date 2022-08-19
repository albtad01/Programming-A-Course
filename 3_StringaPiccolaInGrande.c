
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 500
int main(int argc, const char * argv[]) {
    char v1[N],v2[N];
    int len1,len2,i,j=0,inside=0;
    printf("Inserisci Stringa grande: ");
    scanf("%s",v1);
    printf("Inserisci Stringa piccola: ");
    scanf("%s",v2);
    len1=(int)strlen(v1);
    len2=(int)strlen(v2);
    for(i=0;v1[i]!='\0';i++){
        if(v2[j]==v1[i])
            j++;
        else j=0;
        if(j==len2){
            inside++;
            j=0;
        }
    }
    printf("La piccola sta %d volte dentro la grande :/\n",inside);
    return 0;
}
