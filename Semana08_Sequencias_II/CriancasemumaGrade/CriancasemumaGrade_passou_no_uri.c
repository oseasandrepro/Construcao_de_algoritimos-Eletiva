#include <stdio.h>

#define SIZE_GRADE 21
#define MAX(a,b) ( (a)>(b)?(a):(b) )
#define SIZE 5003

int T[SIZE][SIZE];

void smc(char *str1, char* str2, int n, int m);


char grade[SIZE_GRADE][SIZE_GRADE];

void Setar(char* str, int N, char G[][SIZE_GRADE], int X, int Y);

int main(void)
{
	char str1[SIZE_GRADE];
	char str2[SIZE_GRADE];
	int t; int H, W;
	int N, X, Y; int n, m;

	scanf("%d", &t);
	for( int i = 1; i<=t; i++)
	{
	
	
		scanf("%d%d%*c", &H, &W);
		for( int j = 1; j<=H; j++)
			for(int k = 1; k<=W; k++)
				scanf(" %c ", &grade[j][k]);
		
		scanf("%d%d%d%*c", &N, &X, &Y);
		n = N+1;
		char ch, j;
		str1[1] = grade[X][Y];
		for(j = 2; j<=n; j++)
		{
			scanf("%c", &ch);
			if( ch == 'N')
				str1[j] = grade[--X][Y];
			else if( ch == 'S')
				str1[j] = grade[++X][Y];
			if( ch == 'W')
				str1[j] = grade[X][--Y];
			if( ch == 'E')
				str1[j] = grade[X][++Y];
				
		}
		str1[j] = '\0';
		
		scanf("%d%d%d%*c", &N, &X, &Y);
		m = N+1;
		str2[1] = grade[X][Y];
		for(j = 2; j<=m; j++)
		{
			scanf("%c", &ch);
			if( ch == 'N')
				str2[j] = grade[--X][Y];
			else if( ch == 'S')
				str2[j] = grade[++X][Y];
			if( ch == 'W')
				str2[j] = grade[X][--Y];
			if( ch == 'E')
				str2[j] = grade[X][++Y];
				
		}
		str2[j] = '\0';
		
		smc(str1, str2, n,   m);
		

		printf("Case %d: %d %d\n", i, n-T[n][m], m-T[n][m]);
		
	}
}

void smc(char *str1, char* str2, int n, int m)
{
	int i, j;
	
	for(i = 0; i<=n; i++)
		T[i][0] = 0;
	for(j = 0; j<=m; j++)
		T[0][j] = 0;
		
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
