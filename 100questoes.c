#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <assert.h>


//1)Defina um programa que le (usando a funçao scanf uma sequencia de numeros inteiros terminada com o numero 0 e imprime no ecran o maior elemento da sequencia.

int maiorseq ()
{
    int x, k;
    k = 0;
    scanf ("%d", &x);
    while (x != 0){
        if (x>k) k=x;
        scanf ("%d", &x);
    }
    printf("%d\n", k);
    return 0;
}

//2)Defina um programa que le (usando a funçao scanf uma sequencia de numeros inteiros terminada com o numero 0 e imprime no ecran a media da sequencia.

double mediaseq ()
{
    double x, k, i;
    i=0;
    k=0;
    scanf ("%lf", &x);
    while (x != 0){
     k=k+x;
     scanf ("%lf", &x); i++;
}
        printf("%le\n", k/i);
        return 0;
}

//3)Defina um programa que le (usando a funçao scanf uma sequencia de numeros inteiros terminada com o numero 0 e imprime no ecran o segundo maior elemento.

int segmaior ()
{
    int x, k, y;
    k=0;
    y=0;

    scanf ("%d", &x);
    while (x != 0){
       if (x>k){
        y=k;
        k=x;
    }
       else if (x>y) y=x;
       scanf ("%d", &x);
    }
    printf ("%d\n", y);
    return 0;
} 

//4)calcula o numero de bits iguais a 1 usados na representaçao binaria de um dado numero n.

int bitsUm (unsigned int n)
{
    int i=0;

    while (n != 0){
        if (n%2==1) i++;
        n=n/2;
    }
    return i;
}

//5)calcula o numero de bits a 0 no final da representaçao binaria de um numero (o expoente da maior potencia de 2 que é divisor desse numero).

int trailingZ (unsigned int n)
{
    int i = 1;

    while (n != 0 && i<32) {
        if (n%2==0) i++;
        else break;
        n=n/2;
    }
    return i;
}

//6)calcular o numero de digitos que tem um numero

int qDig (unsigned int n)
{
    int i = 0;

        if (n/10 < 1) i=1;
        else i = 1 + qDig (n/10);
        return i;
}

//7)concatena strings

char *juntastr (char s1[], char s2[])
{
    int i, j;
    i=0;
    j=0;
    

    while (s1[i] != '\0') i++;
    while (s2[j] != '\0') {
        s1[i] = s2[j];
        i++;
        j++;
    }
    s1[i] = '\0';

    return s1;
}

//8)copia a string source para dest retornando o valor desta última

char *strcpy (char s1[], char s2[]) 
{    

    int i;

    for (i=0 ; s1[i] != '\0' ; i++) s1[i] = '\0';
    for (i=0 ; s2[i] != '\0' ; i++){
        s1[i] = s2[i];
    }
    s1[i] = '\0';

   return s1;
}

//9) compara (lexicograficamente) duas strings.

int strcmp (char s1[], char s2[]){

    int i;

    for (i=0; s1[i]!='\0' || s2[i]!='\0'; i++){

    if (s1[i] == s2[i]);
    else if (s1[i] > s2[i]) return 1;
    else return -1;
    }
    return 0;
}


//10) determina a posição onde a string s2 ocorre em s1. A função deverá retornar NULL caso s2 não ocorra em s1.

char *mystrstr (char s1[], char s2[]) {

    
    int i, j;
    i=0;
    j=0;

    while (s1[i] != '\0' && s2[j] != '\0'){
       if (s1[i] == s2[j]){
        i++; 
        j++;
    }
       else { i++; 
        j=0;
       }
   }
   
   char *p = &s1[i-j];

   if (s2[j] == '\0') return p;
   else return NULL;
}

//11) inverte uma string.

void strrev (char s[]){

    int i;

    for (i=0; s[i] != '\0'; i++);

    char p[i];
    int j, c;
    c=i;
    i=i-1;

    for (j=0; j=c; j++, i--);{
        p[j] = s[i];
    }

    i=0;
    s[i] = p[i];
}

//12) retira todas as vogais de uma string.

