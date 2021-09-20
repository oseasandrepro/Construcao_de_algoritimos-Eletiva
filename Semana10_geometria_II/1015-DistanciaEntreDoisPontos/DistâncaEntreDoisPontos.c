#include <stdio.h>
#include <math.h>

typedef struct { double x, y; }ponto;

double DistPontos(ponto p1,ponto p2){
    return (sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)));
}

int main(void)
{
	ponto p1,p2;
	
	scanf("%lf%lf", &p1.x, &p1.y);
	scanf("%lf%lf", &p2.x, &p2.y);
	
	printf("%.4f\n", DistPontos(p1, p2) ); 
	return 0;
}


