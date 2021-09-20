#include <stdio.h>

#define SIZE 100001
#define N 11

char A[SIZE], B[SIZE];
char tabelaNF[N];

int fNF(int n){
	return (n%9)==0?9:n%9;
}
void preencherTabela(int n){
	int i;
	for( i = 0; i<N; i++){
		tabelaNF[i] = fNF( (int)pow((double)n, (double)i) );
	} 	
}

int main(void)
{
	int NF, digito;
	int a, b;
	int digitRoot;
	int k, l, i, di;
	
	scanf("%s", A);
	scanf("%s", B);
	
	k = strlen(A);
	l = strlen(B);
	a = 0;
	
	
	
	//tratando A
	for( i = 0; i<k; i++)
		a += A[i]-'0';	
	a = fNF(a);
	
	preencherTabela(a);
	
	
	for( i = 0; B[i] != '\0'; i++)
	{
		digito = B[i] - '0';
		if( i == 0)
		{
			NF = tabelaNF[digito];
			if(B[i+1] != '\0')
				NF = fNF( (int)pow((double)NF, 10.0) );
		}
		else
		{
		
			NF = fNF( fNF(NF) * tabelaNF[digito] );
			if(B[i+1] != '\0')
				NF = fNF( (int)pow((double)NF, 10.0) );
		}	
	}
	
	printf("%d\n", NF);
	
	
	return 0;
}
