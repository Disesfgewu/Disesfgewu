#include <iostream>
using namespace std ;

int main ()
{
	int N ;
	cin >> N ;
	int score[N] ;
	for ( int i = 0 ; i < N ; i++ )
	{
		cin >> score[i] ;
	}
	for ( int i = N-1 ; i >= 0 ; i-- )
	{
		int y = 0 , c = 0;
		for ( int j = 0 ; j <= i ; j++ )
		{
			if ( c < score[j] )
			{
				c = score[j] ;
				y = j ;
			}
		}
		int u = score[i];
		score[i] = c ;
		score[y] = u ;
	}
	int best = 101 , worst = -1 , b = 0 , w = 0 ;
	for ( int i = 0 ; i < N ; i++ )
	{
		cout << score[i] ;
		if ( score[i] >= 60 && score[i] < best )
		{
			best = score[i];
		}
		else if ( score[i] < 60 && score[i] > worst )
		{
			worst = score[i];
		}
	}
	cout << endl ;
	if ( worst == -1 )
	{
		cout << "best case" << endl ;
	}
	else
	{	
		cout << worst << endl ;
	}
	if ( best == 101 )
	{	
		cout << "worst case" << endl ;
	}
	else
	{	
		cout << best << endl ;
	} 
	return 0 ;
}
