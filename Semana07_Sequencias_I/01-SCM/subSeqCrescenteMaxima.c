#include <stdio.h>
#define MAX(a,b) ( (a)>(b)?(a):(b) )
#define SIZE	8

int S[SIZE] = { 0, 10, 2, 15, 3, 20, 4, 20};

int SCM_t(int *S, int n);
int SCM(int *S, int n);

int main(void)
{
	printf("<");
	for( int i = 1; i<SIZE; i++)
		printf("%4d", S[i]);
	printf(">\n");
	printf("Quantidade de elementos da maior subsequencia crescente maxima:");
	printf("%d\n", SCM(S, SIZE-1) );
	return 0;
}

int SCM_t(int *S, int n)
{
	//Retorna o comprimento da subsequêcia crescente
	//Máxima que temina em S[n]
	int m = 1;
	for( int i = 1; i<=n-1; i++)
	{
		if( S[i] < S[n] )
			m = MAX( m, SCM_t(S, i)+1 );
	}
	return m;
}

int SCM(int *S, int n)
{
	//retorna o comptimento da sebsequência crescente
	//Maxima contida em S[1..n]
	int m = 0;
	for( int i = 1; i<=n; i++){
		m = MAX( m, SCM_t(S,i) );
	}
	
	return m;
	
}
