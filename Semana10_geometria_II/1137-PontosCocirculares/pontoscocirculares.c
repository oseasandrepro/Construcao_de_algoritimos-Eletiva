#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

#define SIZE 101

const long double QZERO = 0.001;

typedef struct { long double x, y; }ponto;
typedef struct { long double a,b,c; }reta;
typedef struct { int ret; ponto p; }boolponto;

ponto pontos[SIZE];
int R[4];
int tabela[SIZE][SIZE][SIZE];
int U[SIZE];

boolponto PontoIntersecao(reta r1,reta r2);
reta PontosParaReta(ponto p1,ponto p2);
long double AreaTriangulo(ponto p1, ponto p2,ponto p3);
long double DistPontos(ponto p1,ponto p2);
int Paralelas(reta r1, reta r2);
int MesmaReta(reta r1,reta r2);
reta RetaPerpendicular(ponto p1, reta r1);
reta PontoTangenteParaReta(ponto p, long double tang);

void maxcocircular(ponto* P, int N, int d,int* R, int* U, int *refmax);
 
int main(void)
{
	int N;
	int max = 0;
	memset(tabela, 0, sizeof(tabela));
	memset(U, 0, sizeof(U));
	
	while( 1 )
	{
		
		scanf("%d", &N);
		if( N == 0)
			break;
		max = INT_MIN;
		
		for( int i = 1; i<=N; i++)
			scanf("%Lf%Lf", &pontos[i].x, &pontos[i].y);
			
		maxcocircular(pontos, N, 0, R, U, &max);
		
		printf("%d\n", max);
	}
}

void maxcocircular(ponto* P, int N, int d,int* R, int* U, int *refmax)
{
	if( (d==3) && (AreaTriangulo(P[R[2]],P[R[3]],P[R[1]])!=QZERO ) )
	{
		
		int cont = 0;
		long double r;
		boolponto pc;
		reta r1 = PontosParaReta(P[R[1]],P[R[2]]);
		reta r2 = PontosParaReta(P[R[1]],P[R[3]]);

		ponto p1,p2;
		
		//PONTO MÉDIO
		p1.x = (P[R[1]].x+P[R[2]].x)/2.0; p1.y = (P[R[1]].y+P[R[2]].y)/2.0;
		p2.x = (P[R[1]].x+P[R[3]].x)/2.0; p2.y = (P[R[1]].y+P[R[3]].y)/2.0;
		
		//MEDIATRIZ
		reta r4 = RetaPerpendicular(p1, r1);
		reta r5 = RetaPerpendicular(p2, r2);
		
		pc = PontoIntersecao(r4, r5);
		
		r = DistPontos(P[R[1]], pc.p);
	
		for( int i = 1; i<=N; i++)
		{
				if( fabsl(DistPontos(pc.p, P[i])-r)<=QZERO )
					cont = cont+1;
		}
		if( cont>(*refmax))
			(*refmax) = cont;
	}
	else
	{
		for( int i = 1; i<=N; i++)
		{
			if(!U[i] && (R[d]<i || d==0))
			{
				R[d+1] = i;
				U[i] = 1;
				maxcocircular(P, N, d+1, R, U, refmax);
				U[i] = 0;
			}
		}
	}
}

long double AreaTriangulo(ponto p1, ponto p2,ponto p3)
{
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

boolponto PontoIntersecao(reta r1,reta r2){
    boolponto bp;
    bp.ret = 1;
    if (Paralelas(r1,r2) || MesmaReta(r1,r2)) bp.ret = 0;
    else{
        bp.p.x = (r2.b*r1.c-r1.b*r2.c)/(r2.a*r1.b-r1.a*r2.b);
        if (fabsl(r1.b)>QZERO)
            bp.p.y = -(r1.a*bp.p.x + r1.c)/r1.b;
        else
            bp.p.y = -(r2.a*bp.p.x + r2.c)/r2.b;
        if (fabsl(bp.p.x) < QZERO) bp.p.x = 0;   // Para evitar -0.00
        if (fabsl(bp.p.y) < QZERO) bp.p.y = 0;   // Para evitar -0.00   
    }
    return bp;
}

long double DistPontos(ponto p1,ponto p2){
    return (sqrtl((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)));
}

int Paralelas(reta r1, reta r2){
    return ((fabsl(r1.a-r2.a)<=QZERO) && (fabsl(r1.b-r2.b)<=QZERO));
}

int MesmaReta(reta r1,reta r2){
    return (Paralelas(r1,r2) && (abs(r1.c-r2.c)<=QZERO));
}

reta RetaPerpendicular(ponto p1, reta r1){
    ponto p2; reta r2;
    if (fabsl(r1.b)<= QZERO){
        r2.a = 0;  r2.b = 1;  r2.c = -p1.y;
    }
    else if (fabsl(r1.a)<= QZERO){
        r2.a = 1;  r2.b = 0;  r2.c = -p1.x;
    }
    else r2 = PontoTangenteParaReta(p1,1/r1.a);
    return r2;
}

reta PontoTangenteParaReta(ponto p, long double tang){
    reta r;
    r.a=-tang;  r.b=1;  r.c=-(r.a*p.x + r.b*p.y);
    return r;
}
