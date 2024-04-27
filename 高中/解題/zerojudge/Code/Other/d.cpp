#include <iostream>
using namespace std;
int main ()
{
	int number ;
	while ( cin >> number )
	{
		for ( int i = 1 ; i <= number ; i++ )
		{
			int count = 1 ;
			if (( number % i == 0)&&( i != 1 ))
			{
				number = number / i ;
				while ( number % i == 0)
				{
					count ++ ;
					number = number / i ;
				}
				if (( count > 1 )&&( number != 1))
				{
					cout << i << "^" << count << " * " ; 
				}
				else if (( number == 1 )&&( count == 1))
				{
					cout << i ;
				}
				else if ((number == 1)&&(count > 1 ))
				{
					cout << i << "^" << count ;
				}
				else 
				{
					cout << i << " * " ;
				}
			 } 
			
		}
		cout << endl;
	}
}
