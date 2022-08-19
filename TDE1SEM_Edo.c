// ! ESERCIZIO 1

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
void compattaParole(char txt[100],char res[100]);
void stampaParola(char s[100]);
int main()
{
    char txt1[100] = "che bella giornata su Zoom";
    char txt2[100] = "misione compiuta!";
    // TODO: DEFINIZIONE VARIABILI AGGIUNTIVE
    char res1[100], res2[100];
    // TODO: INVOCAZIONE funzione  txt1
    compattaParole(txt1,res1);
    // STAMPA tutta la *porzione utilizzata* del vettore "lun"
    stampaParola(res1);
    // TODO: INVOCAZIONE funzione  txt2
    compattaParole(txt2,res2);
    // STAMPA tutta la *porzione utilizzata* del vettore "lun"
    stampaParola(res2);
}
void compattaParole(char txt[100],char res[100]){
    int i,j=0;
    for(i=0;txt[i]!='\0';i++){
        if(j==0 || txt[i+1]==' ' || txt[i-1]==' ' || txt[i+1]=='\0'){
            res[j]=txt[i];
            j++;
        }
    }
    res[j]='\0';
}
void stampaParola(char s[100]){
    printf("%s",s);
    printf("\n");
}

// ESERCIZIO 4
SELECT CF, Cognome, Nome
FROM SOMMELIER
WHERE CF IN (SELECT CFIscritto FROM ISCRIZIONE WHERE DATA_INIZIO_CORSO>='1/1/1994'
             AND DATA_INIZIO_CORSO<='31/12/1994' GROUP BY CFIscritto HAVING count(*)>=2)

CREATE VIEW MAX_PREZZO(CODICE_CORSO,DATA_INIZIO_CORSO,MAX) AS
SELECT CODICE_CORSO, DATA_INIZIO, max(Prezzo)
FROM ISCRIZIONE
GROUPBY CODICE_CORSO, DATA_INIZIO


             SELECT M1.CODICE_CORSO, M1.DATA_INIZIO_CORSO
             FROM MAX_PREZZO AS M1
             WHERE M1.MAX >= all(SELECT M2.MAX
                                               FROM MAX_PREZZO AS M2
                                               WHERE M1.DATA_INIZIO_CORSO=M2.DATA_INIZIO_CORSO)
