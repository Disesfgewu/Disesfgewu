#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector <int> d ;
stack <int> c ;

int main ()
{
	int n ;
	while ( cin >> n )
	{
		int a , b ;
		for ( int i = 0 ; i < n ; i++ )
		{
			cin >> a ;
			d.push_back(a);
			if ( a == 3 )
			{
				cin >> b ;
				c.push(b);
			}
			else if ( d[i] == 2 )
				cout << c.top() << endl;
			else if ( d[i] ==  1 )
				c.pop();
		}
		/*for ( int i = 0 ; i < n ; i++ )
		{
			if ( d[i] == 2 )
				cout << c.top() << endl;
			else if ( d[i] ==  1 )
				c.pop();
		}*/ 
	}
	return 0 ;
 } 
