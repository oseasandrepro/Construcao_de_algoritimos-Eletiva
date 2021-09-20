#include <stdio.h>

int C[31700000], P[4000001], rq, nf, np, nd;
long long int n, q, F[50], D[10000];
int teste;


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
{    np=0; 
	int i;
     for (i=2; i<=rq; i++)
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

int totienteDeEuler(int n)
{
	int e;
	int tot;
	int index;
	int p,q;
	int i, j;
	
	e = 1;
	tot = 1;
	Fatora(n);
	
	
	for(i = 1; i<=nf; i++)
	{
		if( F[i] == F[i-1])
			continue;
			
		e = 0; index = i;
		
		while( (index<=nf) && (F[index] == F[i]) ){
			e++;
			index += 1;
		}
		p = q = 1;
		for(j =0; j<e; j++)
			p *= F[i];
			
		for(j = 0; j<e-1; j++)
			q *= F[i];
	
		tot *= (p - q);
			
	}
	return tot;
}

int main(void)
{

	
	int i, numEstrelas;
	n = 1000000000000000;
	rq = sqrt(n)+1;  
    	GeraCrivo(rq);
    	GeraPrimos(rq);
    	
	
	while( scanf("%d", &i) == 1 )
	{
		numEstrelas = totienteDeEuler(i)/2;
		
		printf("%d\n", numEstrelas);
	}
	return 0;
}
