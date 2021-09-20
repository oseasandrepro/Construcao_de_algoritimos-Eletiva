#include <stdio.h>
#include <stdlib.h>


#define VAZIA -10001
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))

typedef struct{int x, y; }Ponto;
typedef struct {Ponto p1, p2;}Retangulo;

Retangulo pontoRetangulo(Ponto p1, Ponto p2, Ponto p3, Ponto p4);
int intersecao(Ponto p1, Ponto p2, Ponto p3, Ponto p4);

int main(void)
{

	Retangulo R_0, R_1, R;
	while(1)
	{
		int p,q;
		p = scanf("%d %d %d %d", &R_0.p1.x, &R_0.p1.y, &R_0.p2.x, &R_0.p2.y);
		q = scanf("%d %d %d %d", &R_1.p1.x, &R_1.p1.y, &R_1.p2.x, &R_1.p2.y);
		if( (p+q) != 8)
			break;
			
		if( intersecao(R_0.p1, R_0.p2, R_1.p1, R_1.p2) == 1 )
		{
			R = pontoRetangulo(R_0.p1, R_0.p2, R_1.p1, R_1.p2);
			int A = ((R.p2.x-R.p1.x)*(R.p2.y-R.p1.y));
			
			//printf("%d :", A);
			if(A>=1 && A<=10)
				printf("adequada\n");
			else if(A>10)
				printf("grande\n");
			else if( A==0 && ( (R.p2.x!=R.p1.x) || (R.p2.y!=R.p1.y) ) )
			{
				printf("linha\n");
			}
			else if( A==0 &&  (R.p2.x==R.p1.x) && (R.p2.y==R.p1.y) )
			{
				printf("ponto\n");
			}
		}
		else
		{
			printf("inexistente\n");	
		}
		
	}
	
	return 0;
}

int intersecao(Ponto p1, Ponto p2, Ponto p3, Ponto p4)
{

 if(	(MAX(p1.x,p2.x)>= MIN(p3.x,p4.x)) && 
 	(MAX(p3.x,p4.x)>=MIN(p1.x,p2.x))  && 
 	(MAX(p1.y,p2.y)>=MIN(p3.y,p4.y))  && 
 	(MAX(p3.y,p4.y)>=MIN(p1.y,p2.y)) ){
 		return 1;
 	}
 	else
 		return 0;
}

Retangulo pontoRetangulo(Ponto p1, Ponto p2, Ponto p3, Ponto p4)
{
	Retangulo re;
	
	re.p1.x = MAX(p1.x, p3.x);
	re.p1.y = MAX(p1.y, p3.y);
	
	re.p2.x = MIN(p2.x, p4.x);
	re.p2.y = MIN(p2.y, p4.y);
	
	return re;
}
