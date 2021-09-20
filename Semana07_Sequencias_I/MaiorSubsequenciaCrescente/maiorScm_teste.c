#include <stdio.h>

#define SIZE 601
#define SIZEL 601*601
#define MAX(a,b) ( (a)>(b)?(a):(b) )


int K, MAIOR;
int maiorMatrizLinha, maiorMatrizcoluna, maiorSubmatrizBi;

int H[SIZE][SIZE];
int V[SIZE][SIZE];

int T[SIZEL];

int matriz[SIZE][SIZE];

int BuscaBinaria(int T[SIZEL], int ini, int fim, int x);

void computar_tamanho_da_maior_submatriz(int l, int c);
void SCM_H(int l, int c);
void SCM_V(int l, int c);


int main(void)
{
	int i, j, M, N;
	
	while( 1 )
	{
		
		scanf("%d%d", &N,&M);
		if( N==0 && M==0)
			break;
		
		for( i = 1; i<=N; i++)
		{
			for( j = 1; j<=M; j++)
			{
				scanf("%d", &matriz[i][j]);
			}
		}
		
		SCM_H( N, M);
		SCM_V( N, M);
		

		computar_tamanho_da_maior_submatriz(N, M);
		
		printf("%d\n", MAIOR);
	}
	
	return 0;
}


void computar_tamanho_da_maior_submatriz( int l, int c)
{
	int Qc, Ql, i, j;
	int subl, subc;
	int cont, k;
	int flag, matrizLinha, matrizColuna;
	MAIOR = 0;
	maiorMatrizLinha = maiorMatrizcoluna = maiorSubmatrizBi = 0;
	for(i = 1; i<=l; i++)
	{
		for(j = 1; j<=c; j++)
		{
			Qc = H[i][j];//H guarda a quantidade de celulas que posso associar em uma linha(número de colunas)
			Ql = V[i][j];//V guarda a quantidade de celulas que posso associar em uma coluna(número de linhas)
			matrizLinha = matrizColuna = 0;
			
			/*if( i-(Ql-1) == i)//dectar matriz linha 
				matrizLinha = 1;
			if( j-(Qc-1) == j)//dectar matriz coluna
				matrizColuna = 1;
			
			if( (Qc==1 && Ql==1) && (maiorSubmatrizBi>1) )//caso de uma celula
				break;
			else if((!matrizLinha && !matrizColuna) && (Qc*Ql < maiorSubmatrizBi) )
				break;	
			else if( matrizLinha && (Qc < maiorMatrizLinha) )
				break;
			else if( matrizColuna && (Ql<maiorMatrizcoluna) )
				break;*/
			
			//Linearizar subsequencia e verificar se é crecente
			int ant = -100000000;
			cont = 0;
			flag = 1;
			for(subl = i-(Ql-1); subl<=i; subl++)
			{
				for(subc = j-(Qc-1); subc<=j; subc++)
				{
					if( ant > matriz[subl][subc] ){
						flag = 0;
						break;
					}else{
						cont++;
						ant = matriz[subl][subc];
					}
				}
			}
					
			//Atualizar maior subsequência
			if( flag )
			{
				MAIOR = MAX(MAIOR, cont);
				
				/*if( !matrizLinha && !matrizColuna)
					maiorSubmatrizBi = Ql*Qc;
					
				if( matrizLinha && (Qc > maiorMatrizLinha) )
					maiorMatrizLinha = Qc; 
					
				if( matrizColuna && (Ql > maiorMatrizcoluna) )
					maiorMatrizcoluna = Ql;*/
			}	
			
		}
	}
}

void SCM_H(int l, int c)
{
	for( int linha = 1; linha<=l; linha++)
	{
		K = 1; 
		T[1] = matriz[linha][1]; 
		H[linha][1] = 1;
		for( int i = 2; i<=c; i++)
		{
			
			if( matriz[linha][i] > T[K] )
			{
				
				K = K + 1;
				T[K] = matriz[linha][i];
				H[linha][i] = K;
			}
			else
			{
				int j = BuscaBinaria(T, 1, K, matriz[linha][i]);
				T[j] = matriz[linha][i];
				H[linha][i] = j;
			}
		}
	}
}

void SCM_V(int l, int c)
{
	for( int coluna = 1; coluna<=c; coluna++)
	{
		K = 1; 
		T[1] = matriz[1][coluna]; 
		V[1][coluna] = 1;
		for( int i = 2; i<=l; i++)
		{
				
			if( matriz[i][coluna] > T[K] )
			{
				K = K + 1;
				T[K] = matriz[i][coluna];
				V[i][coluna] = K;
			}
			else
			{
				int j = BuscaBinaria(T, 1, K, matriz[i][coluna]);
				T[j] = matriz[i][coluna];
				V[i][coluna] = j;
			}
		}
	}
}



int BuscaBinaria(int T[SIZEL], int ini, int fim, int x)
{
	if( ini > fim)
		return ini;
	else{
		int m = (ini+fim)/2;
		if( T[m] < x){
			return BuscaBinaria(T, m+1, fim, x);
		}
		else{
			return BuscaBinaria(T, ini, m-1, x);
		}
	}
}
