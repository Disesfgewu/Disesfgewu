#include <iostream>
using namespace std;

int main ()
{
	cin.tie( NULL ) ;
	cout.tie( NULL ) ;
	int n , p1[6] = {0} , p2[5] = {0} , total = 0 ;
	while ( 1 )
	{
		int num ;
		cin >> n ;
		if ( n == 0 )
		{
			cout << "Total: " << total << endl;
			break ;
		}
		else if ( n == 1 )
		{
			cin >> num ;
		//	cout << "dfghjkl3456" << endl ;
			if ( num == 1 )
			{
				total += 4 ;
				p1[1] = 4 ;
				cout << "Medium Wac " << p1[1] << endl;
		//		cout << p1[1] << endl;
			}
			else if ( num == 2 )
			{
				total += 8 ;
				p1[2] = 8 ;
				cout << "WChicken Nugget " << p1[2] << endl;
			}
			else if ( num == 3 )
			{
				total += 7 ;
				p1[3] = 7 ;
				cout << "Geez Burger " << p1[3] << endl;
			}
			else if ( num == 4 )
			{
				total += 6 ;
				p1[4] = 6 ;
				cout << "ButtMilk Crispy Chicken " << p1[4] << endl;
			}
			else 
			{
				total += 3 ;
				p1[5] = 3 ;
				cout << "Plastic Toy " << p1[5] << endl;
			}
		}
		else
		{
			cin >> num ;
			if ( num == 1 )
			{
				total += 2 ;
				p2[1] = 2 ;
				cout << "German Fries " << p2[1] << endl;
			}
			else if ( num == 2 )
			{
				total += 3 ;
				p2[2] = 3 ;
				cout << "Durian Slices " << p2[2] << endl;
			}
			else if ( num == 3 )
			{
				total += 5 ;
				p2[3] = 5 ;
				cout << "WcFurry " << p2[3] << endl;
			}
			else
			{
				total += 7 ;
				p2[4] = 7 ;
				cout << "Chocolate Sunday " << p2[4] << endl;
			}
		}
	}
}