void strnoV (char s[]) {

    int i, c;
    i=0;

    while (s[i] != '\0'){

        if (s[i]=='a' || s[i]=='A' || s[i]=='e' || s[i]=='E' || s[i]=='i' || s[i]=='I' || s[i]=='o' || s[i]=='O' || s[i]=='u' ||s[i]=='U'){

            for (c=i; s[c] != '\0'; c++){

                s[c] = s[c+1];
            }
        }
        
        else i++;
    }

}

//13) palavras so com n letras

void truncW (char t[], int n){
    int c=0, i, j;
    
    for(i=0;t[i] != '\0';i++){
        
        if(t[i] == ' ') c=0;
        
        else if(c==n){
            
            if(t[i] != ' '){
                
                for(j=i; t[j] !='\0';j++){
                    
                    t[j] =t[j+1];
                }
                
                i--;
            }
        }
        
        else c++;
    }
}

//14)retornar o caracter mais frequente numa string, retornar 0 se for vazia

char charMaisfreq (char s[]) {
    
int i, j;
int accum1, accum2;
char caracter = 'O';

accum1 = accum2 = 0;

if (s[1] == '\0') caracter = s[0];

for (i=0; s[i]!='\0'; i++){
    
    for (j=i+1; s[j] != '\0'; j++){
        
        if (s[i] == s[j]) accum1++;
        }
        
        if (accum1 > accum2){
            
            accum2 = accum1;
            caracter = s[i];
        }
        accum1 = 0;
    }
    
    return caracter;
}

//15) retornar o numero de vezes que aparece o caracter (consecutivo) + freq

int iguaisConsecutivos (char s[]){
    
    int i, count, accum;
    i = count = 0;
    accum = 1;

    while (s[i] != '\0'){

        if (s[i] == s[i+1]){
            accum ++;
            }

        else if (accum > count){
                count = accum;
                accum = 1;
                }
        i++;
    }

    return count;
}

//16)retornar o numero de vezes que aparecem os caracteres (consecutivo) + frequentemente diferentes

int not_in_prev(char str[], int k, int n) {
    int ans = 1;
    for(int i = k; i < n; i++) {
        if(str[i] == str[n]) {
            return 0;
        }
    }
    return ans;
}

int difConsecutivos(char s[]) {
    int ans = 0;
    for(size_t i = 0; s[i]; i++) {
        int consec = 0;
        for(size_t j = i; s[j]; j++) {
            if(not_in_prev(s,i,j)) consec++;
            else break;
        }
        if (consec > ans) ans = consec;
    }
    return ans;
}

//17)calcula o comprimento do maior prefixo comum entre as duas strings.

int maiorPrefixo (char s1 [], char s2 []){
    int i, count;

    for (i=0; s1[i]!='\0' && s2[i] !='\0'; i++){
        int a = s1[i], b = s2[i];
        if (a==b) count++;
        else return count;
    }
    return count;
}

//18) calcula o comprimento do maior sufixo comum entre as duas strings.
int maiorSufixo (char s1 [], char s2 []){
    int i, j, count;
    count=0;
    i=strlen(s1);
    j=strlen(s2);

    while(i>0 && j>0){
        if (s1[i-1]==s2[j-1]){ 
        i--;
        j--;
        count++;
        }
        else {return count;}
        
    }
    return count; 
}

//19)calcula o tamanho do maior sufixo de s1 que e um prefixo de s2

int sufPref (char s1[], char s2[]){
    int i=0, j=0, count=0;
    while (s1[i]!='\0' && s2[j]!='\0'){
        int b=s1[i], d=s2[j];
        if (b==d){i++; j++; count++;}
        else{i++; j=0; count=0;}
    }
    if (s1[i]!='\0') return 0;
    else return count;
}

//20)conta as palavras de uma string.
int contaPal (char s[]){
    int r=0, i=0, first=1;
    while (s[i])
    {
        if(s[i]==' ' || s[i]=='\n') first=1;
        else if (first){
            r++;
            first=0;
        }
        i++;
    }
return r;
}

//21)  retorna o numero de vogais da string s
int contaVogais (char s[]){
    int i=0;
    int count=0;
    
    while(s[i] != '\0'){
         if (s[i]=='a' || s[i]=='A' || s[i]=='e' || s[i]=='E' || s[i]=='i' || s[i]=='I' || s[i]=='o' || s[i]=='O' || s[i]=='u' ||s[i]=='U')count++;
         i++;
    }
    return count;
}

