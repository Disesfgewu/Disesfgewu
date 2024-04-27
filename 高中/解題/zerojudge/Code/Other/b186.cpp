#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{
	long long int a , b , c ;
	while ( cin >> a >> b >> c )
	{
		//long long int count = 0 ;
		long long int A = a / 10 ;
		long long int C = c / 2 ;
		b += min( A , C ) ;
		 cout << a << " 個餅乾，" << b << " 盒巧克力，" << c << " 個蛋糕。" << endl;
	}
	return 0 ;
}
