#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MIN(a,b) ( ((a)<(b))? (a):(b) )
#define MAX(a,b) ( ((a)>(b))? (a):(b) )

#define SIZE 7
typedef struct {int x, y;}Ponto;

double max;
Ponto pp[SIZE];
Ponto ch[SIZE];
int R[SIZE];
int U[SIZE];
Ponto aux[SIZE];

void OrdenaPontosy(Ponto *pol, int tp);
void OrdenaPontosPorx(Ponto *pol, int np);
int SentidoPercurso(Ponto p1, Ponto p2, Ponto p3);
void Quicksort(Ponto *pol, int e, int d);
int PontoNoSegmento(Ponto p0, Ponto p1, Ponto p2);
int comparax(const void* p1, const void* p2);
int PontoInteriorPoligonoConvexo(Ponto *pol, int n, Ponto q);

int ConvexHull(Ponto *pol, int tp, Ponto *ch);
double AreaPoligono(Ponto *pol, int n);
void combpoligonos(Ponto* P, int N, int d, int* R, int* U);

int main(void)
{
	memset(U, 0, sizeof(U));	
		
	while(1)
	{	
		max = INT_MIN;
		for(int i = 1; i<=5; i++)
			scanf("%d%d%*c", &pp[i].x, &pp[i].y);
			
		if(	((pp[1].x == 0) && (pp[1].y==0)) && 
			((pp[2].x == 0) && (pp[2].y==0)) &&
			((pp[3].x == 0) && (pp[3].y==0)) &&
			((pp[4].x == 0) && (pp[4].y==0)) &&
			((pp[5].x == 0) && (pp[5].y==0)) ){
				break;
			}
					
		combpoligonos(pp, 5, 0, R, U);
		
		printf("%f\n", max);
	}
	
	return 0;
}


void combpoligonos(Ponto* P, int N, int d, int* R, int* U)
{
	if( (d==3) )
	{
		int k = 0;
		int i, nv;
		double A;

		for( int i = 0; i<3; i++){
			aux[i] = P[R[i+1]];
		}
		
		nv = ConvexHull(aux, 3, ch);
		
		for(int i = 0; i<=3; i++){
			printf("(%d,%d)\n", ch[i].x, ch[i].y);
		}
		printf("\n");
		 
		/*A = AreaPoligono(ch, nv);
		 
		if( A > max){
		 	max = A;
		}*/
		 
		 
		
	}
	else
	{
		for( int i = 1; i<=N; i++)
		{
			if( !U[i] && (R[d]<i || d==0) )
			{
				R[d+1] = i;
				U[i] = 1;
				combpoligonos(P, N, d+1, R, U);
				U[i] = 0;
			}
		}
	}
}

int ConvexHull(Ponto *pol, int tp, Ponto *ch)
{   int i,j,topo;
    OrdenaPontosy(pol, tp);
    /*Repete o ponto inicial no final*/
    ch[0] = pol[0]; 
    pol[tp] = pol[0];
    j= 1;
    /* Elimina pontos iniciais colineares */
    while (SentidoPercurso(ch[0],pol[j],pol[j+1])==0) j++;
    ch[1]= pol[j];  
    ch[2]= pol[j+1];
    topo = 2;
    for (i= j+2; i<= tp; i++)
    {   while (SentidoPercurso(ch[topo-1], ch[topo], pol[i]) <= 0) topo--;
        topo++;  ch[topo] = pol[i];
    }
   
    return (topo);
}



double AreaPoligono(Ponto *pol, int n)
{  long long c;  int i;
   pol[n] = pol[0];
   c = 0;  
   for (i=0; i<n; i++)
   {
   	c = c + pol[i].x*pol[i+1].y - pol[i+1].x*pol[i].y;
   }
   return c/2.0;
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

void OrdenaPontosy(Ponto *pol, int tp)
/*   Ordena pontos por ângulo, escolhendo como referência o ponto mais embaixo e mais
   à esquerda. */
{  int i,m;  Ponto p;
   m=0;
   for (i=1;i<tp;i++) 
      if ((pol[i].y < pol[m].y)||(pol[i].y==pol[m].y)&&(pol[i].x<pol[m].x)) m=i;
   p=pol[0];  pol[0]=pol[m];  pol[m]=p;
   Quicksort(pol, 1,tp-1);
}    

void Quicksort(Ponto *pol, int e, int d)
// O ponto 0 fica fixo na ordenação, pois tem o menor x
{  int i,j,k;  Ponto t,r;  long long d0, d1, d2;
   if (d > e)
   {  i=e;  j=d;  t=pol[(e+d)/2];
      d1= pol[0].x-t.x;  d2= pol[0].y-t.y;  d0=d1*d1+d2*d2;
      while(i<=j)
      {  while(1)
         {  k=SentidoPercurso(pol[0],pol[i],t);
            if (k==1) i++;
            else if (k==0)
            {  d1= pol[0].x-pol[i].x;  d2= pol[0].y-pol[i].y;  d1= d1*d1+d2*d2;
               if (d1 < d0) i++;
               else break;
            }   
            else break;
         }
         while(1)
         {  k=SentidoPercurso(pol[0],t,pol[j]);
            if (k==1) j--;
            else if (k==0)
            {  d1= pol[0].x-pol[j].x;  d2= pol[0].y-pol[j].y;  d1= d1*d1+d2*d2;
               if (d0 < d1) j--;
               else break;
            }
            else break;
         }  
         if (i<=j) {r=pol[i];  pol[i]=pol[j];  pol[j]=r;  i++; j--;}
      }
      Quicksort(pol, e,j);  Quicksort(pol, i,d);
   }
}      
