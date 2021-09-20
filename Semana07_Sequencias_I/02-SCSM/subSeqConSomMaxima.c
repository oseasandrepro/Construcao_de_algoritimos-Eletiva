#include <stdio.h>

#define SIZE 12

int S[SIZE] = {0,	6, 2, -7, 12, -15, 8, -2, 3, -5, 10, -1};

int sm, im, fm;
int ss, is, fs;


void SCM(int* S, int N);

int main(void)
{
	SCM(S, SIZE-1);
	printf("%d\n", sm);
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
