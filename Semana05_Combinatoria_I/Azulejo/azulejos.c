#include <stdio.h>

long int mdc(long int a, long int b);

int main(void)
{
	long int N, A, B;
	long int Part1, Part2, Part3;
	long int resposta;
	while(1)
	{
		scanf("%ld %ld %ld", &N, &A, &B);
		if(N==0 && A==0 && B==0)
			break;
		Part1 = N/A; 
		Part2 = N/B; 
		Part3 = N/ ( (A*B)/mdc(A,B) );
			
		resposta = Part1 + Part2 - Part3;
		printf("%ld\n", resposta);
	}
	return 0;
}

long int mdc(long int a, long int b)
{
	if( b == 0)
		return a;
	else
		return mdc(b, a%b);
}
