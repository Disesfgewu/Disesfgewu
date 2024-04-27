#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{
	cin.tie( NULL ) ;
	cout.tie( NULL ) ;
	ios :: sync_with_stdio( false ) ;
	int ans = 0 , n , point ;
	while ( cin >> n )
	{
        ans = 0 ;
        while ( n-- )
		{
			cin >> point ;
			if ( ans < point )
				ans = point ;
		}
		cout << ans << endl ;
    }
    return 0 ;
} 
