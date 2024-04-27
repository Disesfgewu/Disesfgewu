#include <stdio.h>

void s (int *nums, int len, int *result1, float *result2, float *result3)
{
	*result1 = 0 ; // sum = 0 ; 
    for(int i=0; i<len; i++)
    {
        *result1 += *(nums+i);
    }
	if((len%2) != 0)
        *result2 = (float)*(nums+len/2);
    else
    {
		*result2 = (float)nums[len/2] + (float)nums[len/2-1]  ;
		*result2 /= 2 ;
    }
	*result3 = ( (float)*result1 ) /len;
}
int main ()
{
	int n ;
	printf( "Input array length: " ) ;
	scanf( "%d" , &n ) ;
	printf( "Input %d numbers: " , n  ) ;
	int sum = 0 ;
	float avg = 0 , median = 0 ;
	int a[n] ;
	for ( int i = 0 ; i < n ; ++i )
	{
		scanf( "%d" , &a[i] ) ;
	}
	int* ptr1 = &sum ;
	float *ptr2 = &median ;
	float *ptr3 = &avg ;
	s( a , n , ptr1 , ptr2 , ptr3 ) ;
	printf( "Sum: %d\nMedian: %.2f\nAverage: %.2f\n " , sum , median , avg ) ;
}
