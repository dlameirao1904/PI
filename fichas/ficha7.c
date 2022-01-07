#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct celula {
    char *palavra;
    int ocorr;
    struct celula * prox;
} * Palavras;


//-----------------------------
void libertaLista (Palavras);
int quantasP (Palavras);
void listaPal (Palavras);
char * ultima (Palavras);
Palavras acrescentaInicio (Palavras, char *);
Palavras acrescentaFim (Palavras, char *);
Palavras acrescenta (Palavras, char *);
struct celula * maisFreq (Palavras);
//---------------------------------

//1)
void libertaLista (Palavras l){
    Palavras aux;
    aux = l;
    
    Palavras aux2;
    aux2 = malloc (sizeof (struct celula));

    while (aux != NULL){
        aux2 = aux->prox;
        free(aux);
        aux = aux->prox;
    } 
}

//2)
int quantasP (Palavras l){
    int i=0;
    while (l != NULL){
        i++;
        l = l->prox;
    }
    return i;
}

//3)
void listaPal (Palavras l){
    Palavras aux;
    aux = l;
    for (; aux != NULL; aux=aux->prox){ 
        printf ("%s, %d\n", aux->palavra, aux->ocorr);
    }
}

//4)
char * ultima (Palavras l){
    char *pal = (char *) malloc (sizeof (char)*256);
    int conta = 0;
    int x = quantasP(l);
    //l->ocorr = x;
    while (l != NULL)
    {
        conta++;
        if (conta == x) return l->palavra;
        else {l->prox;}
    }
    
    return NULL;
}

//5)
Palavras acrescentaInicio (Palavras l, char *p){
    Palavras aux;
    aux = malloc (sizeof (struct celula));
    aux->palavra=p;
    aux->ocorr=1;
    aux->prox=l;
    return aux;
}

//6)
Palavras acrescentaFim (Palavras l, char *p){
    
    Palavras aux = l;
    Palavras aux2 = malloc (sizeof (struct celula));

    for (; aux != NULL; aux = aux->prox);

    aux2->palavra = p;
    aux2->ocorr=1;
    aux2->prox=NULL;
    
    aux = aux2;

    return NULL;
}

//7)
Palavras acrescenta (Palavras l, char *p){
    
    Palavras aux = l;
    int r = 1;

    for (; aux!=NULL; aux = aux->prox){

        if (strcmp(aux->palavra, p) == 0){aux->ocorr++; r=0;}
    
    }
    if (r==1) l = acrescentaInicio(l, p);

    return l;
}

//8)
struct celula * maisFreq (Palavras l){
    
    Palavras aux = l;
    Palavras aux2 = malloc (sizeof (struct celula));
    aux2->ocorr = 0;

    for (; aux != NULL; aux = aux->prox){

        if (aux->ocorr > aux2->ocorr){aux2 = aux;}
    }

    return aux2;
}

//-------------------------------------------------

int main () {
    Palavras dic = NULL;

    char * canto1 [44] = {"as", "armas", "e", "os", "baroes", "assinalados",
                          "que", "da", "ocidental", "praia", "lusitana", 
                          "por", "mares", "nunca", "de", "antes", "navegados",
                          "passaram", "ainda", "alem", "da", "taprobana",
                          "em", "perigos", "e", "guerras", "esforcados",
                          "mais", "do", "que", "prometia", "a", "forca", "humana",
                          "e", "entre", "gente", "remota", "edificaram", 
                          "novo", "reino", "que", "tanto", "sublimaram"};

    printf ("\n_____________ Testes _____________\n\n");

    int i; struct celula *p;
    for (i=0;i<44;i++)
        dic = acrescentaInicio (dic, canto1[i]);

    printf ("Foram inseridas %d palavras\n", quantasP (dic));
    printf ("\n");
    printf ("palavras existentes:\n\n");
    listaPal (dic);
    printf ("\n");
    printf ("última palavra inserida: %s\n", ultima (dic));
    printf ("\n");

    libertaLista (dic);

    dic = NULL;

    printf ("__________________________\n");
    printf ("\n\n");
    srand(42);
    
    for (i=0; i<1000; i++)
        dic = acrescenta (dic, canto1 [rand() % 44]);
    
    printf ("Foram inseridas %d palavras\n", quantasP (dic));
    printf("\n");
    printf ("palavras existentes:\n"); 
    listaPal (dic);
    printf ("\n");
    printf ("última palavra inserida: %s\n", ultima (dic));
    printf ("\n");
    
    p = maisFreq (dic);
    printf ("Palavra mais frequente: %s (%d)\n", p->palavra, p->ocorr);
    printf ("\n");
    printf ("\n_________ Fim dos testes _________\n\n");

    return 0;
}