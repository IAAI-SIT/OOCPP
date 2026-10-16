#include <iostream>

namespace A
{
    void show()
    {
        std::cout << "A::show()" << std::endl;
    }
}

namespace B
{
    void show()
    {
        std::cout << "B::show()" << std::endl;
    }
}

int main()
{
    using namespace A;
    using namespace B;

    // 课堂演示：
    // 取消下一行注释，编译器无法判断调用 A::show 还是 B::show。
    //
    // show();

    A::show();
    B::show();

    return 0;
}
