
// 題目 : Zerojudge a453: TOI2010 第一題：一元二次方程式 
// AC (6ms, 340KB) 
#include <iostream>
#include <cmath>
using namespace std;

float N , a , b , c ; // 宣告全域變數 型態為 float  

int main ()
{
	cin >> N ;
	while ( N-- )
	{
		cin >> a >> b >> c ;
		float p = pow(b,2) - 4*a*c ;
		int sq = sqrt(p);           // 利用 int 截掉開根號後小數點的部分 
		if ( sq * sq == p )         // if 截掉後平方 == 原始開根號之前 
			cout << "Yes" << endl;  // 表示確實為有理數 
		else
			cout << "No" << endl;
	}
	return 0 ;
}
