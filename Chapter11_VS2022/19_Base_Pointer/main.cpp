#include <iostream>
using namespace std;

class Student
{
public:
    void show() const
    {
        cout << "Student" << endl;
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
    Student* p = &g;     // 基类指针指向派生类对象

    p->show();           // 正确：Student接口
#if 0
    p->research();       // 错误：p的静态类型是Student*
#endif
    return 0;
}
