#include <vector>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    cout << "***INNER PRODUCT CALCULATOR***\n";
    while (true)
    {
        string vec1, vec2;
        vector<double> vector1;
        vector<double> vector2;
        while (true)
        {
            cout << "\nPlease enter first vector:\n";
            getline(cin, vec1);
            vector1 = get_vector(vec1);
            if (vector1[0] <= 0)
            {
                cout << "\nDimension must be an integer greater than 0\n";
                continue;
            }
            else if (int(vector1[0]) + 1 < vector1.size())
            {
                cout << "\nMuch data than expected\n";
                continue;
            }
            else if (int(vector1[0]) + 1 > vector1.size())
            {
                cout << "\nFewer data than expected\n";
                continue;
            }
            else
                break;
        }
        while (true)
        {
            cout << "\nPlease enter second vector:\n";
            getline(cin, vec2);
            vector2 = get_vector(vec2);
            if (vector2[0] <= 0)
            {
                cout << "\nDimension must be an integer greater than 0\n";
                continue;
            }
            else if (int(vector2[0]) + 1 < vector2.size())
            {
                cout << "\nMuch data than expected\n";
                continue;
            }
            else if (int(vector2[0]) + 1 > vector2.size())
            {
                cout << "\nFewer data than expected\n";
                continue;
            }
            else
                break;
        }
        double ans;
        if (vector1.size() == vector2.size())
            ans = show_result(vector1, vector2);
        else
            cout << "\nIllegal: only vectors with same dimensionality have an inner product\n";
        if (!continue_or_quit())
            break;
    }
    return 0;
}