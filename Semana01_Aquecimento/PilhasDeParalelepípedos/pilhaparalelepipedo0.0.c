#include <stdio.h>

int PodeempilharB1emB2(char *str);
int PodeempilharB2emB1(char *str);

int FaceAbHeMaiorQueCd(int a, int b, int c, int d);


int main(void)
{
	int n, i;
	char linha[20];
	int flag1,flag2;
	scanf("%d%*c", &n);
	
	for(i = 0; i<n; i++)
	{
		flag1 = flag2 = 0;
		scanf("%[^\n]%*c", linha);
		
		flag1 = PodeempilharB1emB2(linha);
		
		flag2 = PodeempilharB2emB1(linha);
		
		if( flag1 && flag2)
		{
			printf("3\n");
		}else if(flag1 && !flag2 )
		{
			printf("1\n");
		}
		else if( !flag1 && flag2)
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

int FaceAbHeMaiorQueCd(int a, int b, int c, int d)
{
	return (a>c) && (b>d) || (a>d && b>c);
}

int PodeempilharB2emB1(char* str)
{
	/*a, b, c*/
	int a1, b1, c1;
	int a2, b2, c2;
	int face1, face2, face3;
	sscanf(str,"%d %d %d %d %d %d", &a1, &b1, &c1, &a2, &b2, &c2);
	
	face1 = face2 = face3 = 0;
	
	/*face1: b,c*/
	face1 = FaceAbHeMaiorQueCd(b1,c1, b2,c2) || FaceAbHeMaiorQueCd(b1,c1, c2, a2) || FaceAbHeMaiorQueCd(b1,c1,b2,a2);
	
	/*face2: c,a*/
	face2 = FaceAbHeMaiorQueCd(c1,a1, b2, c2) || FaceAbHeMaiorQueCd(c1,a1, c2, a2) || FaceAbHeMaiorQueCd(c1,a1, b2, a2); 
	
	/*face3: b,a*/
	face3 = FaceAbHeMaiorQueCd(b1,a1, b2, c2) || FaceAbHeMaiorQueCd(b1,a1, c2, a2) || FaceAbHeMaiorQueCd(b1,a1, b2, a2);
	
	return (face1 || face2 || face3);
}

int PodeempilharB1emB2(char* str)
{
	/*a, b, c*/
	int a1, b1, c1;
	int a2, b2, c2;
	int face1, face2, face3;
	sscanf(str, "%d %d %d %d %d %d", &a1, &b1, &c1, &a2, &b2, &c2);
	face1 = face2 = face3 = 0;
	
	/*face1: b,c*/
	face1 = FaceAbHeMaiorQueCd(b2,c2, b1,c1) || FaceAbHeMaiorQueCd(b2,c2, c1,a1) || FaceAbHeMaiorQueCd(b2,c2, b1,a1);
	
	/*face2: c,a*/
	face2 = FaceAbHeMaiorQueCd(c2,a2, b1,c1) || FaceAbHeMaiorQueCd(c2,a2, c1,a1) || FaceAbHeMaiorQueCd(c2,a2, b1, a1);  
	
	/*face3: b,a*/
	face3 = FaceAbHeMaiorQueCd(b2,a2, b1,c1) || FaceAbHeMaiorQueCd(b2,a2, c1,a1) || FaceAbHeMaiorQueCd(b2,a2, b1,a1);
	
	return ( face1 || face2 || face3 );
}