//22)testa se todos os caracteres da primeira string
int contida (char a[], char b[]) {
    int cont = 1;
    int i;
    int j;
    
    for(i=0; a[i]; i++) {
        int pertence = 0;
        for(j=0; b[j]; j++) {
            if(a[i] == b[j]) pertence = 1;
        }
        if(!pertence) {
            cont = 0;
            break;
        }
    }
    return cont;
}

//23)testa se uma palavra é palíndrome, i.e., le-se de igual forma nos dois sentidos.
int palindroma (char s[]) {
    int tamanho = 0;
    int i;
    for(i=0; s[i]; i++) len++;
    for(i=0; s[i]; i++) if(s[i]!=s[tamanho-1-i]) return 0;
    return 1;
}

//24) elimina de uma string todos os caracteres que se repetem sucessivamente deixando la apenas uma copia. elimina de uma string todos os caracteres

int remRep (char x[]){
    int i=0, j=0, last=0;
    char aux[strlen(x)];
    while (x[i])
    {
        aux[j]=x[i];
        while (x[i]==aux[j]) i++;
        j++;
    }
    aux[j]='\0';
    strcpy(x, aux);
    return j;
}

//25) elimina repetiçoes sucessivas de espaços por um unico espaço.

void elimina(char* s) {
    for(; *s; s++)
        *s = *(s+1);
}

int limpaEspacos (char t[]) {
    int i = 0;
    int prevSpace = 0;
    
    while(t[i]!='\0') {
       
        if(t[i] == ' ') {
            
            if(prevSpace) {
                elimina(t + i);
                continue;
            }
            
            else prevSpace = 1;
        }
       
        else prevSpace = 0;
        i++;
    }
    return i;
}

//26)  insere um elemento (x) num vector ordenado.

void insere (int v[], int N, int x) {
    
    for(int i = 0; i < N; i++) {
        
        if(v[i] > x) {
            
            for(int j = N; j > i; j--) {
                v[j] = v[j - 1];
            }
           
            v[i] = x;
            break;
        }
       
        else if(i == N - 1) {
            v[N] = x;
        }
    }
}

//27) preenche o vector r (com na+nb elementos) com os elementos de a e b ordenados.

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

void merge (int r [], int a[], int b[], int na, int nb){
    int i, j, x=0;
    
    for(i=0;i<na; i++){
        r[i]=a[i];
    }
    for(j=0; j<nb; j++){
        r[i+j]=b[j];
    }
    x=na+nb
    ordena(r, x);
}

//28) testa se os elementos do vector a, entre as posiçoes i e j (inclusive) estao ordenados por ordem crescente.

int crescente (int a[], int i, int j) {
    int count=1;
    int k;

    for(k=i; k<j; k++) {
        if(a[k+1]<a[k]) count=0;
    }
    return cresc;
}

//29) retira os numeros negativos de um vector com N inteiros.

int retiraNeg (int v[], int N) {
    int i=0;
    int j=0;

    while(i<N) {
        if(v[i] < 0) {
            for(j=i; j<N-1; j++) v[j]=v[j+1];
            N--;
        }
        else i++;
    }
    return N;
}

//30)recebe um vector v com N elementos ordenado por ordem crescente e retorna o menos frequente dos elementos do vector. 

int menosFreq (int v[], int N) {
    int i=0;
    int freq=1;
    int res=N;
    int aux=v[0];

    for(i; i<N-1; i++){
        if (v[i]==v[i+1])freq++;
        else{
            if (freq<res){
                res=freq;
                aux=v[i];
            }
            freq=1;
        } 
    }
    if (freq < res){
    res = freq;
    aux = v[i];
    }
    return aux;
}

//31) recebe um vector v com N elementos ordenado por ordem crescente e retorna o mais frequente dos elementos do vector.

int maisFreq (int v[], int N) {
    int i=0;
    int freq=1;
    int res=1;
    int aux=v[0];

    for(i; i<N-1; i++){
        if (v[i]==v[i+1])freq++;
        else{
            if (freq>res){
                res=freq;
                aux=v[i];
            }
            freq=1;
        } 
    }
    if (freq > res){
    res = freq;
    aux = v[i];
    }
    return aux;
}

//32) calcula o comprimento da maior sequencia crescente de elementos consecutivos num vector v com N elementos. 

