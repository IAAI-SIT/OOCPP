#include <iostream>
using namespace std;

class Student {
public:
    Student() 
    { 
        ++count; 
    }
    ~Student() 
    {
        --count;
    }

    static int getCount() 
    {
        return count;
    }
private:
    static int count;
};

int Student::count = 0;

int main() 
{
    cout << "before: " << Student::getCount() << endl;
    Student a;
    Student b;
    cout << "inside: " << Student::getCount() << endl;
    b.getCount();
    
    return 0;
}
