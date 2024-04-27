#include<bits/stdc++.h>

using namespace std;



int main()

{

    int year;



    // ­«½Æ¿é¤J

    while (cin >> year)

    {

        year -= 1804 - 60;

        year %= 60;

        switch (year % 10)

        {

            case 0: cout << "¥Ò"; break;

            case 1: cout << "¤A"; break;

            case 2: cout << "¤ş"; break;

            case 3: cout << "¤B"; break;

            case 4: cout << "¥³"; break;

            case 5: cout << "¤v"; break;

            case 6: cout << "©°"; break;

            case 7: cout << "¨¯"; break;

            case 8: cout << "¤Ğ"; break;

            case 9: cout << "¬Ñ"; break;

        }



        switch (year % 12)

        {

            case 0: cout << "¤l"; break;

            case 1: cout << "¤¡"; break;

            case 2: cout << "±G"; break;

            case 3: cout << "¥f"; break;

            case 4: cout << "¨°"; break;

            case 5: cout << "¤x"; break;

            case 6: cout << "¤È"; break;

            case 7: cout << "¥¼"; break;

            case 8: cout << "¥Ó"; break;

            case 9: cout << "¨»"; break;

            case 10: cout << "¦¦"; break;

            case 11: cout << "¥è"; break;

        }

        cout << '\n';

    }

    

    return 0;

}
