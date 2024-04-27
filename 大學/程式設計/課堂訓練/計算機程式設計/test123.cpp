#include <iostream>
using namespace std;
class Student
{
private:
    string name;
    int point;

public:
    void show()
    {
        cout << "123" << endl;
        cout << "number";
        cin >> name;
    }
    void print()
    {
        cout << "Enter point";
        cin >> point;
    }
    void gogo()
    {
        cout << name << endl;
        cout << point << endl;
    }
};
int main()
{
    Student stu1;
    stu1.show();
    stu1.print();
    return 0;
}