#include <iostream>
using namespace std;
int main ()
{
	int i , j ;
	while (cin >> i >> j)
	{
		int arrT[j][i];
		for (int a = 0 ; a < i ; a++)
		{
			for (int b =0 ; b < j ; b++)
			{
				cin >> arrT[b][a];
			}
		}
		for (int a = 0 ; a < j ; a++)
		{
			for (int b =0 ; b < i ; b++)
			{
				cout << arrT[a][b]<< " ";
			}
			cout << '\n';
		}
	}
 } 
