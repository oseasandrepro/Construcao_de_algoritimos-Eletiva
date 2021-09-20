#include <stdio.h>
#include <string.h>

#define MIN(a,b) ( ( (a) < (b) ) ? (a) : (b) )
#define SIZE 10002

int D[SIZE][SIZE];

char str1[SIZE];
char str2[SIZE];

int n, m;

void distanciaEdicao(int n, int m);

int main(void)
{
	scanf("%[^\n]%*c", &str1[1]);
	scanf("%[^\n]%*c", &str2[1]);
	
	n = strlen(&str1[1]);
	m = strlen(&str2[1]);
	
	distanciaEdicao(n, m );
	
	printf("%d\n", D[n][m] );
	return 0;
}


void distanciaEdicao(int n, int m)
{
	int i,j;
	for( i = 0; i<=n; i++)
		D[i][0] = i;
		
	for( j = 0; j<=m; j++)
		D[0][j] = j;
		
	for( i = 1; i<=n; i++)
	{
		for( j = 1; j<=m; j++)
		{
			if(str1[i] == str2[j] )
				D[i][j] = D[i-1][j-1];
			else
			{
				D[i][j] = 1+ MIN( MIN(D[i-1][j-1], D[i-1][j]) , D[i][j-1] );
			}
			
		}
	}
}

