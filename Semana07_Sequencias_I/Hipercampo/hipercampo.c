#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX(a,b) ( (a)>(b)?(a):(b) )
#define BUFFER_SIZE	100001
#define SIZE	101
#define PI 3.14159265

int K;
int T1[BUFFER_SIZE];
int T2[BUFFER_SIZE];
double ladoA[SIZE];
double ladoB[SIZE];

typedef struct{
	int x;
	int y;
}Ponto;

void SCM(double* LadoA, double* LadoB, int n);
int BuscaBinaria(int* T1, int* T2, int ini, int fim, double alfax, double betax);
void ordenar(double* LadoA, double* LadoB, int n);
int quadradoDaDistancia(Ponto P, Ponto Q);

int main(void)
{
	int N, Xa, Xb, x, y;
	Ponto A, B, C;
	double val = 180.0 / PI;

	scanf("%d %d %d", &N, &Xa, &Xb);
	
	A.x = Xa; A.y = 0;
	B.x = Xb; B.y = 0;
	
	K = 0;
	
	//Calcular a distância AB
	int c2 = quadradoDaDistancia(A,B);
	double c = sqrt(c2);
	
	for( int i = 1; i<=N; i++)
	{
		scanf("%d %d", &x, &y);
		
		C.x = x; C.y = y;
		// quadrado da distância entre os pontos A, B e Pi
   	 	int a2 = quadradoDaDistancia(A,C);
    		int b2 = quadradoDaDistancia(B,C);
    		
  		
    		// tamanho dos lados a(AC), b(BC)
   	 	double a = sqrt(a2);
    		double b = sqrt(b2);
    		
    		//calcular os angulos alfa(BÂC) e beta(ABC)
    		double alfa = acos( (a2+c2-b2) / (2*a*c) )  * val;
    		double beta = acos( (c2+b2-a2) / (2*b*c) )  * val;
    		
    		
    		ladoA[i] = alfa*100; //100 para caso tenha valores decimais muito pequenos
		ladoB[i] = beta*100;
		
		//printf("(%d, %d);\t a=%.2f, b=%.2f, c=%.2f;\t alfa=%f, beta=%f\n", x, y, a, b, c, alfa, beta);
    		
    		
		
	}
	//Ordenar em relacao ao lado A
	ordenar(ladoA, ladoB, N);
	
	SCM(ladoA, ladoB, SIZE-1);
	printf("%d\n", K );
	
	return 0;
	
}

void SCM(double* LadoA, double* LadoB, int n)
{
	K = 1; 
	T1[1] = LadoA[1];
	T2[1] = LadoB[1]; 
	for( int i = 2; i<=n; i++)
	{
		
			
		if(  (LadoB[i]>T2[K]) && (LadoA[i]>T1[K]) )
		{
			K = K + 1;
			T1[K] = LadoA[i];
			T2[K] = LadoB[i];
		}
		else
		{
			int j = BuscaBinaria(T1, T2, 1, K, LadoA[i], LadoB[i]);
			T1[j] = LadoA[i];
			T2[j] = LadoB[i];
		}
	}
}

int quadradoDaDistancia(Ponto P, Ponto Q)
{
    int xD = Q.x - P.x;
    int yD = Q.y -  P.y;
    
    return ((xD*xD) + (yD*yD) );
}

void ordenar(double* LadoA, double* LadoB, int n)
{
	int i, j;
	double aux1; 
	double aux2; 
	
	for( i = 2; i<=n; i++)
	{
		j = i;
		aux1 = LadoA[i];
		aux2 = LadoB[i];
		while( LadoA[j-1] > aux1 )
		{
			LadoA[j] = LadoA[j-1];
			LadoB[j] = LadoB[j-1];
			j = j-1;
		}
		LadoA[j] = aux1;
		LadoB[j] = aux2;
	}
}

int BuscaBinaria(int* T1, int* T2, int ini, int fim, double alfax, double betax)
{
	if( ini > fim)
		return ini;
	else
	{
		int m = (ini+fim)/2;
		if( (T1[m] < alfax) && (T2[m] < betax) )
			return BuscaBinaria(T1, T2, m+1, fim, alfax, betax);
		else
			return BuscaBinaria(T1, T2, ini, m-1, alfax, betax);
	}
}
