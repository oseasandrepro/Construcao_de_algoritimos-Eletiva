#include <stdio.h>
#include <string.h>

#define SIZE 26
#define HEVOGAL(x) ( (x=='a') || (x=='e') || (x=='i') || (x=='o') || (x=='u') )

char tabela[SIZE][SIZE];
char alf[SIZE];
char mensagem[100001];
char palavraChave[45];
int N;

void criarTabela(void);
void printtabela(void);

int main(void)
{
	int i = 0;
	int tam;
	criarTabela();
	
	scanf("%s%*c", palavraChave);
	scanf("%d%*c", &N);
	
	tam = strlen(palavraChave);
	
	for( i = 0; i<N; i++)
	{
		char* pch;
		char* pchaux;
		char chant = '\0';
		
		scanf("%[^\n]%*c", mensagem);
		
		pch = mensagem;
		
		int indexmensagem = 0;
		while( !(*pch == '\0') )
		{
			if( HEVOGAL(*pch) &&  (*pch != ' ') )
			{
				while( !(*pch == '\0') &&  (*pch != ' '))
					pch++;
			}
			else if( (*pch == ' ') || (pch==mensagem))
			{
				if( !(pch==mensagem) )
					pch++;
					
				if( !HEVOGAL(*pch) )
				{
					
					pchaux = pch;
					while( (*pchaux != ' ') && !(*pchaux == '\0') )
					{
						int indexpalavrachave = indexmensagem%tam;
						char codlinha = palavraChave[indexpalavrachave] - 'a';
						char codcoluna = (*pchaux) - 'a';
							
						(*pchaux) = tabela[codlinha][codcoluna];
						pchaux++;
						indexmensagem++;
					}
					
					pch = pchaux;
				}
					
			}
		}
		printf("%s\n", mensagem);
	}
	return 0;
}

void criarTabela(void)
{
	char letra = 'a';
	int i, j;
	for(i = 0; i<SIZE; i++)
		alf[i] = letra++;
		
	for(i = 0; i< SIZE; i++)
	{
		for( j = 0; j<SIZE; j++)
		{
			int k = (i+j)%SIZE;
			tabela[i][j] = alf[k]; 
		}
	}
}

void printtabela(void)
{
	int i, j;
	for( i = 0; i<SIZE; i++)
	{
		for( j = 0; j<SIZE; j++)
		{
			printf("%4c", tabela[i][j]);
		}
		printf("\n");
	}
}
