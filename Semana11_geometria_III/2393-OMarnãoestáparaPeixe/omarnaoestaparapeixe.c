#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 101

typedef struct{int x, y; }Ponto;
typedef struct {Ponto p1, p2;}Rede;

Rede redes[SIZE];
int plano[SIZE][SIZE];

int main(void)
{
	int N;
	int soma = 0;
	memset(plano, 0, sizeof(plano));
	
	scanf("%d", &N);
	for( int i = 1; i<=N; i++){
		scanf("%d%d%d%d", &redes[i].p1.x, &redes[i].p2.x,
				  &redes[i].p1.y, &redes[i].p2.y );
	}
	
	for( int i = 1; i<=N; i++)
	{
		for( int j = redes[i].p1.y; j<=redes[i].p2.y-1; j++)
		{
			for( int k = redes[i].p1.x; k<=redes[i].p2.x-1; k++)
			{
				plano[j][k] = 1;
			}
		}
	}
	
	for( int j = 1; j<=100; j++)
		for( int k = 1; k<=100; k++)
			soma += plano[j][k];
	printf("%d\n", soma);
		
	return 0;
}
