#include <stdio.h>
#include <stdlib.h>

#define VAZIA -10001
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define SIZE 10001

typedef struct {int x, y;}Ponto;
typedef struct {Ponto SupEsq, InfDir;}Retangulo;

Retangulo retangulos[SIZE];

Retangulo pontoRetangulo(Ponto p1, Ponto p2, Ponto p3, Ponto p4);
int colisao(Ponto p1, Ponto p2, Ponto p3, Ponto p4);


int main(void)
{
	Retangulo aux;
	int cont = 0;
	int N;
	while( 1 )
	{
		
		scanf("%d", &N);
		if( N==0){
			break;
		}
	
		aux.SupEsq.x = 0; aux.SupEsq.y = 0;
		aux.InfDir.x = 0; aux.InfDir.y = 0;
		printf("Teste %d\n", ++cont);
		
		for( int i = 1; i<=N; i++)
		{
			scanf("%d%d%d%d", &retangulos[i].SupEsq.x, &retangulos[i].SupEsq.y, 
					  &retangulos[i].InfDir.x, &retangulos[i].InfDir.y);
		}
		
		aux = retangulos[1];
		for( int i = 2; i<=N; i++)
		{
			if( colisao( aux.SupEsq, aux.InfDir, retangulos[i].SupEsq, retangulos[i].InfDir) )
			{
				aux = pontoRetangulo( aux.SupEsq, aux.InfDir, 
						      retangulos[i].SupEsq, retangulos[i].InfDir);
						      
			}
			else
			{
				aux.SupEsq.x = VAZIA; aux.SupEsq.y = VAZIA;
				aux.InfDir.x = VAZIA; aux.InfDir.y = VAZIA;
				break;
			}
		}
		if( (aux.SupEsq.x == VAZIA) && (aux.SupEsq.y == VAZIA) &&
		    (aux.InfDir.x == VAZIA) && (aux.InfDir.y== VAZIA) ){
		    printf("nenhum\n");
		}
		else
		{
			printf("%d %d %d %d\n", aux.SupEsq.x, aux.SupEsq.y, 
						aux.InfDir.x, aux.InfDir.y);
		}
		printf("\n");
	}
	return 0;
}

int colisao(Ponto p1, Ponto p2, Ponto p3, Ponto p4)
{

 if(	(MAX(p1.x,p2.x)>= MIN(p3.x,p4.x)) && 
 	(MAX(p3.x,p4.x)>=MIN(p1.x,p2.x))  && 
 	(MAX(p1.y,p2.y)>=MIN(p3.y,p4.y))  && 
 	(MAX(p3.y,p4.y)>=MIN(p1.y,p2.y)) ){
 	return 1;
 }
 else{
 	return 0;
 }
 
}

Retangulo pontoRetangulo(Ponto p1, Ponto p2, Ponto p3, Ponto p4)
{
	Retangulo re;
	
	re.SupEsq.x = MAX(p1.x, p3.x);
	re.SupEsq.y = MIN(p1.y, p3.y);
	
	re.InfDir.x = MIN(p2.x, p4.x);
	re.InfDir.y = MAX(p2.y, p4.y);
	
	return re;
}
