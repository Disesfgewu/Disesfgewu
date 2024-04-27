#include <iostream>
using namespace std;
int main ()
{
	int n , m;
	while ( cin >> n >> m )
	{
		int count , C[100000] = {0} , c = 0 ;
		do
		{
			c++;
			count = 0 ;
			C[c-1] = n + c - 1;
			for ( int i = 0 ; i < c ; i++ )
				count += C[i];
		}while ( count <= m );
		cout << c << endl;
	}
	return 0 ;
}
