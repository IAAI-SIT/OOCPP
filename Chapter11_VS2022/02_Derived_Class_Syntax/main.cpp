#include <iostream>
using namespace std;

class Student
{
public:
    void study() const
    {
        cout << "study" << endl;
    }
};

class Graduate : public Student
{
public:
    void research() const
    {
        cout << "research" << endl;
    }
};

int main()
{
    Graduate g;
    g.study();
    g.research();
    return 0;
}