int maxCresc (int v[], int N){
    int i=0;
    int accum=1;
    int count=1;

    for(i; i<N-1; i++){
        if (v[i]<=v[i+1]){
            accum++;
        }
        else{
            if(accum>count){
                count = accum;
            }
            accum=1;
        }
    }
    if (accum>count)count=accum;
    return count;
}

//33) recebe um vector v com n inteiros e elimina as repetiçoes. 

 int elimRep (int v[], int n) {
    int i=1;
    int j;

    while(i<n) {
        int belongs = 0;
        for(j=0; j<i; j++) {
            if(v[i]==v[j]) belongs = 1;
        }
        if(belongs) {
            for(j=i; j<n; j++) {
                v[j]=v[j+1];
            }
            n--;
        } else i++;
    }
    return n;
}

//34)recebe um vector v com n inteiros ordenado por ordem crescente e elimina as repetiçoes.

int elimRepOrd (int v[], int n) {return elimRep(v,n);}

//35) calcula quantos elementos os vectores a (com na elementos) e b (com nb elementos) tem em comum. 

int comunsOrd (int a[], int na, int b[], int nb){
    int  i=0;
    int j=0;
    int accum=0;

    while(i<na && j<nb){
        if(a[i] == b[j]){
            accum++;
            i++;
            j++;
        }
        else if (a[i]>b[j])j++;
        else i++;
    }
    return accum;
}

//36)  calcula quantos elementos os vectores a (com na elementos) e b (com nb elementos) tem em comum 

int comuns (int a[], int na, int b[], int nb) {
    int accum=0;
    int i=0;
    int j=0;
    
    for(i; i<na; i++) {
        int comum = 0;
        for(j=0; j<nb; j++) if(a[i] == b[j]) comum=1;
        if(belongs) accum++;
    }
    return accum;
}

//37) dado um vector v com n inteiros, retorna o ındice do menor elemento do vector.

int minInd (int v[], int n){
    int i=0;
    int menor=0;

    for(i; i<n; i++){
        if(v[i]<v[menor]){
            menor=i;
        }
    }
    return menor;
}

//38) preenche o vector Ac com as somas acumuladas do vector v.

void somasAc (int v[], int Ac [], int N){
    int i=0;
    int j=0;
    
    for(i; i<N; i++){
        Ac[i]=0;
        for(j=0; j<=i; j++){
            Ac[i]+=v[j];
        }
    }
} 

//39) testa se uma matriz quadrada e triangular superior, i.e., que todos os elementos abaixo da diagonal sao zeros.

int triSup (int N, float m [N][N]){
    int i=0;
    int j=0;
    int x=1;

    for(i; i<N; i++){
        for(j; j<i; j++){
            if(m[i][j]) x=0;
        }
    }
    return x;
}

//40) transforma uma matriz na sua transposta.

void transposta (int N, float m[N][N]) {
    int i=0;
    int j=0;
    
    
    for(i; i<N; i++) {
        for(j; j<i; j++) {
            float aux = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = aux;
        }
    }
}

//41) que adiciona a segunda matriz a primeira.

void addTo (int N, int M, int a [N][M], int b[N][M]){
    int i=0;
    int j=0;

    for(i;  i<N; i++){
        for(j; j<M; j++){
            a[i][j]+=b[i][j];
        }
    }coloca no array r o resultado da uni˜ao dos conjuntos v1 e v2
}

//42) coloca no array r o resultado da uniao dos conjuntos v1 e v2

int unionSet (int N, int v1[N], int v2[N], int r[N]) {
    int len=0;
    int i=0;
    for(i; i<N; i++) {
        r[i] = v1[i] || v2[i];
        len += r[i];
    }
    return len;
}

//43) coloca no array r o resultado da intersçao dos conjuntos v1 e v2.

int intersectSet (int N, int v1[N], int v2[N], int r[N]){
    int len=0;
    int i=0;
    for(i; i<N; i++) {
        r[i] = v1[i] && v2[i];
        len += r[i];
    }
    return len;
} 

//44) coloca no array r o resultado da interseçao dos multi-conjuntos v1 e v2.

