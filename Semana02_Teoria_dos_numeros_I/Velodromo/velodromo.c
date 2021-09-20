#include <stdio.h>

int C[10000001], P[1000001], F[50], D[1000], n, q, nf, np, nd;

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
void GeraPrimos (int n)
{    np=0;
     int i;
     for (i=2; i<=n; i++)
         if (C[i]==i)  P[++np]= i;
}

int TestaPrimo (int q)
{    return (C[q] == q);
}

void Fatora (int q)
{    nf = 0;
     while(q != 1)
     {   F[++nf] = C[q];  q = q/C[q];
     }
}

void Divisores(int q)
{    int nda, k, i, j;
     F[0] = 1;  nd = 1;  D[1] = 1;  nda = 1;
     for (i=1; i<=nf; i++)
     {   if (F[i] == F[i-1]) k = k*F[i];
         else
         {    nda = nd;  k = F[i];
         }
         for (j=1; j<=nda; j++)
             D[++nd] = k*D[j];
     }
}

int MDC(int a, int b)
{   if (b == 0) return a;
    else return MDC(b, a % b);
}

int MMC(int a, int b){
	return a*(b/MDC(a,b));
}

void ordenaInsercao(int *V, int n)
{
   	int i, j;
	for( i=2; i<=n; i++)
	{
		j = i;
		V[0] = V[i];
		while( (V[j-1] > V[0]) )
		{
			
			V[j] = V[j-1]; 
		    	j    = j-1;
		}
		V[j] = V[0];
	}
}

int main(void)
{
	/*número máximo que pode ser testado - até 10.000.000*/
	n = 10000000; 
	int T, A, B;
	int C[1000];
	int nc, j;
	int K, W;
	
	 GeraCrivo(n);
    	 GeraPrimos(n);
    	 
	while( 1 )
	{
		scanf("%d %d %d", &T, &A, &B);
		if( T==0 && A==0 && B==0 )
			break;
		Fatora(T);
		Divisores(T);
		
		K = MMC(A,B);
		nc = 0;
		for(j=1; j<=nd; j++)
		{
			W = MMC(K, D[j]);
			if ( W == T)
			{
				nc++;
				C[nc] = D[j];
			}
		}
		ordenaInsercao(C,nc);
		for(j = 1; j<=nc; j++)
			(j<nc) ? printf("%d ", C[j]) : printf("%d\n", C[j]);
				
	}
	return 0;
}
