#include <stdio.h>
#include <math.h>

#define MAX(a,b) ( (a)>(b)?(a):(b) )
#define SIZE	101
#define PI 3.14159265

typedef struct{
	int x;
	int y;
}Ponto;

int SCM_t(double* BAC, double* ABC, int n);
int SCM(double* BAC, double* ABC, int n);
void ordenar(double* BAC, double* ABC, int n);
int quadradoDaDistancia(Ponto P, Ponto Q);

double ABC[SIZE];
double BAC[SIZE];

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
		// quadrado da distância entre os pontos a2, b2, c2
   	 	int a2 = quadradoDaDistancia(B,C);
    		int b2 = quadradoDaDistancia(A,C);
    		int c2 = quadradoDaDistancia(A,B);
  		
    		// tamanho dos lados a, b, c
   	 	float a = sqrt(a2);
    		float b = sqrt(b2);
    		float c = sqrt(c2);
  
    		// Aplicando lei dos cossenos
    		float alfa = acos((b2 + c2 - a2)/(2*b*c));
    		float beta = acos((a2 + c2 - b2)/(2*a*c));
    		float gama = acos((a2 + b2 - c2)/(2*a*b));
  
	    	// Convertendo para graus
	   	alfa = alfa * 180 / PI;
	    	//beta = beta * 180 / PI;
	    	gama = gama * 180 / PI;
	    	
	    	ladoA[i] = a;
	    	ladoB[i] = b;
	    	
	    	//BAC[i] = alfa;
	    	//ABC[i] = gama;
	    	printf("(%d, %d): %.2f %.2f %.2f\n" ,x, y,  a, b, c);
	    	//printf("(%d, %d): %.2f %.2f\n", x, y, BAC[i], ABC[i]);
		
	}
	
	//Ordenar os angulo BAC
	ordenar(ladoA, ladoB, N);
	for( int i = 1; i<=N; i++)
		printf("%.2f %.2f\n", ladoA[i], ladoB[i]);
	
	printf("%d\n", SCM(ladoA, ladoB, SIZE-1) );
	
	return 0;
	
}


int SCM_t(double* BAC, double* ABC, int n)
{
	int m = 1;
	for( int i = 1; i<=n-1; i++)
	{
		if( (BAC[i] < BAC[n]) && (ABC[i] < ABC[n]) )
		{
			m = MAX( m, SCM_t(BAC, ABC, i)+1 );
		}
	}
	return m;
}

int SCM(double* BAC, double* ABC, int n)
{
	int m = 0;
	for( int i = 1; i<=n; i++){
		m = MAX( m, SCM_t(BAC, ABC, i) );
	}
	
	return m;
	
}

int quadradoDaDistancia(Ponto P, Ponto Q)
{
    int xD = P.x - P.y;
    int yD = Q.x -  Q.y;
    
    return xD*xD + yD*yD;
}

void ordenar(double* BAC, double* ABC, int n)
{
	int i, j;
	double aux1; 
	double aux2; 
	
	for( i = 2; i<=n; i++)
	{
		j = i;
		aux1 = BAC[i];
		aux2 = ABC[i];
		while( BAC[j-1] < aux1 )
		{
			ABC[j] = ABC[j-1];
			BAC[j] = BAC[j-1];
			j = j-1;
		}
		BAC[j] = aux1;
		ABC[j] = aux2;
	}
}
