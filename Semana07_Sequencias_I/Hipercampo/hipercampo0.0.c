#include <stdio.h>
#include <math.h>

#define MAX(a,b) ( (a)>(b)?(a):(b) )
#define SIZE	101
#define PI 3.14159265

typedef struct{
	int x;
	int y;
}Ponto;

int SCM_t(double* LadoA, double* LadoB, int n);
int SCM(double* LadoA, double* LadoB, int n);
void ordenar(double* LadoA, double* LadoB, int n);
int quadradoDaDistancia(Ponto P, Ponto Q);

double ladoA[SIZE];
double ladoB[SIZE];


int main(void)
{
	int N, Xa, Xb, x, y;
	Ponto A,B,C;
	double val = 180.0 / PI;

	scanf("%d %d %d", &N, &Xa, &Xb);
	
	A.x = Xa; A.y = 0;
	B.x = Xb; B.y = 0;
	for( int i = 1; i<=N; i++)
	{
		scanf("%d %d", &x, &y);
		
		C.x = x; C.y = y;
		// quadrado da distância entre os pontos A, B e Pi
   	 	float a2 = quadradoDaDistancia(A,C);
    		float b2 = quadradoDaDistancia(B,C);
    		float c2 = quadradoDaDistancia(A,B);
  		
    		// tamanho dos lados a, b, c
   	 	float a = sqrt(a2);
    		float b = sqrt(b2);
    		float c = sqrt(c2);
    		
    		float alfa = acos( (a2+c2-b2) / (2*a*c) );
    		float beta = acos( (c2+b2-a2) / (2*b*c) );
    		
    		alfa = alfa * 180 / PI;
		beta = beta * 180 / PI;
    		
    		ladoA[i] = alfa;
		ladoB[i] = beta;
		
		//printf("(%d, %d); a=%.2f, b=%.2f, c=%.2f; alfa=%.2f beta=%.2f\n", x, y, a, b, c, alfa, beta);
    		
    		
		
	}
	//Ordenar em relacao ao lado A
	ordenar(ladoA, ladoB, N);
	
	printf("%d\n", SCM(ladoA, ladoB, SIZE-1) );
	
	return 0;
	
}


int SCM_t(double* LadoA, double* LadoB, int n)
{
	int m = 1;
	for( int i = 1; i<=n-1; i++)
	{
		if( (LadoA[i] < LadoA[n]) && (LadoB[i] < LadoB[n]) )
		{
			m = MAX( m, SCM_t(LadoA, LadoB, i)+1 );
		}
	}
	return m;
}

int SCM(double* LadoA, double* LadoB, int n)
{
	int m = 0;
	for( int i = 1; i<=n; i++){
		m = MAX( m, SCM_t(LadoA, LadoB, i) );
	}
	
	return m;
	
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
