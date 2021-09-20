#include <stdio.h>
#include <string.h>

#define NMOD	100000007
#define TAM	10000+1

typedef struct{ 
	int d; 
	int x; 
	int y;
}ret;
int a, b; 
ret r;
ret MDCE(int a, int b, ret ra);

int R[TAM];
char S[TAM];
int N,K;

void PreencherTabelaDeRepeticao(void);
void ordenar(char* str);

int P(int N);
int Pr(int N, int* R, int K);

int multMod(int a, int  b, int n);
int divMod(int a, int b,  int n);
int invMod(int b, int n);


int main(void)
{
	while(1)
	{
		scanf("%s", S);
		if( S[0] == '0' ){
			break;
		}
			
		N = strlen(S); K = 0;
		
		ordenar(S);
		PreencherTabelaDeRepeticao();
		
		//printf("%s\n%d %d\n", S, N, K);
		
		printf("%d\n", Pr(N,R,K) );
	}
	return 0;
}

void ordenar(char* str)
{
	int i, j;
	char aux; 
	
	for( i = 1; i<N; i++)
	{
		j = i;
		aux = str[i];
		while( str[j-1] > aux ){
			str[j] = str[j-1];
			j = j-1;
		}
		str[j] = aux;
	}
}
void PreencherTabelaDeRepeticao(void)
{
	int indexr = 0;
	//ordenar(S);
	int i = 1;
	int cont = 1;
	char escolhido = S[0];
	
	while( S[i] != '\0' )
	{
		if(S[i] == escolhido)
			cont++;
		else
		{
			if(cont>1){
				R[indexr++] = cont;
				K++;
			}
			cont = 1;
			escolhido = S[i];
			
		}
		i++;
	}
	if(cont>1){
		R[indexr++] = cont;
		K++;
	}
}

int P(int N)
{
	if( N==0)
		return 1;
	else
		return multMod(N, P(N-1), NMOD);
}

int Pr(int N, int* R, int K)
{
	if( K == 0){
		return P(N);
	}
	else if( R[K-1] == 0)
	{
		return Pr(N, R, K-1);
	}
	else
	{
		int aux = R[K-1];
		
		//printf("%d %d\n", N, aux);
		//printf("%f\n", ((double)N/aux));
		
		R[K-1] = aux-1;
		int V = multMod( Pr(N-1, R, K), N, NMOD );
		return divMod(V, aux, NMOD);
	}
}

int multMod(int a, int b, int n)
{
	unsigned long long int la, lb;
	la=a; lb=b;
	return (la*lb)%n;
}

int divMod(int a, int b, int n)
{
	unsigned long long int la = a;
	unsigned long long int lb_linha = invMod(b,n);
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
