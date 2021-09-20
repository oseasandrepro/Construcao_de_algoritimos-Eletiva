#include <stdio.h>

#define SIZE 3
int N,X;
int ni[SIZE], ai[SIZE];
int Ni[SIZE], Xi[SIZE];
int D, y;


void MDCE(int a, int b, int* D, int* X, int *Y );

int main(void)
{

	int r, l;
	int cont = 0;
	int i = 0;
	while( scanf("%d%d", &r, &l) == 2)
	{
		ai[i] = r; ni[i] = l;
		i++;
		if( (i%3) == 0)
		{
			cont++;
			N = 1;
			X = 0;
			for( i = 0; i<SIZE; i++)
				N *= ni[i];
			
			for( i = 0; i<SIZE; i++)
				Ni[i] = N/ni[i];
				
			for( i = 0; i<SIZE; i++)
				MDCE(Ni[i], ni[i], &D, &Xi[i], &y);
			//Resolvendo Xi(inverso modular) negativo	
			for( i = 0; i<SIZE; i++)
			{
				if( Xi[i]<0)
					Xi[i] = ((Xi[i]%ni[i])+ni[i])%ni[i];
			}
				
			for( i = 0; i<SIZE; i++)
				X += ai[i]*Ni[i]*Xi[i];
			if( X==0)
				X = N;
			else	
				X = X%N;
			i = 0;
			printf("Caso #%d: %d laranja(s)\n", cont, X); 
		}
		
	}
	return 0;	
}

void MDCE(int a, int b, int* D, int* X, int *Y )
{
	int xant, yant, resto, quociente;
	int d, x, y, aux;
	xant = 1; yant = 0;
	x = 0; y = 1;
	while( b!= 0)
	{
		quociente = a/b;
		resto = a % b;
		a = b;
		b = resto;
		
		aux = x;
		x = xant - quociente*x; xant = aux;

		aux = y;
		y = yant - quociente*y; yant = aux;
	}
	*D = a; *X = xant; *Y = yant;
}
