#include<iostream>
using namespace std;

int main()
{
    char c;

    while(true)
    {
        c = cin.get();
        cout << "得到字元[" << c << "]  ASCII編號 [" << (int)c << "]" << endl;
    }

    return 0;
}
