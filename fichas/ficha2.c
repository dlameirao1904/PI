//ficha 2

#include <stdio.h>
#include <math.h>
//1
float multInt1 (int n, float m){

	int b; 
	float r=0;

	for (b=0; b<n; b++)
	{
		r=r+m;
	}

	return r;
}

//2
float multInt2 (int n, float m){

	int i;
	float r = 0;

	for (i=n; i>0; i=i/2){

		if ((n%2) != 0){

			r = r + m;
		}

		m = m * 2;
	}

	return r;
}

//3

int mdc1 (int a, int b){

	int i, r;

	if (a<b){

		for  (i=1; i<=b; i++){

			if (a%i==0 && b%i==0) r=i;
		}
	}

	else {

		for (i=1; i<=a; i++){

			if (a%i==0 && b%i==0) r=i;
		}
	}

	return r;
}

//4
int divisor2 (int a, int b){

	while (a != 0 && b != 0){

		if (a > b) a = a - b;
		else if (a < b) b = b - a;
		else return a;
	}

	if (a == 0 && b != 0) return b;
	else return a;
}

//5
int maxdivisor3 (int a, int b){

	while (a != 0 && b != 0){

		if (a > b) a = a % b;
		else if (a < b) b = b % a;
		else return a; 
	}

	if (a == 0 && b != 0) return b;
	else return a;
}

//6
//a)
int fib1 (int n){

	if (n==1 || n==2) return 1;
	else return fib1(n-1) + fib1(n-2);
}

//b)
int fibonacci2 (int n){

	int i;
	int f=1;
	int a[n];
	int b[n];

	for (i=0; i<n; i++){

		a[i] = b[i] = 0; 
	}

	for (i=1; i<n; i++){

		a[i] = b[i-1];
		b[i] = f;
		f = a[i] + b[i];
	}

	return f;
}

int main (){
    int j;

    j = fibonacci2 (5);
    printf("%d\n", j);
	return 0;
}







