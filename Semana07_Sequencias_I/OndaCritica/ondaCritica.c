#include <stdio.h>

#define MAX(a,b) ( (a)>(b)?(a):(b) )
#define TAM 1001

typedef struct{
	int x;
	int y;
}Ponto;

Ponto P[TAM];

void ordenar(Ponto* P, int n);

int computar_Ci(Ponto* P, int n);
int computar_Bi(Ponto* P, int n);
int SCM(Ponto* P, int n);

int main(void)
{
	int n;
	
	while( 1 )
	{
		if( scanf("%d", &n)< 1 )
			break;
			
		for( int i = 1; i<=n; i++)
			scanf("%d%d", &P[i].x, &P[i].y);
		//Ordenanção em relação a x
		ordenar(P, n);
		
		/*for( int i = 1; i<=n; i++)
			printf("%d %d\n", P[i].x, P[i].y);*/
			
		printf("%d\n", SCM(P, n) );
	}
	
	return 0;
}

int computar_Ci(Ponto* P, int n)
{
	int m = 1;
	for( int i = 1; i<=n; i++)
	{
		if( (P[i].x < P[n].x) && (P[i].y==P[n].y-2) )
			m = MAX( computar_Bi(P, i) + 1, m);
	}
	
	return m;
}

int computar_Bi(Ponto* P, int n)
{
	int m = 1;
	for( int i = 1; i<=n; i++)
	{
		if( (P[i].x<P[n].x) && (P[i].y==P[n].y+2) )
			m = MAX(computar_Ci(P, i) + 1, m );
	}
	
	return m;
}

int SCM(Ponto *P, int n)
{
	int m = 0;
	for( int i = 1; i<=n; i++){
		m = MAX( computar_Bi(P, i), computar_Ci(P, i) );
	}
	
	return m;
	
}

void ordenar(Ponto* P, int n)
{
	int i, j;
	Ponto aux;
	
	for( i = 2; i<=n; i++)
	{
		j = i;
		aux = P[i];
		while( P[j-1].x > aux.x )
		{
			P[j] = P[j-1];
			j = j-1;
		}
		
		P[j] = aux;
	}
}
