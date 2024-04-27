#include <iostream>
using namespace std;
int main ()
{
	int n ;
	while ( cin >> n )
	{
		for ( int i = -12 ; i <= 107 ; i++ )
	{
		int count;
		//cout << count << endl;
		if ( i < 0 )
			count = ( i + 1 ) % 12;
		else
			count = i % 12 ;
		//cout << count << endl;
		if ( count < 0 )
			count += 12 ;
		switch ( count )
		{
			case 1 :
				cout << "¹«" << endl;
				break; 
			case 2 :
				cout << "¤û" << endl;
				break; 
			case 3 :
				cout << "ªê" << endl;
				break; 
			case 4 :
				cout << "¨ß" << endl;
				break; 
			case 5 :
				cout << "Às" << endl;
				break; 
			case 6 :
				cout << "³D" << endl;
				break; 
			case 7 :
				cout << "°¨" << endl;
				break; 
			case 8 :
				cout << "¦Ï" << endl;
				break; 
			case 9 :
				cout << "µU" << endl;
				break; 
			case 10 :
				cout << "Âû" << endl;
				break; 
			case 11 :
				cout << "ª¯" << endl;
				break; 
			default :
				cout << "½Þ" << endl;
				break; 
		}
	}
	}
	return 0 ;
}
