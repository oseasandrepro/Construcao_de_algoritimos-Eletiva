#include <stdio.h>

#define SIZE 51

int sm, im, fm;
int ss, is, fs;


void SCM(int* S, int N);

int main(void)
{
	int S[SIZE];
	int n, custo, receita;

	
	while( 1 )
	{
		if( scanf("%d", &n) < 1 )
			break;
		scanf("%d", &custo);
		
		for( int i = 1; i<=n; i++)
		{
			scanf("%d", &receita);
			S[i] = receita - custo;
		}
		
		SCM(S, n);
		printf("%d\n", sm);
	}
	return 0;
}


void SCM(int* S, int N)
{
	sm = im = fm = 0;
	ss = is = fs = 0;
	for( int i = 1; i<=N; i++)
	{
		if( ss+S[i] >= 0)
		{
			ss = ss + S[i];
			fs = i;
			if( is = 0)
				is = i;
			if( ss > sm){
				sm = ss;
				im = is;
				fm = fs;
			}
		}
		else
		{
			ss = is = fs = 0;
		}
	}
}
