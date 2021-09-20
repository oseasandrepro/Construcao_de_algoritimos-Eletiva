#include <stdio.h>


typedef struct{ 
	int d; 
	int x; 
	int y;
} ret;
int a, b; ret r;

int C[31700000], P[4000001], rq, nf, np, nd;
long long int n, q, F[50], D[10000];

int PotMod(long long a, long long b, long long n);
ret MDCE(int a, int b, ret ra);

void GeraCrivo (int n);
void GeraPrimos (int rq);
void Fatora (long long int q);

int main(void)
{
	long long N, E, D, C, T, M;
	int d, y;
	
	
	n = 1000000000000000;
	rq = sqrt(n)+1;  
    	GeraCrivo(rq);
   	GeraPrimos(rq);
	
	scanf("%lld %lld %lld", &N, &E, &C);
	
	/*Fatorar N*/
	Fatora(N);
	/*printf("p = %d, q = %d\n", F[1], F[2]);*/
	
	/*Cacular T*/
	T = (F[1]-1) * (F[2]-1);
	
	/*printf("T = %lld\n", T);*/
	
	//Calcular D, o inverso modular de E relativo a T
	r = MDCE(E, T, r);
	D = (r.x<0)?r.x+T:r.x;
	
	
	/*printf("D = %lld\n", D);*/
	
	
	/*Computar M = C^D mod N*/
	M = PotMod(C, D, N);
	
	printf("%lld\n",M);
	
	
	return 0;
}

int PotMod(long long a, long long b, long long n)
{
    long long int m, c, d, rb[101];  int i, j;
    m= b;   i= 101;
    while (m > 0){
        rb[--i]= m % 2;   m= m /2;
    }
    c= 0; d= 1;
    for(j=i; j<= 100; j++)
    {
        d= (d*d) % n;    c= 2*c;
        if (rb[j] == 1){
            d= (d*a) % n;   c++;
        }
    }
    return (int) d;
}

ret MDCE(int a, int b, ret ra)
{   int xx;
    if (b == 0)
    {   ra.d = a;  ra.x = 1;  ra.y = 0;
    }
    else{   ra = MDCE(b, a % b, ra);
        xx = ra.x;  ra.x = ra.y;  ra.y = xx - (a / b)*ra.y;
    }    
    return ra;          
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
     for (i=2; i<=rq; i++)
         if (C[i]==i)  P[++np]= i;
}

void Fatora (long long int q)
{ 	int i;   
	int rq = sqrt(q)+1;
	 nf = 0; 
     for (i=1; i <=np; i++)
     {   while((q % P[i]) == 0)
         {   F[++nf] = P[i];  q = q/P[i];
         }
         if (q == 1 || P[i] >= rq) break;  
     }
     if (q != 1) F[++nf] = q;
}
