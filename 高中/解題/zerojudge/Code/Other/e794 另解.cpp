#include<stdio.h>

int main()
{	
	int N = 0;
	int h = 0, w = 0;
	scanf("%d", &N);

	int num1 = 0,num2 = 1;
	int num3 = 0;
	for(int i=2;i<=N;i+=1)
	{
		num3 = num1 + num2;
		if( i == N )
			break;
		num1 = num2;
		num2 = num3;
	}

	if( N == 1 ){
		h = 1;
		w = 1;
	}
	else{
		h = num3;
		w = num3 + num2;
	} 
		
	printf("%d:%d\n", h, w);
	return 0;
}

