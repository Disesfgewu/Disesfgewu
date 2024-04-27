#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    int n;
    vector<int> d;
    for (int i = 0; i <= 2 * (int)pow(10, 9); ++i)
    {
        d.push_back(i * i);
    }
    while (cin >> n)
    {
        if (n == 0)
            break;
        vector<int>::iterator it = upper_bound(d.begin(), d.end(), n);
        vector<int>::iterator it2 = lower_bound(d.begin(), d.end(), n);
        cout << it - d.begin() << " " << it2 - d.begin() << endl;
    }
}