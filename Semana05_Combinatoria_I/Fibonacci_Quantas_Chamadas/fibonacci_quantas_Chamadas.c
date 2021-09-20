#include <stdio.h>
#include <string.h>

#define TAM 10001
long int fibo[TAM];
long int numChamadas[TAM];

void fib(long int N);

int main(void)
{
	long int n;
	int x;
	scanf("%d", &x);
	for( int i = 0; i<x; i++)
	{
		scanf("%ld", &n);
		fib(n);
		printf("fib(%ld) = %ld calls = %ld\n",n, numChamadas[n]-1, fibo[n]);
	}
	
}

void fib(long int N)
{
	int i;
	memset(fibo,-1, sizeof(fibo));
	memset(numChamadas, 0, sizeof(numChamadas));
	
	fibo[0] = 0; fibo[1] = 1;
	numChamadas[0] = 1; numChamadas[1] = 1;
	
	for( i = 2; i<=N; i++)
	{
		fibo[i] = fibo[i-1] + fibo[i-2]; 
		numChamadas[i] = numChamadas[i-1] + numChamadas[i-2]+1;	
	}
}
