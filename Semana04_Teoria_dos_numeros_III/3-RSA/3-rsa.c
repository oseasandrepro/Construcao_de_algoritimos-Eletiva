#include <stdio.h>
#include <string.h>
#include <math.h>

int C[31700000], P[4000001];
int rq, nf, np, nd;
long long int n, q, F[50];

void GeraCrivo (int n);
void GeraPrimos (int rq);
void Fatora (long long int q);

int main(void)
{
	char str[18];
	int  decimal;
	long double x, p, q, r, div;
	int i;
	n = 1000000000000000;
	rq = sqrt(n)+1;  
    	GeraCrivo(rq);
   	GeraPrimos(rq);
   	
   	while( 1 )
   	{
   		scanf("%Lf", &x);
   		if( x == 0)
   			break;
	   	/*achar p*/
	   	/*
	   	for (i=1; i <=np; i++)
	     	{
	     		div = x/P[i];
	     		sprintf(str, "%.5Lf", div);
	     		sscanf(str, "%*[^.].%d",  &decimal);
	     		if( decimal == 0){
	     			p = P[i];
	     			break;
	     		}  
	     	}*/
	     	
	     	Fatora(x);
	     	p = F[1]; q = F[2]; r = F[3];
	   	
	   	printf("%.0Lf = %.0Lf x %.0Lf x %.0Lf\n",x, p, q, r);
	 }
	return 0;
}

void GeraCrivo (int n)
{    int i, rq, t, d;
     for (i=1; i<=n; i++)   C[i] = i;
     for (i=2; i<=n; i+=2)  C[i] = 2;
     rq = sqrt(n);
     for (i=3; i<=rq; i+=2)
     {   if (C[i] == i)
         {   t = i*i;  d = i+i;
             while(t<=n)
             {   if (C[t] == t) C[t] = i;
                 t = t+d;
             }
         }
     }
}
void GeraPrimos (int rq)
{
	int i;    
	np=0; 
     for (i=2; i<=(int)rq; i++)
         if (C[i]==i)  P[++np]= i;
}

void Fatora (long long int q)
{    int rq = sqrt(q)+1;
	int i;
	 nf = 0; 
     for (i=1; i <=np; i++)
     {   while((q % P[i]) == 0)
         {   F[++nf] = P[i];  q = q/P[i];
         }
         if (q == 1 || P[i] >= rq) break;  
     }
     if (q != 1) F[++nf] = q;
}
