#include <stdio.h>
#include <string.h>

#define MIN(a,b) ( ( (a) < (b) ) ? (a) : (b) )
#define SIZE 102

float  D[SIZE][SIZE];

char seque1[SIZE][103];
char seque2[SIZE][103];

int n, m;
int T, M, N;
float R;

void distanciaEdicao(int n, int m);

int main(void)
{
	float valor;
	char str[1001];
	
	scanf("%d", &T);
	for( int i = 1; i<=T; i++)
	{
		scanf("%f", &R);
		
		scanf("%d", &M);
		for(int j = 1; j<=M; j++)
			scanf("%s%*c", seque1[j]);
		
		scanf("%d", &N);	
		for(int j = 1; j<=N; j++)
			scanf("%s%*c", seque2[j]);
			
		
		
		distanciaEdicao(M, N);
		
		valor = R * (D[M][N]/60.0f);
		sprintf(str, "%.2f", valor);
		int k = 0;
		while( str[k] != '\0' ){
			if( str[k]=='.')
				str[k] = ',';
			k++;
		}
		
		printf("Caso #%d: R$ %s\n", i, str);
	}
	return 0;
}


void distanciaEdicao(int n, int m)
{
	/*
		30s Deleção
		60s substituição
		150s Inserção
	*/
	int i,j;
	for( i = 0; i<=n; i++)
		D[i][0] = i*30;
		
	for( j = 0; j<=m; j++)
		D[0][j] = j*150;
		
	for( i = 1; i<=n; i++)
	{
		for( j = 1; j<=m; j++)
		{
			if( strcmp(seque1[i],seque2[j]) == 0 )
			{
				D[i][j] = D[i-1][j-1];
			}
			else
			{
				D[i][j] = MIN( MIN(D[i-1][j-1]+60 , D[i-1][j]+30), D[i][j-1]+150 );
			}
			
		}
	}
	
}

