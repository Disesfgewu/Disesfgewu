#include <bits/stdc++.h>
using namespace std;
int main ()
{
	long long int h , m , s ;
	while ( cin >> h >> m >> s )
	{
		if ( h*s >= m )
			cout << h << " " << m << " " << s << ". I will make it!"<< '\n';
		else
			cout << h << " " << m << " " << s << ". I will be late!"<< '\n';
	}
	return 0 ;
}
