#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) ( ((a)>(b))?(a):(b) )
#define MIN(a,b) ( ((a)<(b))?(a):(b) )

#define SIZE 6
typedef struct {int x, y;}Ponto;

Ponto pontos[SIZE];
Ponto  ch[SIZE];

int ConvexHull(Ponto *pol, int tp, Ponto *ch);
void OrdenaPontosy(Ponto *pol, int tp);
int PontoInteriorPoligonoConvexo(Ponto *pol, int n, Ponto q);
int SentidoPercurso(Ponto p1, Ponto p2, Ponto p3);
int PontoNoSegmento(Ponto p0, Ponto p1, Ponto p2);
void Quicksort(Ponto *pol, int e, int d);

int main(void)
{
	int nv, P;
	int i,s;
	Ponto ponto_0;
	
	
	for(i =1; i<=5; i++)
		scanf("%d%d", &pontos[i].x,&pontos[i].y);
	
	ponto_0.x = pontos[1].x; ponto_0.y = pontos[1].y;
	i = 1; s=0;
	for( i =1; i<=3; i++){
		s = (s || SentidoPercurso(ponto_0, pontos[i], pontos[i+1]) );
	}
	
	if( s == 0)
	{
		printf(" O>\n");
		printf("<| \n");
		printf("/ >\n");
	}
	else
	{
		
		nv = ConvexHull(&pontos[1], 4, ch);
		
		
		P = PontoInteriorPoligonoConvexo(ch, nv, pontos[5]);
		if( P )
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
	
	return 0;
}

int PontoNoSegmento(Ponto p0, Ponto p1, Ponto p2){
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

int ConvexHull(Ponto *pol, int tp, Ponto *ch)
{   int i,j,topo;
    OrdenaPontosy(pol, tp);
    /*Repete o ponto inicial no final*/
    ch[0]= pol[0]; pol[tp]= pol[0];
    j= 1;
    /* Elimina pontos iniciais colineares */
    while (SentidoPercurso(ch[0],pol[j],pol[j+1])==0) j++;
    ch[1]= pol[j];  ch[2]= pol[j+1];
    topo= 2;
    for (i= j+2; i<= tp; i++)
    {   while (SentidoPercurso(ch[topo-1], ch[topo], pol[i]) <= 0) topo--;
        topo++;  ch[topo]= pol[i];
    }
    return (topo);
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

int SentidoPercurso(Ponto p1, Ponto p2, Ponto p3)
{  long long a, b, c, d;
   a= p2.x - p1.x;  b= p3.y - p1.y;  c=p3.x - p1.x;  d=p2.y - p1.y;
   a = a*b-c*d;
   if (a > 0) return 1;
   else if (a < 0) return -1;
   else return 0;
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

