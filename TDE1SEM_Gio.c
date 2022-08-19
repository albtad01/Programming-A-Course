
// ESERCIZIO 1

#include<stdio.h>
#include<string.h>
void consonanteMinore(char txt[100],char res[100]);

int main(){
    char txt1[100] = "ho usato molto il computer in questo periodo";
    char txt2[100] = "condivido lo schermo su zoom";
    // TODO: DEFINIZIONE VARIABILI AGGIUNTIVE
    char res1[100], res2[100];
    // TODO: INVOCAZIONE funzione su txt1
    consonanteMinore(txt1,res1);
    // STAMPA tutta la *porzione utilizzata* della stringa "res"
    printf("%s -> %s\n",txt1,res1);
    // TODO: INVOCAZIONE funzione su txt2
    consonanteMinore(txt2, res2);
    // STAMPA tutta la *porzione utilizzata* della stringa "res"
    printf("%s -> %s\n%d",txt2,res2,(' '>'a'));

    return 1;
}
void consonanteMinore(char txt[100],char res[100]){
    int i,j=0;
    char conMin='z';
    for(i=0;txt[i]!='\0';i++){
        if(txt[i]==' '){
            res[j]=conMin;
            conMin='z';
            j++;
        }
        else{
            if(txt[i]!='a' && txt[i]!='e' && txt[i]!='i' && txt[i]!='o' && txt[i]!='u' && txt[i]<conMin)
                conMin=txt[i];
        }
    }
    res[j]='\0';
}

// ESERCIZIO 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct c {
    char c;
    struct c * next;
} Cifra;
typedef Cifra * NumTelefono;
typedef struct con{
    char nome[1000];
    char indirizzo[1000];
    NumTelefono numero;
    struct con * next;
}Contatto;
typedef Contatto * Rubrica;
NumTelefono InsInTestaCifra( NumTelefono lista, char elem );
NumTelefono InsInFondoCifra( NumTelefono lista,char elem );
Rubrica costruisciRubrica(void);
NumTelefono costruisciNumero(char * telefono);
Rubrica InsInFondoContatto( Rubrica lista, char * nome, char * indirizzo, char * telefono );
void StampaRubrica(Rubrica rub);
Rubrica correggiRubrica(Rubrica rub);

int main(){
    Rubrica rub;
    rub=costruisciRubrica();
    // TODO: stampa rubrica
    StampaRubrica(rub);
    // TODO: correggi rubrica
    rub=correggiRubrica(rub);
    // TODO: stampa rubrica corretta
    StampaRubrica(rub);
    return 0;
}
Rubrica costruisciRubrica(void){
    Rubrica lis=NULL;
    int i=0;
    char nomi[5][20]={"Alessandro","Marco","Giacomo","Giovanni","Matteo"};
    char indirizzi[5][20]={"via Milano 1,Mi","via Milano 1,Mi","via Milano 1,Mi","via Milano 1,Mi","via Milano 1,Mi"};
    char telefoni[5][20]={"333333333","+3956789","003956565656","03456678","4444444"};
    for(i=0;i<5;i++)
        lis=InsInFondoContatto(lis,nomi[i],indirizzi[i],telefoni[i]);
    return lis;
}
NumTelefono InsInTestaCifra ( NumTelefono lista, char elem ) {
    NumTelefono punt;
    punt = (NumTelefono) malloc(sizeof(Cifra));
    punt->c = elem;
    punt->next = lista;
    return punt;
}
NumTelefono InsInFondoCifra(NumTelefono lista,char elem ) {
    NumTelefono punt;
    if( lista==NULL ) {
        punt = (NumTelefono)malloc( sizeof(Cifra) );
        punt->next = NULL;
        punt->c = elem;
        return punt;
    }
    else {
        lista->next = InsInFondoCifra( lista->next, elem );
        return lista;
    }
}
NumTelefono costruisciNumero(char * telefono){
    int i;
    NumTelefono lis=NULL;
    for(i=0;telefono[i]!='\0';i++)
        lis=InsInFondoCifra(lis,telefono[i]);
    return lis;
}
Rubrica InsInFondoContatto( Rubrica lista, char * nome, char * indirizzo, char * telefono ) {
    Rubrica punt;
    if( lista==NULL ) {
        punt = (Rubrica)malloc( sizeof(Contatto) );
        punt->next = NULL;
        strcpy(punt->nome, nome);
        strcpy(punt->indirizzo, indirizzo);
        punt->numero=costruisciNumero(telefono);
        return punt;
    }
    else {
        lista->next = InsInFondoContatto( lista->next, nome, indirizzo,telefono );
    }
    return lista;
}
void StampaRubrica(Rubrica rub){
    if(rub==NULL)
        printf("\n");
    else{
        printf("%s %s ",rub->nome,rub->indirizzo);
        NumTelefono num=rub->numero;
        while(num!=NULL){
            printf("%c",num->c);
            num=num->next;
        }
        printf("\n");
        StampaRubrica(rub->next);
    }
}
Rubrica correggiRubrica(Rubrica rub){
    NumTelefono temp=NULL;
    Rubrica head=rub;
    while(rub!=NULL){
        if(rub->numero->c=='0' && rub->numero->next->c=='0'){
            rub->numero->c='+';
            temp=rub->numero->next->next;
            free(rub->numero->next);
            rub->numero->next=temp;
        }
        if(rub->numero->c >='0' && rub->numero->c <='9'){
            rub->numero=InsInTestaCifra(rub->numero, '9');
            rub->numero=InsInTestaCifra(rub->numero, '3');
            rub->numero=InsInTestaCifra(rub->numero, '+');
        }
        rub=rub->next;
    }
    return head;
}

// ESERCIZIO 3

SELECT CODICE, count(*)
FROM CORSO
WHERE DATA_INIZIO>'1/1/2020'
GROUP BY CODICE

SELECT CFIscritto
FROM ISCRIZIONE
GROUP BY CFIscritto
HAVING count(*)<2
