#include <iostream>

namespace school
{
    class Student
    {
    public:
        void show() const
        {
            std::cout << "school::Student" << std::endl;
        }
    };

    void print()
    {
        std::cout << "school::print()" << std::endl;
    }
}

namespace lab
{
    class Student
    {
    public:
        void show() const
        {
            std::cout << "lab::Student" << std::endl;
        }
    };
}

int main()
{
    using school::Student;

    Student s;
    s.show();

    // using 声明只引入了 school::Student。
    // school::print 仍然需要完整限定。
    school::print();

    // lab::Student 没有被引入，所以仍然写 lab::Student。
    lab::Student t;
    t.show();

    return 0;
}
