#include <bits/stdc++.h>
using namespace std;
int main ()
{
	float x[3] ={0} , y[3] = {0} , count[3] = {0};
	for ( int i = 0 ; i < 3 ; i++ )
			cin >> x[i] >> y[i] ;
	count[0] = sqrt( ( pow( x[0]-x[1]  , 2) + ( pow( y[0]-y[1] , 2) ) ));
	count[1] = sqrt( ( pow( x[2]-x[1]  , 2) + ( pow( y[2]-y[1] , 2) ) )); 
	count[2] = sqrt( ( pow( x[0]-x[2]  , 2) + ( pow( y[0]-y[2] , 2) ) ));
	float r = ( count[0]+count[1]+count[2] ) / 2;
	float p = sqrt(r*(r-count[0])*(r-count[1])*(r-count[2])) * 2 ;
	cout << int(p) << endl; 
 }
