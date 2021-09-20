#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) ( ((a)>(b))?(a):(b) )
#define MIN(a,b) ( ((a)<(b))?(a):(b) )

#define SIZE 6
typedef struct {int x, y;}Ponto;

Ponto pontos[SIZE];
int R[SIZE];
int U[SIZE];
Ponto aux[3];

int SentidoPercurso(Ponto p1, Ponto p2, Ponto p3);
int PoligonoConvexo(Ponto *pol, int n);
int PontoNoSegmento(Ponto p0, Ponto p1, Ponto p2);
int PontoInteriorPoligonoConvexo(Ponto *pol, int n, Ponto q);
int comparax(const void* p1, const void* p2);
void OrdenaPontosPorx(Ponto *pol, int np);

void CaminhoFechado(Ponto *pol, int tp);
void OrdenaPontosy(Ponto *pol, int tp);
void OrdenaPontosx(Ponto *pol, int tp);
void Quicksort(Ponto *pol, int e, int d);


int combtriangulos(Ponto* P, int N, int d, int* R, int* U);


int main(void)
{
	int i,s;
	Ponto ponto_0;
	
	
	for(i =1; i<=5; i++)
		scanf("%d%d", &pontos[i].x,&pontos[i].y);
	
	ponto_0.x = pontos[1].x; ponto_0.y = pontos[1].y;
	i = 1; s=0;
	for( i =1; i<=3; i++)
	{
		s = (s || SentidoPercurso(ponto_0, pontos[i], pontos[i+1]) );
	}
	
	if( s != 0)
	{
		CaminhoFechado(&pontos[1], 4);
		if( PoligonoConvexo(&pontos[1], 4) )
		{
			if( PontoInteriorPoligonoConvexo(&pontos[1], 4, pontos[5]) )
			{
				printf("\\O/\n");
				printf(" | \n");
				printf("/ \\\n");
			}
			else
			{
				printf(" O>\n");
				printf("<| \n");
				printf("/ >\n");
			}
		}
		else
		{
			OrdenaPontosPorx(&pontos[1], 4);
			
			if( combtriangulos(pontos, 4, 0, R, U) )
			{
				printf("\\O/\n");
				printf(" | \n");
				printf("/ \\\n");
			}
			else
			{
				printf(" O>\n");
				printf("<| \n");
				printf("/ >\n");
			}
		}
	}
	else
	{
		printf("\\O/\n");
		printf(" | \n");
		printf("/ \\\n");
	}
	
	return 0;
}

int combtriangulos(Ponto* P, int N, int d, int* R, int* U)
{
	if( (d==3) )
	{
		for( int i = 0; i<3; i++)
			aux[i] = P[R[i+1]];
			
		CaminhoFechado(aux, 3);
		
		if(	( (pontos[5].x>=pontos[5].x) && (pontos[5].x<=aux[2].x) ) || 
				( (pontos[5].x>=aux[0].x) && (pontos[5].x<=aux[1].x) ) ||
				( (pontos[5].x>=aux[2].x) && (pontos[5].x<=aux[0].x) ) ) {
				
				int q = PontoInteriorPoligonoConvexo(aux, 3, pontos[5]);
				if(q){return 1;}
			}
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
	return 0;
}

void CaminhoFechado(Ponto *pol, int tp)
/* Ordena pontos e, ao final da ordenação, se houver pontos colineares com
   o ponto inicial, no final do vetor, a ordem dos pontos colineares é invertida. */
{  int i,m;  Ponto p;
   OrdenaPontosx(pol, tp);
   i = tp-1;  while ((i>0)&&(SentidoPercurso(pol[0],pol[i-1],pol[i])==0)) i--;
   for (m=i; m<(i+tp)/2;m++) {p=pol[m]; pol[m]=pol[tp-1-m+i]; pol[tp-1-m+i]=p;}
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
void OrdenaPontosx(Ponto *pol, int tp)
/* Ordena pontos por ângulo, escolhendo como referência o ponto mais à esquerda e mais
   embaixo. */
{  int i,m;  Ponto p;
   m=0;
   for (i=1;i<tp;i++) 
      if ((pol[i].x < pol[m].x)||(pol[i].x==pol[m].x)&&(pol[i].y<pol[m].y)) m=i;
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


int PoligonoConvexo(Ponto *pol, int n)
{
	int s, i; 
	s = SentidoPercurso(pol[n-2], pol[n-1], pol[0]);
	if (s != SentidoPercurso(pol[n-1], pol[0], pol[1]))
		return 0;
    for (i=0; i<n-2; i++) if (s != SentidoPercurso(pol[i], pol[i+1], pol[i+2]))
		return 0;
	return 1;
}

int PontoNoSegmento(Ponto p0, Ponto p1, Ponto p2)
{
    return SentidoPercurso(p0, p1, p2) == 0 &&
           p0.x >= MIN(p1.x, p2.x) && p0.x <= MAX(p1.x, p2.x) &&
           p0.y >= MIN(p1.y, p2.y) && p0.y <= MAX(p1.y, p2.y);
}

int PontoInteriorPoligonoConvexo(Ponto *pol, int n, Ponto q)
{
	int t, t1, i; 
	pol[n] = pol[0];
	t = SentidoPercurso(q, pol[n-1], pol[0]);
	if (t==0)
	    return PontoNoSegmento(q, pol[n-1], pol[0]);
    for (i=1; i<=n-1; i++){
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
   if (a > 0) 
   	return 1;
   else if (a < 0) 
   	return -1;
   else 
   	return 0;
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
