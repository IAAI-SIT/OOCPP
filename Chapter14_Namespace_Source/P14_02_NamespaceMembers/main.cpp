#include <iostream>

namespace A
{
    int value = 10;

    void show()
    {
        std::cout << "A::show()" << std::endl;
    }

    class Demo
    {
    public:
        void print() const
        {
            std::cout << "A::Demo" << std::endl;
        }
    };
}

namespace B
{
    int value = 20;

    void show()
    {
        std::cout << "B::show()" << std::endl;
    }
}

int main()
{
    std::cout << "A::value = " << A::value << std::endl;
    std::cout << "B::value = " << B::value << std::endl;

    A::show();
    B::show();

    A::Demo d;
    d.print();

    return 0;
}