int intersectMSet (int N, int v1[N], int v2[N],int r[N]) {
    int len=0;
    int i=0;

    for(i; i<N; i++) {
        if(v1[i]<v2[i]) r[i]=v1[i];
        else r[i]=v2[i];
        len += r[i]; 
    }
    return len;
}

//45)  coloca no array r o resultado da uniao dos multi-conjuntos v1 e v2.

int unionMSet (int N, int v1[N], int v2[N], int r[N]){
    int len=0;
    int i=0;

    for(i; i<N; i++) {
        if(v1[i]>v2[i]) r[i]=v1[i];
        else r[i]=v2[i]; 
    }
} 

//46)calcula a numero de elementos do multi-conjunto 

int cardinalMSet (int N, int v[N]) {
    int len=0;
    int i=0;

    for(i; i<N; i++) len += v[i];
    return len;
}

//47) dada uma posiçao inicial e um array com N movimentos, calcula a posiçao final do robot depois de efectuar essa sequˆencia de movimentos. 

typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;
typedef struct posicao {
int x, y;
} Posicao;

Posicao posFinal (Posicao inicial, Movimento mov[], int N){
    int i=0;

    for(i; i<N; i++){
        Movimento x = mov[i];
        if(x == Norte) inicial.y++;
        if(x == Este) inicial.x++;
        if(x == Sul) inicial.y--;
        if(x == Oeste) inicial.x--;
    }
    return inicial;
}

//48)  preenche o array com os movimentos suficientes para que o robot passe de uma posiçao para a outra.

int caminho (Posicao inicial, Posicao final, Movimento mov[], int N){
    int i=0;
    int xf = final.x;
    int yf = final.y;
    int *xi = &inicial.x;
    int *yi = &inicial.y;

    for(i; i<N; i++){
    if ((*xi)>xf){
        (*xi)--;
        mov[i]=Oeste;
    }

    else if ((*xi)<xf){
        (*xi)++;
        mov[i]=Este;
    }

    else if ((*yi)>yf){
        (*yi)--;
        mov[i]=Sul;
    }

    else if ((*yi)<yf){
        (*yi)++;
        mov[i]=Norte;
    }

    else break;
    }
    if(inicial.x != final.x || inicial.y != final.y) return -1;
    else return i;
}

//49)

int manDist(int x, int y, int x0, int y0) {
    int k;
    k=abs(x - x0) + abs(y - y0);
    return k;
}

int maiscentral (Posicao pos[], int N) {
    int minDist = manDist(pos[0].x,pos[0].y,0,0);
    int ans = 0; 
    int i;
    for(i=1; i<N; i++) {
        if(manDist(pos[i].x,pos[i].y,0,0) < minDist) {
            ans = i;
            minDist = manDist(pos[i].x,pos[i].y,0,0);
        }
    }
    return ans;
}


//50) dada uma posiçao e um array com N posiçoes, calcula quantas dessas posiçoes sao adjacentes a posiçao dada.

int vizinhos (Posicao p, Posicao pos[], int N){
    int ans = 0;
    int i;
    
    for(i=0; i<N; i++) {
        if(manDist(pos[i].x,pos[i].y,p.x,p.y) == 1) ans++;
    }
    return ans;
}

//Parte 2//

typedef struct lligada {
int valor;
struct lligada *prox;
} *LInt;

//1)calcula o comprimento de uma lista ligada.

int length (LInt l){
    LInt aux = l;
    int accum=0;
    while(aux!=NULL){
        accum++;
        aux = aux->prox;
    }
    return accum;
}

//2) liberta o espaço ocupado por uma lista.

void freeL (LInt l){
    LInt aux;
    aux = l;

    while (aux != NULL){
        aux = aux->prox;
        free(aux);
    }
}

//3) imprime no ecran os elementos de uma lista (um por linha).

void imprimeL (LInt l){
    LInt aux;
    aux = l;
    for (; aux != NULL; aux=aux->prox){ 
        printf ("%d\n", aux->valor);
    }
}

//4) inverte uma lista

LInt reverseL (LInt l){
    LInt aux=l;
    LInt aux2=l;
    int x=length(l);
    int *v=malloc (sizeof(int)*x);
    int j=0, i=0;
    
    while(aux!=NULL){
        v[i]=aux->valor;
        i++;
        aux=aux->prox;
    }
    l=aux2;
    
    for(j=i-1; j>=0; j--){
        aux2->valor=v[j];
        aux2=aux2->prox;
    }
    return l;
}

