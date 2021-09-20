#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000001

typedef struct{
	double x, y;
}Ponto;

Ponto pontos[SIZE];

double DistPontos(Ponto p1,Ponto p2);

int main(void)
{
	Ponto partida;
	int N;
	double inicio_jogo, d;
	int assistio = 0;
	
	scanf("%lf%lf%d", &partida.x, &partida.y, &N);
	for( int i = 1; i<=N; i++)
	{
		scanf("%lf%lf%lf", &pontos[i].x, &pontos[i].y, &inicio_jogo);
		d = DistPontos(partida,pontos[i]);
		if( d<(inicio_jogo*inicio_jogo) )
		{
			(i==N)?printf("%d",i):printf("%d ", i);
			assistio = 1;
		}
	}
	if(!assistio)
		printf("-1");
	printf("\n");
	
	return 0;
}

double DistPontos(Ponto p1,Ponto p2){
    return ((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
