#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno {

	int numero;
	char nome [100];
	int miniT [6];
	float teste;

} Aluno;

//1)

int nota (Aluno a){

	int k,n;
	k=0;

	for (n=0; n<6; n++){

		k += a.miniT[n];
	}

	int nota_mini_testes=0;

	nota_mini_testes = ((k*20)/12) * 0.3;

	int nota_teste=0;

	nota_teste = a.teste * 0.7;

	int nota_final=0;

	nota_final = nota_mini_testes + nota_teste;

	if (nota_final >= 10) {return nota_final;}
	else {return 0;} 
}


//2)

int procuraNum (int num, Aluno t[], int N){

	int i, x, c;
	x=0;
	c=-1;

	for (i=0; i<N; i++){

		x = t[i].numero;
		if (num == x) {c=i;}
	}

	return c;
}


//3)

void swap (Aluno t[], int i, int j){

	Aluno r;

	r=t[i];
	t[i]=t[j];
	t[j]=r; 
}

void ordenaPorNum (Aluno t[], int N){

	int i, j, x, k;
	x=k=0;

	for (i=0; i<N; i++){

		for (j=i+1; j<N; j++){

			x=t[i].numero;
			k=t[j].numero;

			if (x>k) {swap (t, i, j);}
		}
	}
}


//4)

int procuraaux (int num, Aluno t[], int N){

	int i, x, c;
	x=0;
	c=-1;

	for (i=0; i<N; i++){

		x = t[i].numero;
		if (num == x) {c=i;}
	}

	return c;
}

void criaIndPorNum (Aluno t[], int N, int ind[]){

	Aluno array[N];

	for (int i=0; i<N; i++){

		array[i] = t[i];
	}

	ordenaPorNum (array, N);

	for (int i=0; i<N; i++){

		ind[i] = procuraaux (array[i].numero, t, N);
	}
}


//5)

void imprimeTurma (int ind[], Aluno t[], int N){

	int i=0;
	Aluno turma[N];

	for (i; i<N; i++){

		turma[i] = t[ind[i]];
	}

	for (i; i<N; i++){t[i] = turma[i];}
}

//6)

/* nao percebi o que é
para fazer neste exercicio */


//7)

void ordenaPorNome (Aluno t[], int N){

	int p;
	int trocas = 0;
	Aluno aux;

	while (trocas){

		trocas = 0;
		p = 0;

		while (p < N-1){

			if (strcmp (t[p].nome, t[p+1].nome) > 0);{

				aux = t[p];
				t[p] = t[p+1];
				t[p+1] = aux;
				trocas = 1;}

		p++;}
	}
}

int procuraNome(char n[100], Aluno t[], int N){
    int i; 
	int res = -1;

    for(i = 0; i < N ; i++){
        
		if(strcmp(t[i].nome, n)==0) res = i;	
    }
    
	return res;
}

void criaIndPorNome (Aluno t[], int N, int ind[]){

	int i;
	Aluno turmaAux[N];

	for (i=0; i<N; i++){

		turmaAux[i]=t[i];
	}

	ordenaPorNome (turmaAux, N);

	for (i=0; i<N; i++){

		ind[i] = procuraNome (turmaAux[i].nome, t, N);
	}
}


int main () {
     Aluno Turma1 [7] = {{2222, "André", {2,1,0,2,2,2}, 10.5}
                       ,{3333, "Paulo", {0,0,2,2,2,1},  8.7}
                       ,{4444, "Carla", {2,1,2,1,0,1}, 14.5}
                       ,{5555, "Joana", {2,0,2,1,0,2},  3.5}
                       ,{6666, "Maria", {2,2,2,2,2,1},  5.5}
                       ,{7777, "Bruna", {2,2,2,1,0,0}, 12.5}
                       ,{8888, "Diogo", {2,2,1,1,1,0},  8.5}
                       };

     Aluno Turma2 [7] = {{4444, "André", {2,1,0,2,2,2}, 10.5}
                       ,{3333, "Paulo", {0,0,2,2,2,1},  8.7}
                       ,{8888, "Carla", {2,1,2,1,0,1}, 14.5}
                       ,{2222, "Joana", {2,0,2,1,0,2},  3.5}
                       ,{7777, "Maria", {2,2,2,2,2,1},  5.5}
                       ,{6666, "Bruna", {2,2,2,1,0,0}, 12.5}
                       ,{5555, "Diogo", {2,2,1,1,1,0},  8.5}
                       } ;

    Aluno t[4] = {{4444, "Andre", {2,1,0,2,2,2}, 10.5},{2222, "Joana", {2,2,2,1,0,0}, 14.5},{7777, "Maria", {2,2,2,2,2,1}, 18.5},{3333, "Paulo", {0,0,2,2,2,1},  8.7}};

    int indNome [7], indNum [7];
    int i;
    
    printf ("\n-------------- Testes --------------\n");

    printf("\n");

    Aluno a = {8888, "Carla", {2,1,2,1,0,1}, 14.5};
    int x = nota (a);
    printf ("Nota de pauta: %d\n", x);

    printf("\n");

    int n = procuraNum(2222, Turma1, 7);
	printf("A posicao do aluno 2222 e %d\n", n);

    printf("\n");

    ordenaPorNum(Turma2, 7);
    printf("A Turma2, ordenada, fica:\n");
    for(int i = 0; i < 7; i++){
        printf("num: %d, nome: %s, miniT: %d, teste: %f\n", Turma2[i].numero, Turma2[i].nome, Turma2[i].miniT[0], Turma2[i].teste);
    }

    printf("\n");

    printf("Os indices ordenados ficam:\n");
    int ind[4];
    criaIndPorNum(t, 4, ind);
    for(int i = 0; i < 4; i++) printf("%d\n", ind[i]);
    
    printf("\n");

	printf("A turma ordenada pelos indices:\n");
	imprimeTurma(ind, t, 4);
	for(int i = 0; i < 4; i++){
    printf("num: %d, nome: %s, miniT: %d, teste: %f\n", Turma2[i].numero, Turma2[i].nome, Turma2[i].miniT[0], Turma2[i].teste);}
    
	printf("\n");

	printf("Os indices ordenados pelo nome ficam:\n");
    int indices[4];
    criaIndPorNome(t, 4, indices);
    for(int i = 0; i < 4; i++) printf("%d\n", indices[i]);
    
    printf("\nFim dos testes.\n");


    return 0;
}









