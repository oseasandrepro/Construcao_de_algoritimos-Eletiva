#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE	500001

int S[BUFFER_SIZE];
int T[BUFFER_SIZE];
int O[BUFFER_SIZE];
int K;

int BuscaBinaria(int* T, int ini, int fim, int x);
void SCM(int* S, int n);

int main(void)
{
	int N;
	
	while( 1 )
	{
		
		if( scanf("%d", &N) < 1)
			break;
		
		for( int i = 1; i<=N; i++)
			scanf("%d", &S[i]);
			
		SCM(S, N);
		
		printf("%d\n", K);
	}
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
