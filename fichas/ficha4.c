#include <stdio.h>
#include <stdlib.h>

//PARTE 1 => ARRAYS E STRINGS

//1) conta as vogais de uma string

int contaVogais (char *s) {

    int k=0;

    while (*s != '\0'){

        if (*s=='a' || *s=='A' || *s=='e' || *s=='E' || *s=='i' || *s=='I' || *s=='o' || *s=='O' || *s=='u' || *s=='U'){

            k++;
        }
        
        *s++;
    }
    
    return k;
}

//2) devolver uma string correta sem vogais repetidas

int verVogal (char *s){

int c=0;

	if (*s=='a' || *s=='A' || *s=='e' || *s=='E' || *s=='i' || *s=='I' || *s=='o' || *s=='O' || *s=='u' || *s=='U'){
		
		c=1;
	}
	
	else c=0;

	return c;
}

void eliminaElemento (char *s){

	for (; *s; s++){
	*s = *(s+1);	
	}
}

int retiraVogaisRep (char *s){

	int k=0;

	while (*s){

		if (verVogal (s) == verVogal (s+1)){

			while (*s == *(s+1)){

				eliminaElemento (s);
				k++;
			}
		}

		*s++;
	}

	return k; 
}

//3) DUPLICAR VOGAIS

void replicate (char *s, char a){
	char vogal_1, vogal_2;

	vogal_1 = *s;
	*s = a;
	s++;
	vogal_2 = *s;

	for(; *s; s++){
		*s = vogal_1;
		vogal_1 = vogal_2;
		vogal_2 = *(s+1);
	}
}

int duplicaVogais (char *s){    // ver esta funçao

	char vogal;
	int c = 0;

	while (*s){

		if (verVogal (s) == 1 && s != (s+1)){
			vogal = *s;
			replicate (s, vogal);
			s++;

			c++;
		}

		*s++;
	}
	return c;
}

//

void dumpV (int v[], int N){
    int i;
    putchar ('{');
    for (i=0; i<N; i++) printf ("%2d ", v[i]);
    putchar ('}');
}


void simNao (int x){
    if (!x) printf (" não ");
}

//

//PARTE 2 => arrays ordenados

//1)testar se um array está ordenado por ordem crescente
// => 0 se verdadeiro | 1 se falso

int ordenado (int v[], int N){

	int i, r;
	r = 0;

	for (i=0; i<N; i++){

		if (v[i] < v[i+1]) r=0;
		else r=1;
	}

	return r;
}

//2) funde dois arrays ordenados

void swap (int v[], int i, int j){
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void ordena(int a[], int N){
    int i = 0;
    while(i < N-1){
        if(a[i] > a[i+1]){
            while(a[i] > a[i+1] && i < N-1){
                swap(a, i, i+1);
                i++;
            }
            i = 0;
        }
        else i++;
    }
} 

void merge (int a[], int na, int b[], int nb, int r[]){

	int N = na + nb;

	int ka = 0;
	int kb = 0;

	int i;

	for (i=0; i<N; i++){

        if(ka < na) {r[i] = a[ka]; ka++;}
        else if(kb < nb) {r[i] = b[kb]; kb++;}
	}

	ordena (r, N);
}

//3)

int partition (int v[], int N, int x){   // ver esta funçao
    
    int c[N];
    int i;
    int j = 0;
    int conta = 0;

    for(i = 0; i < N; i++) c[i] = v[i];

    for(i = 0; i < N; i++){

        if(c[i] < x) {v[j] = c[i]; j++; conta++;}

    }

    for(i = j + 1; i < N; i++){

        if(c[i] > x){v[j] = c[i]; j++;}

    }

    return conta;
}




int main()
{   
	char s1 [100] = "Estaa e umaa string coom duuuplicadoos";
    int x;

    printf("\n");
    
    printf ("Testes\n");
    printf ("A string \"%s\" tem %d vogais\n", s1, contaVogais (s1));

    printf("\n");
    
    x = retiraVogaisRep (s1);
    printf ("Foram retiradas %d vogais, resultando em \"%s\"\n", x, s1);

    printf("\n");
    
    x = duplicaVogais (s1);
    printf ("Foram acrescentadas %d vogais, resultando em \"%s\"\n", x, s1);
    
    printf ("\nFim dos testes sobre strings\n");

    printf("\n");

    int a [15] = {10, 3,45,56, 8,23,13,42,77,31,18,88,24,45, 1},
    b [10] = { 4,12,34,45,48,52,61,73,84,87},        
    c [10] = { 1, 3, 8,22,33,35,38,41,44,49}, 
    d [50];
    
    printf ("Testes\n\n");

    printf("\n");

    printf ("O array "); dumpV(a,15);
    simNao (ordenado (a,15)); printf (" está ordenado\n");
    printf ("O array "); dumpV(b,10);
    simNao (ordenado (b,10)); printf (" está ordenado\n");

    printf("\n");

    printf ("\n\nMerge dos arrays "); dumpV (b,10);
    printf ("\ne                "); dumpV (c,10); 
    merge (b, 10, c, 10, d);
    printf ("\nresulta em       "); dumpV (d,20);

    printf("\n");

    printf ("\n\n\nA partição do array  "); dumpV (a,15);
    printf ("\nusando 30 resulta em "); 
    x = partition (a,15,30); 
    dumpV (a,15); printf (" e retorna %d \n", x);

    printf("\n");

    printf ("Fim dos testes\n");
    return 0;  
}



