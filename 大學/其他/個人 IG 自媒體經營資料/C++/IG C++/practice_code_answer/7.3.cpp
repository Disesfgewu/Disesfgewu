#include <iostream>
using namespace std ;

int main ()
{
	int r , c , k , m;
	while ( cin >> r >> c >> k >> m )
	{
		int city[r+2][c+2] , cit[r+2][c+2] , uo= 101 , u = 0 ;
		for ( int i = 0 ; i < r+2 ; i++ )
		{
			for ( int j = 0 ; j < c+2 ; j++ )
			{
				city[i][j] = 0 ;
				cit[i][j]  = 0 ;
				if ( i==0 || j==0 || i == r+1 || j == c+1 )
				{
					city[i][j] = -1 ;
				}
				else
				{
					cin >> city[i][j] ;
				} 
			}
		} 
		int y = 0 ;
		while ( y < m )
		{
			for ( int i = 1 ; i < r+1 ; i++ )
			{
				int count ;
				for ( int j = 1 ; j < c+1 ; j++ )
				{
					count = 0 ;
					if ( city[i][j] != -1 )
					{
						int count = city[i][j] / k ;
						if ( city[i+1][j] != -1 && city[i][j] >= count )
						{
							cit[i+1][j] += count ;
							city[i][j] -=count;
						}
						if ( city[i-1][j] != -1 && city[i][j] >= count )
						{
							cit[i-1][j] += count ;
							city[i][j] -=count;
						}
						if ( city[i][j+1] != -1&& city[i][j] >= count  )
						{
							cit[i][j+1] += count;
							city[i][j] -=count;
						}
						if ( city[i][j-1] != -1 && city[i][j] >= count )
						{
							cit[i][j-1] += count ;
							city[i][j] -=count;
						}
					}
				}
			}
			for ( int i = 1 ; i < r+1 ; i++ )
			{
				for ( int j = 1 ; j < c + 1 ; j++ )
				{
					city[i][j] += cit[i][j];
					cit[i][j] = 0 ;
				}
			}
			y++; 
		}
		for ( int i = 1 ; i < r+1 ; i++ )
		{
			for ( int j = 1 ; j < c+1 ; j++ )
			{
				if ( u < city[i][j] )
				{
					u = city[i][j] ;
				}
				if ( uo > city[i][j] && city[i][j] >= 0 )
				{
					uo = city[i][j] ;
				}
			}
		}
		cout << uo << endl ;
		cout << u  << endl ; 
	}
	return 0 ;
}
