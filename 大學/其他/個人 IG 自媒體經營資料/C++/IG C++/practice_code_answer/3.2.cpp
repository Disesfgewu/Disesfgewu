#include <iostream>
using namespace std ;

int main ()
{
	int n , m ;
	cout << "How much bottles of water you want to get : " ;
	cin >> n ;
	cout << "Please give the money : " ;
	cin >> m ;
	int count = m-5*n ;
	int ans = 0 ; 
	ans += count/100 ;
	count %= 100 ;
	ans += count/50 ;
	count %= 50 ;
	ans += count/10 ;
	count %= 10 ;
	ans += count/5 ;
	count %= 5 ;
	ans += count ;
	cout << "The staff need to give " << ans << " coins." << endl ;
	return 0 ;
}
