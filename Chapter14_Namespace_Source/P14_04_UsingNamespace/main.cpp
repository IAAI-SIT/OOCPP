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

int main()
{
    using namespace school;

    Student s;
    s.show();

    print();

    return 0;
}
