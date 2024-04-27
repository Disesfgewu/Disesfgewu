#include <iostream>
using namespace std;
const int maxn = 50005;
int N, K;
int p[maxn];
long long lps[maxn], rps[maxn];
int cut(int L , int R , int level ) 
{
    if ( level == 0 || R - L < 2 ) 
		return 0;
    long long delta = 0;
    lps[L] = 0;
    for ( int i = L+1 ; i <= R ; i++ ) 
	{
        delta += p[i-1];
        lps[i] = lps[i-1] + delta;
    }
    delta = 0;
    rps[R] = 0;
    for ( int i = R-1 ; i >= L ; i-- ) 
	{
        delta += p[i+1];
        rps[i] = rps[i+1] + delta;
    }
    long long mn = 2e18;
    int idx = 0;
    for ( int i = L+1 ; i <= R-1 ; i++ ) 
	{
        long long cost = abs( rps[i] - lps[i] ) ;
        if ( cost < mn ) 
		{
            mn = cost;
            idx = i;
        }
    }
    return p[idx] + cut( L , idx-1 , level-1 ) + cut( idx+1 , R , level-1 );
}
 
int main() 
{
    cin >> N >> K;
    for ( int i = 1 ; i <= N ; i++ ) 
        cin >> p[i];
    cout << cut( 1 , N , K ) << endl;
    return 0;
}
