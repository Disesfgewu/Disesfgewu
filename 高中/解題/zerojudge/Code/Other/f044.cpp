#include <bits/stdc++.h>
using namespace std;
int main ()
{
	double a , b ;
	cin >> a >> b ;
	b = b / a ;
	a = a / a ;
	//cout << a << " " << b <<" " << a+b << endl; 
 	cout << int( log(b+a) / log(2) ) << endl;
}
