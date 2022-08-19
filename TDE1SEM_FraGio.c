// ESERCIZIO 1

#include<stdio.h>
void primaPosizioneVocale(char txt[100],char res[100]);
int main()
{
    char txt1[100] = "volo in aeroplano con la prima aurora";
    char txt2[100] = "mangio due uova nella aiuola";
    // TODO: DEFINIZIONE VARIABILI AGGIUNTIVE
    char res1[100],res2[100];
    // TODO: INVOCAZIONE funzione su txt1
    primaPosizioneVocale(txt1, res1);
    // STAMPA tutta la *porzione utilizzata* del vettore "pos"
    printf("%s\n", res1);
    // TODO: INVOCAZIONE funzione su txt2
    primaPosizioneVocale(txt2, res2);
    // STAMPA tutta la *porzione utilizzata* della stringa "pos"
    printf("%s\n",res2);
    return 0;
}
void primaPosizioneVocale(char txt[100],char res[100]){
    int i,j=0,posparola=0,flag=0;
    for(i=0;txt[i]!='\0';i++){
        if((txt[i]=='a' || txt[i]=='e' || txt[i]=='i' || txt[i]=='o' || txt[i]=='u') && flag==0){
            res[j]=posparola+'0';
            j++;
            flag++;
        }
        if(txt[i]==' '){
            flag=0;
            posparola=-1;
        }
        posparola++;
    }
    res[j]='\0';
}
