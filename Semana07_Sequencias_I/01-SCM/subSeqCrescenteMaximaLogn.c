#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define BUFFER_SIZE	100001
#define SIZE	10

int S[SIZE] = { 0, 10, 2, 15, 8, 20, 16, 10, 5, 20};
int T[BUFFER_SIZE];
int O[BUFFER_SIZE];
int R[BUFFER_SIZE];
int K;

void obterTodos(int* S, int* O, int n, int k, int *R, int m);
int BuscaBinaria(int* T, int ini, int fim, int x);
void SCM(int* S, int n);
void obter(int* S, int* O, int n, int k, int *R);

void Debugando(int testeLogico);

int main(void)
{
	K = 0;
	memset(R, -1, sizeof(R) );
	printf("<");
	for( int i = 1; i<SIZE; i++)
		printf("%4d", S[i]);
	printf(">\n");
	
	SCM(S, SIZE-1);
	
	printf("Quantidade de elementos da maior subsequencia crescente maxima:");
	printf("%d\n", K );
	
	//obter(S, O, SIZE-1, K, R);
	printf("Possiveis sequências:\n");
	obterTodos(S, O, SIZE-1, K, R, INT_MAX);
	
	return 0;
}

void SCM(int* S, int n)
{
	K = 1; 
	T[1] = S[1]; 
	O[1] = 1;
	for( int i = 2; i<=n; i++)
	{
		
			
		if( S[i] > T[K] )
		{
			K = K + 1;
			T[K] = S[i];
			O[i] = K;
		}
		else
		{
			int j = BuscaBinaria(T, 1, K, S[i]);
			T[j] = S[i];
			O[i] = j;
		}
	}
}

void obter(int* S, int* O, int n, int k, int *R)
{
	int m, i, j;
	m = INT_MAX;
	i = n; j = k;
	while( j > 0)
	{
		if( (O[i] == j) && (S[i] < m)  )
		{
			R[j] = S[i];
			j = j -1; m = S[i];
		}
		i = i -1;
	}
	
}

void obterTodos(int* S, int* O, int n, int k, int *R, int m)
{
	if(k==0)
	{
		for( int i = 1; i<=K; i++)
			printf("%4d", R[i]);	
		printf("\n");
	}
	else
	{
	
		
		for( int i = n; i>=1; i--)
		{
			
			if( (O[i] == k) && (S[i] < m)){
				R[k] = S[i];
				obterTodos(S, O, n-1, k-1, R, S[i]);
			}
		}
	}
	
}

int BuscaBinaria(int* T, int ini, int fim, int x)
{
	if( ini > fim)
		return ini;
	else
	{
		int m = (ini+fim)/2;
		if( T[m] < x)
			return BuscaBinaria(T, m+1, fim, x);
		else
			return BuscaBinaria(T, ini, m-1, x);
	}
}
