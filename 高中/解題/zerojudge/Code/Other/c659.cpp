#include <iostream>
using namespace std;
int main () 
{
	string s ;
	while ( cin >> s )
	{
		string a ;
		while ( cin >> a )
			cout << a << " " << s ;
		cout << endl;
	}
	return 0 ;
}
