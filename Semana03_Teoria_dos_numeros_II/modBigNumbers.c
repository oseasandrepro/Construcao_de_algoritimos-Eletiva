#include <stdio.h>

#define SIZE 1000
unsigned char buffer[SIZE];

int bigmodulo(char* vetor, int n, int N);

int main(void)
{
	int n;
	scanf("%s %d", buffer, &n);
	
	printf("%d\n", bigmodulo(buffer, strlen(buffer), n) );
	return 0;
}


int bigmodulo(char* vetor, int n, int N)
{
	int m = 0;
	int i, di;

	for( i = 0; i<n; i++)
	{
		di = vetor[i]-'0';
		m = (m*10+ di) % N;
	}
	return m;
}
