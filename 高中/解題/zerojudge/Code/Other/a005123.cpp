#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    printf("Enter : ");
    int nums[4] = {0};
    for (int i = 0; i < 4; ++i)
        scanf("%d", &nums[i]);
    int first = 0;
    int end = 4;
    int target = 5;
    while (first <= end)
    {
        int mid = (first + end) / 2;
        // if (first == end)
        // {
        //     if (nums[mid] < target)
        //     {
        //         cout << end + 1 << endl;
        //         system("pause");
        //         return 0;
        //     }
        //     else
        //     {
        //         cout << end << endl;
        //         system("pause");
        //         return 0;
        //     }
        // }
        if (nums[mid] < target)
        {
            end = mid - 1;
        }
        else if (nums[mid] == target)
        {
            printf("%d\n", mid);
            system("pause");
            return 0;
        }
        else
        {
            first = mid + 1;
        }
    }
}