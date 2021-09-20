#include <stdio.h>

#define SIZE 100001
int buffer[SIZE];
int indices[SIZE];

/*n é sempre maior ou igual a c*/
int main(void)
{
	int c, n;
	int i, j, k, l;
	int index;
	int resto, tempr;
	int soma;
	int flag = 1;
	while( 1 )
	{
		scanf("%d %d", &c, &n);
		if( c==0 && n==0)
			break;
		for( i = 1; i<=n; i++){
			scanf("%d", &buffer[i] );
		}
		
		
		flag = 1;
		for( i = 1; i<=n; i++)
		{
			if( flag == 0)
				break;
			resto = -1;
			soma = 0;
			index = 1;
			indices[index] = i;
			soma +=buffer[i];
			resto = soma%c;
			if( resto == 0){
				printf("%d\n", i);
				break;
			}
					
			for(j = 1; j<=n; j++)
			{
				if(j==i)
					continue;
				indices[++index] = j;
				soma +=buffer[j];
				tempr = resto;
				resto = soma%c;
				if( resto == 0)
				{
					flag = 0;
					for(l = 1; l<=index; l++){
						!(l==index)?printf("%d ", indices[l]):printf("%d", indices[l]);
					}
					printf("\n");
					break;
				}
				else if( resto == tempr)
				{
					flag = 0;
					for(l = indices[i]+1; l<=index; l++)
					{
						!(l==index)?printf("%d ", indices[l]):printf("%d", indices[l]);
					}
					printf("\n");
					break;
				}
			}
		}
			
	}
	return 0;
}
