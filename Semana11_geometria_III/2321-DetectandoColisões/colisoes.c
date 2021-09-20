#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))

typedef struct {int x, y;}Ponto;

int colisao(Ponto , Ponto , Ponto, Ponto );

int main(void)
{
	Ponto p1, p2, p3, p4;
	
	scanf("%d%d%d%d", &p1.x, &p1.y, &p2.x, &p2.y);
	scanf("%d%d%d%d", &p3.x, &p3.y, &p4.x, &p4.y);
	
	printf("%d\n", colisao(p1, p2, p3, p4) );
	
	return 0;
}

int colisao(Ponto p1, Ponto p2, Ponto p3, Ponto p4)
{

 if(	(MAX(p1.x,p2.x)>= MIN(p3.x,p4.x)) && 
 	(MAX(p3.x,p4.x)>=MIN(p1.x,p2.x)) && 
 	(MAX(p1.y,p2.y)>=MIN(p3.y,p4.y)) && 
 	(MAX(p3.y,p4.y)>=MIN(p1.y,p2.y)) ){
 	return 1;
 }
 else{
 	return 0;
 }
}
