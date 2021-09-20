#include <stdio.h>

#define NMOD 1000000009
#define NA   6

typedef struct{ 
	int d; 
	int x; 
	int y;
}ret;
int a, b; 
ret r;
ret MDCE(int a, int b, ret ra);

int X = NMOD;

int P(int N);
int multMod(int a,  int b, int n);
int divMod(int a, int b,  int n);
int invMod(int b, int n);

int main(void)
{
	int N, resposta;
	resposta = 0;
	while(1)
	{
		scanf("%d", &N);
		if(N==0)
		{break;}
			
		resposta = divMod(P(N), NA, NMOD);
		
		printf("%d\n", resposta);
	}
	printf("\n");
	return 0;
}

int P(int N)
{
	if( N==0)
		return 1;
	else
		return multMod(N, P(N-1), NMOD);
}

int multMod(int a, int b,  int n)
{
	long long int la, lb;
	la=a; lb=b;
	return (la*lb)%n;
}
int divMod(int a, int b, int n)
{
	long long int la = a;
	long long int lb_linha = invMod(b,n);
	return (la*lb_linha)%n;
	
	
}

ret MDCE( int a, int b, ret ra)
{   int xx;
    if (b == 0)
    {   ra.d = a;  ra.x = 1;  ra.y = 0;
    }
    else{   ra = MDCE(b, a % b, ra);
        xx = ra.x;  ra.x = ra.y;  ra.y = xx - (a / b)*ra.y;
    }    
    return ra;          
}


int invMod(int b, int n)
{
	ret retorno;
	retorno = MDCE(b, n, r);
	return (retorno.x+NMOD)%NMOD;
}
