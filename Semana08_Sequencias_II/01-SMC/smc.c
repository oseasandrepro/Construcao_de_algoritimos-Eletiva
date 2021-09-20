#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a,b) ( (a)>(b)?(a):(b) )
#define SIZE 5003

int T[SIZE][SIZE];
char str[SIZE];
char str1[SIZE];
char str2[SIZE];
int indice;
int n, m;

void smc(char *str1, char* str2, int n, int m);
void gerar(int i, int j, int k);

int main(void)
{
	
	scanf("%[^\n]%*c", &str1[1]);
	scanf("%[^\n]%*c", &str2[1]);
	n = strlen(&str1[1]);
	m = strlen(&str2[1]);
	
	smc(str1, str2, n, m);
	
	printf("%d\n", T[n][m]);
	
	/*indice = T[n][m];
	str[indice+1] = '\0';*/
	
	
	
	//gerar_todas(n, m, T[n][m]);
	
	/*gerar(n, m, T[n][m]);
	printf("%s\n", &str[1]);*/
	
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

void gerar(int i, int j, int k)
{
	if( k>0 )
	{
		if( str1[i] == str2[j] )
		{
			str[indice] = str1[i];
			indice--;
			gerar(i-1, j-1, k-1);
		}
		else if(T[i-1][j] == k)
		{
			gerar(i-1, j, k);
		}
		else
		{
			gerar(i, j-1, k);
		}
	}
}
