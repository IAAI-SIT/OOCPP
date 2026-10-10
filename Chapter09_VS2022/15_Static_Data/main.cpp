#include <iostream>
using namespace std;

class Student {
public:
    Student() { ++count; }
    ~Student() { --count; }
    static int getCount() { return count; }
private:
    static int count;
};

int Student::count = 0;

int main()
{
    cout << Student::getCount() << endl;
    {
        Student a;
        Student b;
        cout << Student::getCount() << endl;
    }
    cout << Student::getCount() << endl;
    return 0;
}
