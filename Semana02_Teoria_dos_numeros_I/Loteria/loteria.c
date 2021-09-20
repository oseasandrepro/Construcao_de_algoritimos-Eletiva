#include <stdio.h>

#define SIZE 2500

int matriz[SIZE][SIZE];

/*retorna  Cn,k(combinacao de n tomados k a k*/
double comb(double n, int k)
 {
    if (n == k) 
    	return 1;
    else 
    	return comb(n - 1, k) * n / (n -(double)k);
}

int Heprimo(int n)
{
    int i;
    	if(n==0 || n==1)
    		return 0;
	for(i = 2; i <= sqrt(n); i++ ){
		if( (n % i) == 0 ){
			return 0;
		}
	}
	return 1;
}

double contEscolhasEmLinhas(int mat[SIZE][SIZE], int N, int M, int K)
{
	int cont, i, j;
	double escolhas;
	
	if( M ==1 )
	{
		if( K == 1)
			return 1;
		else /*K > 1*/
			return 0;
	}
	else
	{
		escolhas = 0;
		for(i = 0; i<N; i++)
		{
			cont = 0;
			for(j = 0; j<M; j++){
				if(mat[i][j] == 1)
					cont++;
			}
			if( K == 1)
				escolhas+=cont;
			else if( cont>=K)
				escolhas += comb(cont,K);
			
		}
		return escolhas;
	}
}

double contEscolhasEmColunas(int mat[SIZE][SIZE], int N, int M, int K)
{
	int cont, i, j;
	double escolhas;
	if(N == 1 )
	{
		if( K == 1)
			return 1;
		else /*K > 1*/
			return 0;
	}
	else
	{
		escolhas = 0;
		for(i = 0; i<M; i++)
		{
			cont = 0;
			for(j = 0; j<N; j++){
				cont +=mat[j][i];
			}
			if( K == 1)
				escolhas+=cont;
			else if( cont>=K)
				escolhas += comb(cont,K);
			
		}
		return escolhas;
	}
}


int main(void)
{
	int linha, coluna;
	double NumEscolhas = 0;
	int N, M, K, i;

	N = M = K = 0;
	while(1)
	{
		NumEscolhas = 0;
		scanf("%d %d %d", &N, &M, &K);
		if( N==0 && M==0 && K==0)
			break;	
				
		for( linha = 0; linha<N; linha++)
		{
			for(coluna = 0; coluna<M; coluna++){
				if( Heprimo( linha*M+coluna ) )
					matriz[linha][coluna] = 0;
				else
					matriz[linha][coluna] = 1;
			}
		}
		
		if( N==1 && M==1 && K==1)
		{
			NumEscolhas = 1;
		}
		else if ( K<= N || K<=M)
		{	
		
			NumEscolhas = contEscolhasEmLinhas(matriz, N, M, K);
			NumEscolhas += contEscolhasEmColunas(matriz, N, M, K);
		}
					
		
		printf("%.lf\n", NumEscolhas);
	}
	
	return 0;
}
