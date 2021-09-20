#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>


#define PI acos(-1)
#define	QZERO	0.000000001
#define MIN(a,b) ((a)<(b))?(a):(b)


typedef struct { double x, y; }ponto;
typedef struct { double a,b,c; }reta;
typedef struct {ponto pc; double raio; }circulo;
typedef struct { reta r1,r2; }duasretas;
typedef struct { ponto p1,p2; }doispontos;
typedef struct { int ret; ponto p; }boolponto;

typedef struct { double yi,xf,yf; }aleta_;

aleta_ aletas[1001];

double computarDiamentroMinino(aleta_* ale, int N, int L, int H);
double distanciaPontoReta(ponto P, reta r);
ponto PontoMaisProximo(ponto p1, reta r1);
double DistPontos(ponto p1,ponto p2);
boolponto PontoIntersecao(reta r1,reta r2);
reta RetaParalela(ponto p1, reta r1);
int Paralelas(reta r1, reta r2);
reta PontosParaReta(ponto p1,ponto p2);
reta PontoTangenteParaReta(ponto p, double tang);
int MesmaReta(reta r1,reta r2);

int main(void)
{

	int N, L, H;
	while(1)
	{
		if( scanf("%d", &N) < 1)
			break;
		scanf("%d%d", &L, &H);
		for( int i = 1; i<=N; i++)
			scanf("%lf%lf%lf", &aletas[i].yi,  &aletas[i].xf,  &aletas[i].yf);
		
		printf("%.2f\n", computarDiamentroMinino(aletas, N, L, H));
		
	}
	return 0;
}

double computarDiamentroMinino(aleta_* ale, int N, int L, int H)
{
	int P = 0;
	double minimo = DBL_MAX;
	double d, d1, d2;
	ponto p, p1, p2;
	reta r;
	
	p1.x = 0; p1.y = 0; p2.x = 0;	p2.y = H;
	reta haste1 = PontosParaReta(p1,p2);
	p1.x = L; p1.y = 0; p2.x = H; p2.y = H;
	reta haste2 = PontosParaReta(p1,p2);
	
	for( int i = 1; i<=N; i++)
	{
		
		p.x = ale[i].xf; p.y = ale[i].yf; //final da aleta corrente i
		
		if((i%2)==0)
			d1 = distanciaPontoReta(p, haste1);
		else
			d1 = distanciaPontoReta(p, haste2);
		if( i<N)
		{
		
			if( (i%2)==0 ){
				p1.x = 0; p1.y = ale[i+1].yi; p2.x = ale[i+1].xf; p2.y = ale[i+1].yf;
			}
			else{
				p1.x = L; p1.y =ale[i+1].yi; p2.x = ale[i+1].xf; p2.y = ale[i+1].yf;
			}
				
			r = PontosParaReta(p1, p2); //aleta_i+1
			ponto pp = PontoMaisProximo(p, r); //ponto da aletata_i+1 mais proximo do final da aleta corrente i
			//Verificar se pp está no segmento
			if( (i%2) != 0 )
				P = pp.x>p2.x;
			else
				P = pp.x<p2.x;
			if( P )
			{
				
				d2 = distanciaPontoReta(p, r);
				//printf("está na reta\n");
			}	
			else
			{
				d2 = DistPontos(p, pp);
				//printf("não está na reta\n");
			}
				
				
			
			
			minimo  = MIN(minimo, MIN(d1,d2));
		}
		else
			minimo = MIN(minimo, d1);
	}
	
	return minimo;
}

reta PontosParaReta(ponto p1,ponto p2){
    reta r;
    if (p1.x==p2.x){ r.a=1; r.b =0; r.c=-p1.x;}
    else{ r.b=1; r.a=-(p1.y-p2.y)/(p1.x-p2.x);
          r.c=-(r.a*p1.x)-(r.b*p1.y);
    }
    return r;
}

double distanciaPontoReta(ponto P, reta r)
{
	double d;
	d = fabs((r.a*P.x)+(r.b*P.y)+r.c) / sqrt((r.a*r.a)+(r.b*r.b));
	return d;
}

ponto PontoMaisProximo(ponto p1, reta r1){
    ponto p2;  boolponto bp;
    reta r2;
    if (fabs(r1.b)<= QZERO){
        p2.x = -r1.c;  p2.y = p1.y;
    }
    else if (fabs(r1.a)<= QZERO){
        p2.x = p1.x;  p2.y = -r1.c;
    }
    else{
        r2 = PontoTangenteParaReta(p1,1/r1.a);
        bp = PontoIntersecao(r1,r2);
        if (!bp.ret) printf("Erro\n");
        p2 = bp.p;
    }
    return p2;
}

double DistPontos(ponto p1,ponto p2){
    return (sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)));
}

boolponto PontoIntersecao(reta r1,reta r2){
    boolponto bp;
    bp.ret = 1;
    if (Paralelas(r1,r2) || MesmaReta(r1,r2)) bp.ret = 0;
    else{
        bp.p.x = (r2.b*r1.c-r1.b*r2.c)/(r2.a*r1.b-r1.a*r2.b);
        if (fabs(r1.b)>QZERO)
            bp.p.y = -(r1.a*bp.p.x + r1.c)/r1.b;
        else
            bp.p.y = -(r2.a*bp.p.x + r2.c)/r2.b;
        if (fabs(bp.p.x) < QZERO) bp.p.x = 0;   // Para evitar -0.00
        if (fabs(bp.p.y) < QZERO) bp.p.y = 0;   // Para evitar -0.00   
    }
    return bp;
}

reta RetaParalela(ponto p1, reta r1){
    reta r2;
    r2.a = r1.a;  r2.b = r1.b;  r2.c = -(r1.a*p1.x + r1.b*p1.y);
    return r2;
}

int Paralelas(reta r1, reta r2){
    return ((fabs(r1.a-r2.a)<=QZERO) && (fabs(r1.b-r2.b)<=QZERO));
}

reta PontoTangenteParaReta(ponto p, double tang){
    reta r;
    r.a=-tang;  r.b=1;  r.c=-(r.a*p.x + r.b*p.y);
    return r;
}

int MesmaReta(reta r1,reta r2){
    return (Paralelas(r1,r2) && (abs(r1.c-r2.c)<=QZERO));
}
