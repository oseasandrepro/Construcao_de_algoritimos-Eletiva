#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <limits.h>

#define PI acos(-1)
#define SIZE 101
const double QZERO = 0.000000001;

typedef struct { double x, y; }ponto;
typedef struct { double a,b,c; }reta;
typedef struct {ponto pc; double raio; }circulo;
typedef struct { reta r1,r2; }duasretas;
typedef struct { ponto p1,p2; }doispontos;
typedef struct { int ret; ponto p; }boolponto;

ponto Pontos[SIZE];
int U[SIZE];
int R[3];

double AreaTriangulo(ponto p1, ponto p2,ponto p3);
reta PontosParaReta(ponto p1,ponto p2);
reta RetaPerpendicular(ponto p1, reta r1);

void menorDiferencaBk(ponto* P, int N, int d, int* R, int* U, double *refmin);

int main(void)
{
	int N;
	double min;
	while( 1 )
	{
		scanf("%d", &N);
		if( N==0)
			break;
		min = DBL_MAX;
		for( int i=1; i<=N; i++)
			scanf("%lf%lf", &Pontos[i].x, &Pontos[i].y);
		
		menorDiferencaBk(Pontos, N, 0, R, U, &min);
		
		printf("%.3f\n", min);
	}
	return 0;
}

void menorDiferencaBk(ponto* P, int N, int d, int* R, int* U, double *refmin)
{
	if( d==2 )
	{
		double segmaD = 0.0;
		double segmaS = 0.0;
		double A, d;
		reta r = PontosParaReta(P[R[1]],P[R[2]]);
		
		for( int i = 1; i<=N; i++)
		{
			if(!U[i])
			{
				A = AreaTriangulo(P[R[1]], P[R[2]],  P[i]);
				
				d = fabs((r.a*P[i].x)+(r.b*P[i].y)+r.c) / sqrt((r.a*r.a)+(r.b*r.b));
				if( A > QZERO )
					segmaS = segmaS+fabs(d);
				else
					segmaD = segmaD+fabs(d);
			}
		}
		double dif = fabs(segmaS - segmaD);
		if( (*refmin)>dif )
			(*refmin) = dif;
			
	}
	else
	{
		for( int i = 1; i<=N; i++)
		{
			if(!U[i] && (R[d]<i || d==0))
			{
				R[d+1] = i;
				U[i] = 1;
				menorDiferencaBk(P, N, d+1, R, U, refmin);
				U[i] = 0;
			}
		}
	}
}

double AreaTriangulo(ponto p1, ponto p2,ponto p3){
     return (0.5*(p1.x*(p2.y-p3.y)-p2.x*(p1.y-p3.y)+p3.x*(p1.y-p2.y)));
}

reta PontosParaReta(ponto p1,ponto p2){
    reta r;
    if (p1.x==p2.x){ r.a=1; r.b =0; r.c=-p1.x;}
    else{ r.b=1; r.a=-(p1.y-p2.y)/(p1.x-p2.x);
          r.c=-(r.a*p1.x)-(r.b*p1.y);
    }
    return r;
}

