#include<iostream>
using namespace std;
int main()
{
    int N ;
    while ( cin >> N )
    {
        int H[N][5] = {0};
        for ( int i = 0 ; i < N ; i++ )
        {
            for ( int j = 0 ; j < 5 ; j++ )
                cin >> H[i][j];
            if ( H[i][0] < H[i][2])
            {
                int y = H[i][2]-H[i][0];
                H[i][3] += 60*y ;
            }
            if ( H[i][3]-H[i][1] >= H[i][4])
                cout << "Yes" << endl;
            else
                cout << "No"<< endl;
        }
    }
    return 0;
}
