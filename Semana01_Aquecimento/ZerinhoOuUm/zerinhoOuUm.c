#include <stdio.h>
#define N 4

/* verificar se no vetor tem o simbolo v[indice] além da posicao indice. Retorna 1 se sim e, 0 se nao. */
int OsimboloCorrenteHeUnico(int v[], int indice, int n);



int main(void)
{
	char jogador[3] = {'A', 'B', 'C'};
	int vet[3] = {0,0,0};
	int i;
	int flag = 0;
	
	while( scanf("%d %d %d", &vet[0], &vet[1], &vet[2]) > 0 )
	{
		flag = 0;
		for(i = 0; i<N-1; i++)
		{
			if( OsimboloCorrenteHeUnico(vet, i, N-1) )
			{
				printf("%c\n", jogador[i] );
				flag = 1;
				break;
			}
		}
		
		if( flag==0 ){
			printf("*\n");
		}
	}
	
	return 0;
}

int OsimboloCorrenteHeUnico(int v[], int indice, int n)
{
	int cont = 0;
	int i;
	for( i = 0; i<n; i++)
	{
		if( (v[indice] == v[i]) && (i!=indice) )
			cont = cont + 1;
	}
	if( cont == 0)
		return 1;
	else
		return 0;
}
