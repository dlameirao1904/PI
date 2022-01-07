#include <stdio.h>

//1
//Diga, justificando, qual o output de cada um dos seguintes excertos de codigo C.

//1)
int alinea1 ()
{
int x, y;
x = 3; y = x+1;
x = x*y; y = x + y;
printf("%d %d\n", x, y);
  return 0;
}
//output :  12 , 16

//2) 
int alinea2 () 
{
int x, y;
x = 0;
scanf ("%d", &y);
printf ("%d %d\n", x, y);
  return 0;
}
//output : o , valor introduzido para o y

//3)
int alinea3 ()
{
char a, b, c;
a = 'A'; b = ' '; c = '0';
printf ("%c %d\n", a, a);
a = a+1; c = c+2;
printf ("%c %d %c %d\n", a, a, c, c);
c = a + b;
printf ("%c %d\n", c, c);
return 0;
} 
//output : A 95 B 66 2 50 b 98

//4)
int alinea4 ()
{
int x, y;
x = 200; y = 100;
x = x+y; y = x-y; x = x-y;
printf ("%d %d\n", x, y);
return 0;
} 
//output : 100 , 200

//2
//a)
int doisa ()
{
int x, y;
x = 3; y = 5;
if (x > y)
y = 6;
printf ("%d %d\n", x, y);
return 0;
}
//output : 3 , 5

//b)
int doisb () 
{
int x, y;
x = y = 0;
while (x != 11) {
x = x+1; y += x;
}
printf ("%d %d\n", x, y);
return 0;
}
//output : 11 , 66

//c)
int doisc ()
{
int i;
for (i=0; (i<20) ; i++)
if (i%2 == 0) putchar ('_');
else putchar ('#');
return 0;
}
// output : _#_#_#_#_#_#_#_#_#_#

/*
//d)
void f (int n) {
while (n>0) {
if (n%2 == 0) putchar ('0');
else putchar ('1');
n = n/2;
}
putchar ('\n');
}
int main () {
int i;
for (i=0;(i<16);i++)
f (i);
return 0;
}
/*
1
01
11
001
101
011
111
0001
1001
0101
1101
0011
1011
0111
1111
*/

//3
//a)
int quadrado ()
{
	int i, l;
	for (i=0; (i<5); i++){
	for (l=0; (l<5); l++){
	putchar ('#');
	}
	putchar ('\n');
	}
    return 0;
}

//b)
void xadrez () 
{
	int i, l;
	for (i=0; (i<5); i++){
		for (l=0; (l<5); l++){
			if (i%2 == 0) {
				if (l%2==0) putchar ('#');
			    else putchar ('_');}
			else {
				if (l%2 == 0) putchar ('_');
				else putchar ('#');

			}
}
putchar ('\n');
}
}


//c)
void triangulo1 (int n)
{
int i, j;

	for (i=1; i<n; i++){
		for (j=0; j<i; j++) putchar ('#');
		putchar ('\n');
}
    for (i=n; i>0; i--){
    	for (j=i; j>0; j--) putchar ('#');
    	putchar ('\n');
    }
}



void triangulo2 (int n)
{
	int d = 1;
	int i, j, k;

	for (i=n-1; i>-1; i--)
	{
		for (j=0; j<i; j++) putchar (' ');
		for (k=0; k<d; k++) putchar ('#');
		putchar ('\n'); 
	    d = d+2;
	} 
}




int main () 
{
	triangulo1 (5);
	return 0;
}



