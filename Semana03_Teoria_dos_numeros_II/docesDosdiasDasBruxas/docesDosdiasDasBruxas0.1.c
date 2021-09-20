#include <stdio.h>

#define SIZE 100001

int buffer[SIZE];
int soma[SIZE];

/*n é sempre maior ou igual a c*/
int main(void)
{
	
	int c, n;
	int i, j,l;
	int resto, tempr;
	int flag;
	
	while( scanf("%d %d", &c, &n) != EOF)
	{
		if( c==0 && n==0)
			break;
		for( i = 1; i<=n; i++){
			scanf("%d", &buffer[i] );
		}
		flag = 1;
		for( j = 1; j<=n; j++)
		{
			if((buffer[j]%c) == 0){
				printf("%d\n", buffer[j]);
				flag = 0;
				break;
			}
		}
		
	if(flag!=0){
		for( flag = 1, i = 1; i<=n-1; i++)
		{
			if(flag==0)
				break;
			soma[i] = buffer[i];
			resto = soma[i]%c;
			if( resto == 0){
				printf("%d\n", buffer[i]);
				break;
			}
			for( j = i+1; j<=n; j++)
			{
				soma[j] = soma[j-1] + buffer[j];
				resto = soma[j]%c;
				if( resto == 0)
				{
					flag = 0;
					for(l = i; l<=j; l++)
						!(l==j)?printf("%d ", l):printf("%d", l);
					printf("\n");
					break;
				}
				else if( resto == tempr)
				{
					flag = 0;
					for(l = i+1; l<=j; l++)
						!(l==j)?printf("%d ", l):printf("%d", l);
					printf("\n");
						break;
				}
			}
		}
	}
			
	}
	return 0;
}
