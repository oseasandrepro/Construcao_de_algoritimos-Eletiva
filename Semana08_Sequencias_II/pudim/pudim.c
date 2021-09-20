#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a,b) ( (a)>(b)?(a):(b) )
#define SIZE 5003

int T[SIZE][SIZE];

void smc(char *str1, char* str2, int n, int m);

int main(void)
{
	
	char str1[SIZE];
	char str2[SIZE];
	int n, m;
	
	scanf("%[^\n]%*c", &str1[1]);
	scanf("%[^\n]%*c", &str2[1]);
	n = strlen(&str1[1]);
	m = strlen(&str2[1]);
	
	smc(str1, str2, n, m);
	
	printf("%d\n", T[n][m]);
	
	return 0;
}

void smc(char *str1, char* str2, int n, int m)
{
	int i, j;
	
	memset(T, 0, sizeof(T) );
		
	for( i = 1; i<=n; i++)
	{
		for( j = 1; j<=m; j++)
		{
			if(str1[i]==str2[j])
				T[i][j] = T[i-1][j-1] + 1;
			else
				T[i][j] = MAX(T[i-1][j], T[i][j-1]);
		}
	
	}
}
