#include <stdio.h>


int main(void)
{
	int L, C, R1, R2;
	int a, b, c;
	
	while( 1 )
	{
		scanf("%d%d%d%d", &L, &C, &R1, &R2);
		if( L==0 && C == 0 && R1==0 && R2==0 )
			break;
		int maiorDiametro = (2*R1)>(2*R2)?(2*R1):(2*R2);
		int menorLdoElevador = (L<C) ? L : C;
		int P,Q;
		
		
		a = (L-(R1+R2));
		b = (C-(R1+R2));
		c = a*a + b*b;
		
		
		Q = ((R1+R2)*(R1+R2)) <= c ;
		P = maiorDiametro <= menorLdoElevador;
		
		(P&&Q) ? printf("S\n") : printf("N\n");
	}
	
	return 0;
}
