#include <iostream>
using namespace std ;

int main (){
    int a[10] ;
    // Âk¹s ¥H§K ¥X¿ù  
    for ( int i = 0 ; i < 10 ; ++i )
	{
		a[i] = 0 ;
	}
    int max_num = 0 , max_index = 0 ;
    for ( int i = 0 ; i < 3 ; ++i ) 
	{
        int A ;
        cin >> A ;
        a[A]++ ;
        if ( a[A] > max_num ) 
		{
            max_num = a[A] ;
            max_index = A  ;
        }
    }
    cout << max_num << " " ;
    for ( int i = 9 ; i > 0 ; --i )
	{ 
        if ( a[i] > 0 ) 
		{ 
            cout << i << " " ;
		} 
    }
    cout << endl ;
    return 0 ;
}
