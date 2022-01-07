#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//1.a) ver o output

int pergunta_um_a () {
int x [15] = {1, 2, 3, 4, 5,
6, 7, 8, 9,10,
11,12,13,14,15};
int *y, *z, i;
y = x;
z = x+3;
for (i=0; i<5; i++) {
printf ("%d %d %d\n",
x[i], *y, *z);
y = y+1; z = z+2;
}
return 0;
}

/* resp:

1 1 4
2 2 6
3 3 8
4 4 10
5 5 12

*/

//1.b) ver o output

int pergunta_um_b () {
int i, j, *a, *b;
i=3; j=5;
//a = b = 42; -> apagar «//» se for testar
a = &i; b = &j;
i++;
j = i + *b;
b = a;
j = j + *b;
printf ("%d\n", j);
return 0;
}

/*

13

*/

//2) trocar duas variaveis

void swapM (int *x, int *y){

	int r;

	r=*x;
	*x = *y;
	*y = r;
}

//3) troca as posiçoes i e j do vetor v

void swap (int v[], int i, int j){   // nao sei testar

	int r = v[i];
    v[i] = v[j];
    v[j] = r;
}

//4) calcular a soma de um vetor com N elementos

int soma (int v[], int N){

	int i;
	int soma=0;

	for (i=0; i<N; i++){

		soma += v[i];
	}

	return soma;
}

// funçao jbb

void dumpV (int v[], int N){
    int i;
    for (i=0; i<N; i++) printf ("%d ", v[i]);
    putchar ('\n');
}

//5) inverte um array usando funçoes anteriores

void inverteArray (int v[], int N){

	int i;
	int j=0;

	for (i=0; i < N/2; i++){

		j=N-i-1;
		swap (v, j, i);
	}
}

//------------------------------------------------------> DUVIDAS COM APONTADORES
void inverter (int v[], int N){

	int i=0; int j=0;

	int *x;
	int *y;


	for (i; i < N/2; i++){

		j=N-i-1;
		swapM (&v[i], &v[j]);
	}
}


//6) e coloca em *m o maior dos elementos do vector v

int maximum (int v[], int N, int *m){

	if (N < 1) return 1;
	else {

		int primeiro = v[0];
		*m = primeiro;

		for (int i=0; i<N; i++){

			if (v[i] > *m) *m = v[i];
		}
	}
}

//7) e preenche o vector q com os quadrados dos primeiros N numeros naturais ({0,1,4,9,...}

void quadrados (int q[], int N) {

	int i = 0;

	for (i; i<N; i++) q[i] = pow(i,2);
}

//8.a)  Defina uma funçao que preenche o vector v com a N-esima linha do triangulo de Pascal.

void pascal (int v[], int N){

	int i, j;

	for (i=0; i<N; i++){

		j=i;
		while (j>=0){

			if (j==i) v[j] = 1;
			else if (j > 0) v[j] += v[j-1];
			j--;
		}
	}
}

//8.b) desnha um trinagulo pascal

void desenhaTriangulo (int N){

	int k, v[N];
	for (k=1; k<=N; k++){

		pascal (v, k);
		dumpV (v, k);
	}
}




int main (){

    int a, b, v[10] = {10, 6, 2, 3, 5, 1, 5, 9, 8, 7};
    int x = 3, y = 5;
    printf ("x = %d y = %d\n", x, y);
    swapM (&x, &y);
    printf ("x = %d y = %d\n", x, y);

    printf("\n");

    printf ("%d %d\n", v[0], v[9]);
    swap (v,0,9);
    printf ("%d %d\n", v[0], v[9]);

    printf("\n");

    x = soma (v,10);
    printf ("A soma dos elementos de "); dumpV (v,10);
    printf ("é %d\n", x);

    printf("\n");

    printf ("ao invertemos o array "); dumpV (v,10);
    inverter (v,10);
    printf ("obtemos               "); dumpV (v,10);

    printf("\n");

    x = maximum (v,10, &y);
    printf ("O maior elemento de "); dumpV (v,10);
    printf ("é %d\n", y);

    printf("\n");

    printf ("Os 10 primeiros quadrados: "); 
    quadrados (v,10); 
    dumpV (v,10);

    printf("\n");

    printf ("A linha 5 do triângulo de Pascal é ");
    pascal (v,5); dumpV (v,6);

    printf("\n");

    printf("As linhas 1 a 10 do triangulo de Pascal\n");
    desenhaTriangulo (10);

    printf("\n");

    printf("Fim da Ficha_3\n");

    return 0;
}

