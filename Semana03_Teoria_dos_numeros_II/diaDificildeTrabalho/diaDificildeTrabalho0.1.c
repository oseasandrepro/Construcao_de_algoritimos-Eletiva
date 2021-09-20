#include <stdio.h>

#define SIZE 3
long N,X;
long ni[SIZE], ai[SIZE];
long Ni[SIZE], Xi[SIZE];
long D, y;


void MDCE(long a, long b, long* D, long* X, long *Y );

int main(void)
{

	long r, l;
	long cont = 0;
	long i = 0;
	
	
	while( scanf("%ld %ld", &r, &l) != EOF)
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
				
			for( i = 0; i<SIZE; i++)
				X += (ai[i]*Ni[i]*Xi[i]);
				
			if( X < 0)
			{
				X = 0;
				/*Resolvendo Xi(inverso modular) negativo*/	
				for( i = 0; i<SIZE; i++)
					Xi[i] = ((Xi[i]%ni[i])+ni[i])%ni[i];
				for( i = 0; i<SIZE; i++)
					X += (ai[i]*Ni[i]*Xi[i]);
			}
			
			if( X==0)
				X = N;
			else	
				X = X%N;
				
			i = 0;
			printf("Caso #%ld: %ld laranja(s)\n", cont, X); 
		}
		
	}
	return 0;	
}

void MDCE(long a, long b, long* D, long* X, long *Y )
{
	long xant, yant, resto, quociente;
	long d, x, y, aux;
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
