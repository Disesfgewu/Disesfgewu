#include <iostream>
using namespace std;
int main()
{
    int arr[2] = {10, 5};
    int *p = arr;
    cout << *p++ << endl;
    cout << *(p++) << endl;
}