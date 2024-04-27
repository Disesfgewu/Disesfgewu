#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
using namespace std;
int main()
{
    srand(time(NULL));
    int i = rand() % 2 + 1;
    if (i == 1)
        cout << "1 芳哥\n2 錦\n";
    else
        cout << "1 錦\n2 芳哥\n";
    return 0;
}