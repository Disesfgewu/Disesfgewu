#include <iostream>

using namespace std ;
const int nmax = 10000 ;
int Binary[nmax] ;   // 儲存原陣列 
int n ;             // 儲存的數字數量 

bool Binary_search( int tmp )  // tmp 是 尋找值 
{
	int max = n-1 , min = 0 ;
	while ( max > min ) 
	{
		int mid = ( max + min ) / 2 ;
		if ( Binary[ mid ] < tmp ) //當中心的位置<tmp代表tmp在陣列的右邊 
			min += mid + 1 ;  
		else if ( Binary[ mid ] > tmp ) // 反之 則代表在 左邊的陣列 
			max = mid ; 
		else 			// 代表 ( Binary[mid] == tmp ) 找到了 回傳true  
			return true ;
	}
	return false ;      // 代表tmp不在陣列之中 回傳false 
}

int main ()
{	
	cin >> n ;
	for ( int i = 0 ; i < n ; i++ )
	{
		cin >> Binary[i] ;   // 輸入陣列元素 
	}
	int find_point ;
	cin >> find_point ;      // 輸入要尋找的數字（元素） 
	if ( Binary_search( find_point ) ) cout << "Yes\n" ;
	else	cout << "No\n" ; 
	return 0 ;
} 
