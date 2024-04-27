#include <bits/stdc++.h>
using namespace std;
int main (){
	
	int n ;
	while ( cin >> n )
	{
		priority_queue<int, vector<int> , greater<int> > pq ;
		int c ;
		for ( int i = 0 ; i < n ; i++ )
		{
			cin >> c ;
			pq.push(c);
		}
		for ( int i = 0 ; i < n ; i++ )
		{
			cout << pq.top() << " ";
			pq.pop();
		}
		cout << '\n';
	}
	return 0 ;
} 
