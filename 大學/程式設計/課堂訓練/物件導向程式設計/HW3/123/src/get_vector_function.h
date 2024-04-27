#include <vector>
#include <sstream>
using namespace std;
vector<double> get_vector(string s)
{
    stringstream ss;
    vector<double> get;
    ss << s;
    double number;
    while (ss >> number)
    {
        get.push_back(number);
    }
    return get;
}