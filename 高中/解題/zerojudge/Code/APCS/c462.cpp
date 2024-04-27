#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main()
{
    string s;
    int k;
    while(cin >> k){
        cin >> s;
        int length = s.length();
        int count1 = 0 , count2 = 0 , len = 0 , flen = 0;
        bool b ;
        if ( isupper ( s[0] ) )
		{
            b = true ;
            count2 ++ ;
            if ( count2== k )
			{
                len = k ;
                flen = max ( flen , len ) ;
            }
        }
		else
		{
            b = false ;
            count1 ++ ;
            if ( count1 == k )
			{	
                len = k ;
                flen = max ( flen , len ) ;
            }
        }
        for( int i = 1 ; i < length ; i++ )
		{
            if ( isupper ( s[i] ) && b ) 
			{
                count1 ++ ;
                count2 = 0 ;
                if ( count1 == k )
				{
                    len += k ;
                    flen = max ( flen , len ) ;
                }
                if ( count1 > k){
                    len = k;
                }
            }
			else if ( isupper ( s[i] ) && ( ! b ) ) 
			{
                if ( count2 < k )
				{
                    len = 0;
                }
                count2 = 1 ; 
                count1 = 0 ;
                if ( count2 == k )
				{
                   	len += k;
              		flen = max( flen , len ) ;
               		b = true ;
				}
				else if ( islower( s[i] ) && ( ! b ) ) 
				{
                	count2 = 0 ;
                	if ( count1 == k )
					{
                    	len += k ;
                   		flen = max ( flen , len ) ;
                	}
                	if ( count1 > k )
					{
                    	len = k;
                	}
            	}
            }
			else if ( islower ( s[i] ) && ( b ) ) 
			{
                if ( count2 < k )
				{
                    len = 0;
                }
                count1 = 1 ;
                count2 = 0 ;
                if ( count1 == k)
				{
                    len += k ;
                    flen = max ( flen , len ) ;
                }
                b = false ;
            }
        }
        cout << flen << endl;
    }
}
