#include <iostream>
#include <vector>
using namespace std ;

int main ()
{
	int n ;
	while ( cin >> n )
	{
		vector <string> s ;
		for ( int i = 0 ; i < n ; i++ )
		{
			string s1 ;
			cin >> s1 ;
			s.push_back( s1 ) ;
	 	}
	 	int q ;
	 	cin >> q ;
		for ( int i = 0 ; i < q ; i++ )
		{
			string s2 ;
			cin >> s2 ;
			int count = 0 ;
			for ( int j = 0 ; j < s.size() ; j++ )
			{
				if ( s[j] == s2 )
				{
					count = 1 ;
					break ;
				}
			}
			if ( count == 1 )
			{
				cout << "yes" << endl ;
			 } 
			 else
			 {
			 	cout << "no" << endl ;
			 	s.push_back( s2 ) ;
			 }
		 } 
	}	 
}