//5)insere ordenadamente um elemento numa lista ordenada

void insertOrd (LInt *l, int x){
    LInt new, *aux=l;
    new = malloc(sizeof(struct lligada));;
    new->valor = x;
    while ( *aux != NULL && (*aux)->valor < x)
    {
        aux = &((*aux)->prox);
    }
    new->prox = *aux;
    *aux = new;
}

//6)remove um elemento de uma lista ordenada. Retorna 1 caso o elemento a remover nao exista,0 no outro caso. 

int removeOneOrd (LInt *l, int x){
    int c=1;

    while((*l)&&(*l)->valor < x){
        l = &((*l)->prox);
    }

    if ((*l) != NULL && (*l)->valor == x){
        c=0;
        (*l)=(*l)->prox;
    }
    return c;
} 

//7) junta duas listas ordenadas (a e b) numa unica lista ordenada (r). 

void merge (LInt *r, LInt a, LInt b){
    while(a!=NULL && b!=NULL){
        if (a->valor < b->valor){
            (*r)=malloc (sizeof(struct lligada));
            (*r)->valor=a->valor;
            r=&((*r)->prox);
            a=a->prox;
        }
        else{
            (*r)=malloc (sizeof(struct lligada));
            (*r)->valor=b->valor;
            r=&((*r)->prox);
            b=b->prox;
        }
    }
    if (a==NULL)(*r)=b;
    else (*r)=a;
}

//8)dada uma lista ligada l e um inteiro x, parte a lista em duas (retornando os endereços dos primeiros
//elementos da lista em *mx e *Mx): uma com os elementos de l menores do que x e a outra com
//os restantes. Note que esta funçao nao devera criar copias dos elementos da lista.

void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
    while(l!=NULL){
        if (l->valor <  x){
            (*mx)=malloc (sizeof (struct lligada));
            (*mx)->valor=l->valor;
            mx=&((*mx)->prox);
        }

        else if(l->valor >= x){
            (*Mx)=malloc (sizeof (struct lligada));
            (*Mx)->valor=l->valor;
            Mx=&((*Mx)->prox); 
        }
        l=l->prox;
    }
    //(*mx)=(*Mx)=l;
}

//9) parte uma lista nao vazia *l a meio

LInt parteAmeio (LInt *l){
    LInt aux = *l;
    LInt nova;
    LInt *sitio;
    nova = *l;
    sitio = &nova;
    int x = length(aux);
    x /= 2;

    while (x>0){
        sitio = &((*sitio)->prox);
        (*l) = (*l)->prox;
        x--;
    }
    (*sitio)=NULL;
    return nova;
}

//10) remove todas as ocorrencias de um dado inteiro de uma lista, retornando o numero de celulas removidas.

int removeAll (LInt *l, int x){
    int accum=0;
    while((*l)!=NULL){
        if((*l)->valor == x){
            (*l) = (*l)->prox;
            accum++;
        }
        else{
            l = &((*l)->prox);
        }
    }
    return accum;
}

//11) remove os valores repetidos de uma lista (deixando apenas a primeira ocorrencia).

int removeDups (LInt *l){
    int accum=0;

    while((*l)!=NULL){
       int x = (*l)->valor;
       l = &&((*l)->prox);
       accum += removeAll(l, x);
    }
    return accum;
}

//12)remove (a primeira ocorrencia) o maior elemento de uma lista nao vazia, retornando o valor desse elemento.

int removeMaiorL (LInt *l){
    int maior = (*l)->valor;
    LInt *aux = l;

    while((*l)!=NULL){
        if((*l)->valor > maior){
            maior = (*l)->valor;
            sitio = l;
        }
        l = &((*l)->prox);
    }
    *sitio = (*sitio)->prox;
    return maior;
}

//13) remove o ultimo elemento de uma lista nao vazia (libertando o correspondente espaço).

void init (LInt *l){
    if((*l)==NULL);
    else{
        while((*l)->prox != NULL){
        l=&((*l)->prox);
        free((*l)->prox);
        (*l)=NULL;
        }
    }
} 

//14)

