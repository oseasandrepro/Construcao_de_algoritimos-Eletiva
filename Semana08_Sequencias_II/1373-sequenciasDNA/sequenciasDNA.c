#include <stdio.h>
#include <string.h>

#define MAX(a,b) ( (a)>(b)?(a):(b) )
#define SIZE 5003

int T[SIZE][SIZE];

char str1[1002];
char str2[1002];

void smc(char *str1, char* str2, int n, int m, int k);


int main(void)
{

	int k, n, m;
	while( 1 )
	{
		scanf("%d", &k);
		if( k == 0)
			break;
			
		scanf("%[^\n]%*c", &str1[1]);
		scanf("%[^\n]%*c", &str2[1]);
		n = strlen(&str1[1]);
		m = strlen(&str2[1]);
		
		smc(str1, str2, n, m, k);
		
		for(int i = 0; i<=n; i++)
		{
			for(int  j = 0; j<=m; j++)
			{
				printf("%4d", T[i][j]);
			}
			printf("\n");
	
		}
	
		printf("%d\n", T[n][m]);
	}
	return 0;
}

void smc(char *str1, char* str2, int n, int m, int k)
{
	int i, j;
	
	memset(T, 0, sizeof(T) );
		
	for( i = 1; i<=n; i++)
	{
		for( j = 1; j<=m; j++)
		{
			if(str1[i]==str2[j])
			{
				int c, z, v;
				c = 0; 
				z = i-1; 
				v = j-1;
				
				while( (z>=0 && v>=0) && (str1[z] == str2[v]) ){
					c++;
					z = z-1; 
					v = v-1;
				}
				
				if( c >= k )
					T[i][j] = c+1;
				else
					T[i][j] = 0;
			}
			else
			{
				T[i][j] = MAX(T[i-1][j], T[i][j-1]);
			}
		}
	
	}
}
