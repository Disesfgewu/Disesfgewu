#include <iostream>
#include <string>
using namespace std;
bool continue_or_quit()
{
    string s;
    cout << "\nPlease type 'c' to continue, anything else to quit:\n";
    getline(cin, s);
    if (s[0] == 'c')
        return true;
    else
    {
        cout << "See ya!\n";
        return false;
    }
}