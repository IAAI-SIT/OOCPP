#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    string name;
};

class Graduate : public Student
{
public:
    string topic;
};

void showStudent(const Student& s)
{
    cout << s.name << endl;
}

int main()
{
    Graduate g;
    g.name = "Alice";
    g.topic = "OCTA";

    showStudent(g);   // public继承下合法
    return 0;
}
