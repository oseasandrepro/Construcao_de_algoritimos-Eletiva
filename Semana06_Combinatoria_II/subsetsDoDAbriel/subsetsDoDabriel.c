#include <stdio.h>
#include <string.h>

#define NMOD 1000000007
#define SIZE 3

long long int ComputeSubsets(long long int n);

void expMatRec(long long int M[SIZE][SIZE], long long int n);
void prodMat( long long int A[SIZE][SIZE], long long int B[SIZE][SIZE]);
long long int SomaMod(long long int a, long long int b, long long int n);
long long int Multmod(long long int a, long long int b, long long int n);


int main(void)
{
	long long int x;
	
	scanf("%lld", &x);
	
	printf("%lld\n", ComputeSubsets(x) );
	
	return 0;
}

long long int ComputeSubsets(long long int n)
{
	//long long int D[SIZE][SIZE];
	long long int R[SIZE][SIZE];
	long long int A[SIZE][SIZE] = {	{0, 1, 1}, 
					{1, 0, 0},
					{0, 1, 0} };
	memcpy(R, A, (SIZE*SIZE)*sizeof(long long int));
	
	expMatRec( R, n-3);
	
	return ( (R[0][0]) + (R[0][1]) + (R[0][2]) ); 
}
//Recebe as matrizes A e B efetua o produto e armazena em B
void prodMat( long long int A[SIZE][SIZE], long long int B[SIZE][SIZE])
{
	long long int aux[SIZE][SIZE];
	
	memset(aux, 0, (SIZE*SIZE)*sizeof(long long int) );
	
	for( int i = 0; i<SIZE; i++)
	{
		for(int j = 0; j<SIZE; j++)
		{
			for(int z = 0; z<SIZE; z++)
			{
				aux[i][j] = aux[i][j] + A[i][z]*B[z][j]; 
			}
		}
	}

	memcpy(B, aux, (SIZE*SIZE)*sizeof(long long int));
}

//Recebe a matriz M e o inteiro n, efeuta a potência M^n
void expMatRec(long long int M[SIZE][SIZE], long long int n)
{
	
	long long int N[SIZE][SIZE];
	long long int B[SIZE][SIZE];
	
	if(n<0)
	{
	}
	else if( n==0)
	{
		long long int R[SIZE][SIZE] = {	{1, 0, 0}, 
						{0, 1, 0},
						{0, 0, 1} };
		memcpy(M, R, (SIZE*SIZE)*sizeof(long long int));
	}
	else if( (n%2) == 0)
	{	
		memcpy(N, M, (SIZE*SIZE)*sizeof(long long int));
		
		expMatRec(N, n/2);
		prodMat(N,N);
		
		memcpy( M, N, (SIZE*SIZE)*sizeof(long long int));
	}
	else
	{
		memcpy(B, M, (SIZE*SIZE)*sizeof(long long int));
		memcpy(N, M, (SIZE*SIZE)*sizeof(long long int));
		expMatRec(N, n-1);
		prodMat(N,B);
		
		memcpy(M, B, (SIZE*SIZE)*sizeof( long long int));
	}
	
}

long long int SomaMod(long long int a, long long int b, long long int n)
{
	unsigned long long int la,lb;
	la = a; lb = b;
	return (la+lb)%n;
}
long long int Multmod(long long int a, long long int b, long long int n)
{
	unsigned long long int la,lb;
	la = a; lb = b;
	return (la*lb)%n;
}
