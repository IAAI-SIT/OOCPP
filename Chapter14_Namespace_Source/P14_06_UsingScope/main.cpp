#include <iostream>

namespace school
{
    class Student
    {
    public:
        Student(int n)
        {
            id = n;
        }

        void show() const
        {
            std::cout << "school::Student, id = "
                      << id
                      << std::endl;
        }

    private:
        int id;
    };
}

void f()
{
    using school::Student;

    Student s(1001);
    s.show();
}

void g()
{
    // f() 中的 using 声明不会影响这里。
    school::Student s(1002);
    s.show();

    // 如果写成下面这样会编译失败：
    // Student t(1003);
}

int main()
{
    f();
    g();

    return 0;
}
