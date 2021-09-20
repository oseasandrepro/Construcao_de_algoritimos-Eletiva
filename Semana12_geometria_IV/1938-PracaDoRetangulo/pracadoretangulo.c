#include <stdio.h>
#include <stdlib.h>

#define SIZE 3001

typedef struct{
	int x, y;
}Ponto;

Ponto pontos[SIZE];

int compar(const void *, const void *);

int main(void)
{
	int N, i, j, k;
	int retangulo_valido = 0;
	int cont = 0;
	scanf("%d", &N);
	for( int i = 1; i<=N; i++)
		scanf("%d%d", &pontos[i].x, &pontos[i].y);
	
	//Ordenar por x
	qsort(&pontos[1], N, sizeof(Ponto), compar);
	
	/*for( int i = 1; i<=N; i++)
		printf("(%d,%d)\n", pontos[i].x, pontos[i].y);*/
		
	for(i = 1; i<=N-1; i++)
	{
		for(j = i+1; j<=N; j++)
		{
			retangulo_valido = 1;
			for(k = i+1; k<j; k++)
			{
			    if(j==k ){
			        continue;
			       }
			        
				if( ((pontos[k].y<pontos[i].y) && (pontos[k].y>pontos[j].y)) ||
				    ((pontos[k].y>pontos[i].y) && (pontos[k].y<pontos[j].y)) )
				{
				    	retangulo_valido = 0;
					break;
				}
			}
			if(retangulo_valido){
				cont++;
			}
		} 
	}
	printf("%d\n", cont);
	
	
	return 0;
}

int compar(const void *q1, const void *q2)
{
	Ponto* p1 = (Ponto*)q1;
	Ponto* p2 = (Ponto*)q2;
		
	return (p1->x)>(p2->x);
}