void appendL (LInt *l, int x){
    LInt elem = malloc (sizeof (struct lligada));

    while ((*l != NULL)){
        l = &((*l)->prox);
    }
    elem->valor = x;
    elem->prox = NULL;
    (*l) = elem;
}

//15) acrescenta a lista b à lista *a.

void concatL (LInt *a, LInt b){
    while((*a)){
        a = &((*a)->prox);
    }
    (*a) = b;
}

//16) cria uma nova lista ligada com os elementos pela ordem em que aparecem na lista argumento.

LInt cloneL (LInt l){
    LInt nova;

    while(l != NULL){
        nova = malloc (sizeof (struct lligada));
        nova->valor = l->valor;
        nova->prox = l->prox;
        l = l->prox;
    }
    nova = NULL;
    return nova
}

//17) cria uma nova lista ligada com os elementos por ordem inversa.

LInt newLInt (int v, LInt t){
    LInt new = (LInt) malloc (sizeof (struct lligada));
    
    if (new!=NULL) {
        new->valor = v;
        new->prox  = t;
    }
    return new;
}

LInt cloneRev (LInt l){
	LInt nova;
    int i=0;
    int j=0;
    int x = length(l);
    int *v = malloc (sizeof(int)*x);

    while(l){
        v[i] = l->valor;
        l = l->prox;
        i++;
    }

    for(j=0; j<i; j++){
        //<nova = malloc (sizeof (struct lligada));
        //nova->valor = v[j];
        nova = newLInt(v[j],nova);
    }

	return nova;
 }

 //18) calcula qual o maior valor armazenado numa lista nao vazia. 

 int maximo (LInt l) {
     int maximo = l->valor;
     l = l->prox;
     while(l){
         if(l->valor > maximo){
             maximo = l->valor;
         }
         l = l->prox;
     }
     return maximo;
 }

 //19)  apaga de l todos os nodos para alem do n-esimo (libertando o respectivo espaço)

 int take (int n, LInt *l){
    int i;
	for ( i = 0; i < n && (*l)!= NULL ; i++){
		l = &((*l)->prox);
	}
	if ( (*l) != NULL) 
		free (*l);
		(*l) = NULL;
	return i;
}

//20) apaga de l os n primeiros elementos da lista (libertando o respectivo espaço). 

int drop (int n, LInt *l){
    int i=0;
    int conta=0;

    for(i=0; i<n && (*l)!=NULL; i++){
        LInt aux = *l;
        *l = (*l)->prox;
        free(aux);
        conta++;
    }
    return conta;
}

//21) dada uma lista circular da como resultado o endereço do elemento da lista que esta N posiçoes a frente. 

LInt NForward (LInt l, int N){
    int i=N;

    for(i; i>0; i--){
        l = l->prox;
    }
    return l;
}

//22) dada uma lista l, preenche o array v com os elementos da lista.

int listToArray (LInt l, int v[], int N){
    int i=0;
    while(l && i<N){
        v[i] = l->valor;
        i++;
        l = l->prox;
    }
    return i;
}

//23) constroi uma lista com os elementos de um array

LInt arrayToList (int v[], int N){
    LInt nova = malloc (sizeof (struct lligada));
    if (N==0) return NULL;
    nova->valor = (*v);
    nova->prox = arrayToList(v+1, N-1);
    return nova;
}

//24) constroi uma nova lista de inteiros contendo as somas acumuladas da lista original

//nao me esta a dar??????
LInt somasAcL (LInt l){
    int accum=0;
    LInt aux;

    while(l){
        accum+=l->valor;
        aux = malloc (sizeof (struct lligada));
        aux->valor = accum;
        aux = aux->prox;
        l = l->prox;
    }
    return aux;
}

//25)elimina dessa lista todos os valores repetidos assegurando que o espaço de memoria correspondente aos nos removidos é correctamente libertado.

void remreps (LInt l){
    int rep = l->valor;
    LInt aux;
    LInt anterior = l;
    LInt proximo = l->prox;
    
    if (l==NULL)return;

    while (l != NULL){
        if (proximo->valor == x){
            aux=proximo;
            proximo = proximo->prox;
            free(aux);
            anterior->proximo=NULL;
        }
        else{
            x=proximo->valor;
            anterior->prox = proximo;
            anterior = anterior->prox;
            proximo = proximo->prox;
        }
    }
}
