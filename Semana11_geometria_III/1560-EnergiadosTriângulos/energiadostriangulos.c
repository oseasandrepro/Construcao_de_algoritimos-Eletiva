#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a,b) ( ((a)<(b))? (a):(b) )
#define MAX(a,b) ( ((a)>(b))? (a):(b) )

#define SIZE 101
typedef struct {int x, y;}Ponto;

int total;
int N, M;
Ponto pp[SIZE];
Ponto pb[SIZE];
int R[SIZE];
int U[SIZE];
Ponto aux[3];

void OrdenaPontosPorx(Ponto *pol, int np);
int SentidoPercurso(Ponto p1, Ponto p2, Ponto p3);
void Quicksort(Ponto *pol, int e, int d);
void combtriangulos(Ponto* P, int N, int d, int* R, int* U);
int PontoNoSegmento(Ponto p0, Ponto p1, Ponto p2);
int comparax(const void* p1, const void* p2);
int PontoInteriorPoligonoConvexo(Ponto *pol, int n, Ponto q);

int main(void)
{
	memset(U, 0, sizeof(U));	
		
	while(1)
	{	
		if( scanf("%d%d", &N, &M) < 2 )
			break;
		
		total = 0;
		for(int i = 1; i<=N; i++)
			scanf("%d%d", &pp[i].x, &pp[i].y);
			
		for(int i = 1; i<=M; i++)
			scanf("%d%d", &pb[i].x, &pb[i].y);
			
		
		OrdenaPontosPorx(&pp[1], N);
		
		combtriangulos(pp, N, 0, R, U);
		
		printf("%d\n", total);
	}
	
	return 0;
}


void combtriangulos(Ponto* P, int N, int d, int* R, int* U)
{
	if( (d==3) )
	{
		int k = 0;

		for( int i = 0; i<3; i++)
			aux[i] = P[R[i+1]];
		
		for(int i = 1; i<=M; i++)
		{
			if(	( (pb[i].x>=aux[1].x) && (pb[i].x<=aux[2].x) ) || 
				( (pb[i].x>=aux[0].x) && (pb[i].x<=aux[1].x) ) ||
				( (pb[i].x>=aux[2].x) && (pb[i].x<=aux[0].x) ) ) {
			int q = PontoInteriorPoligonoConvexo(aux, 3, pb[i]);
			if( q ) { k++; }
			}
		}
		total += (k*k);
	}
	else
	{
		for( int i = 1; i<=N; i++)
		{
			if( !U[i] && (R[d]<i || d==0) )
			{
				R[d+1] = i;
				U[i] = 1;
				combtriangulos(P, N, d+1, R, U);
				U[i] = 0;
			}
		}
	}
}


int PontoInteriorPoligonoConvexo(Ponto *pol, int n, Ponto q)
{
	
	int t, t1, i; 
	
	pol[n] = pol[0];
	t = SentidoPercurso(q, pol[n-1], pol[0]);
	
	if (t==0)
	    return PontoNoSegmento(q, pol[n-1], pol[0]);
	
    	for (i=1; i<=n-1; i++)
    	{
		t1 = SentidoPercurso(q, pol[i-1], pol[i]);
			if (t1==0)
		    		return PontoNoSegmento(q, pol[i-1], pol[i]);        
			if (t != t1)
				return 0;
	}
	
	return 1;
}

int SentidoPercurso(Ponto p1, Ponto p2, Ponto p3)
{  
	long long a, b, c, d;
	a= p2.x - p1.x;  b= p3.y - p1.y;  c=p3.x - p1.x;  d=p2.y - p1.y;
	a = a*b-c*d;
	if (a > 0) return 1;
	else if (a < 0) return -1;
	else return 0;
}

int PontoNoSegmento(Ponto p0, Ponto p1, Ponto p2)
{
    return (SentidoPercurso(p0, p1, p2) == 0 ) &&
           (p0.x >= MIN(p1.x, p2.x)) && (p0.x <= MAX(p1.x, p2.x)) &&
           (p0.y >= MIN(p1.y, p2.y)) && (p0.y <= MAX(p1.y, p2.y));
}


int comparax(const void* p1, const void* p2)
{
    Ponto* q1 = (Ponto*)p1;
    Ponto* q2 = (Ponto*)p2;
    
    if (q1->x == q2->x)
    {
    	return (q1->y < q2->y);
    }
    return (q1->x < q2->x);
}

void OrdenaPontosPorx(Ponto *pol, int np)
{
	qsort(pol, np, sizeof(Ponto), comparax);
}
