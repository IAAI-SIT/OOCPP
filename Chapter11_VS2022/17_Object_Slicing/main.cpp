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

int main()
{
    Graduate g;
    g.name = "Tom";
    g.topic = "Medical AI";

    Student s = g;   // 只复制Student部分
    cout << "s.name = " << s.name << endl;

#if 0
    cout << s.topic << endl;  // 错误：Student没有topic
#endif
    return 0;
}
