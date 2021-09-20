#include <stdio.h>

int main(void)
{
	int B1[3], B2[3];
	int EmpB1B2, EmpB2B1;
	
	int n, i, k,l, j,p;
	
	scanf("%d", &n);
	
	for(i = 0; i<n; i++)
	{
		scanf("%d %d %d %d %d %d", &B1[0], &B1[1], &B1[2], &B2[0], &B2[1], &B2[2]);
		
		EmpB1B2 = EmpB2B1 = 0;
		for( k = 0; k<3; k++)
		{
			for( l=k+1; l<3; l++)
			{
				for( j = 0; j<3; j++)
				{
					for( p = j+1; p<3; p++)
					{
						if( (B1[k]>B2[j] && B1[l]>B2[p]) || (B1[k]>B2[p] && B1[l]>B2[j] ) ){
							EmpB2B1 = 1;
						}
						if( (B2[k]>B1[j] && B2[l]>B1[p]) || (B2[k]>B1[p] && B2[l]>B1[j] ) ){
							EmpB1B2 = 1;
						}
					}
				}
			}
		}
		
		if( EmpB1B2 && EmpB2B1 )
		{
			printf("3\n");
		}else if( EmpB1B2 && !EmpB2B1 )
		{
			printf("1\n");
		}
		else if( !EmpB1B2 && EmpB2B1 )
		{
			printf("2\n");
		}
		else
		{
			printf("0\n");
		}
	}
	return 0;
}
