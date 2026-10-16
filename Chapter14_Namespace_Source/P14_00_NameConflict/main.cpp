#include <iostream>
#include "school_bad.h"

// 课堂演示：取消下一行注释，再编译。
// 两个头文件都在全局作用域定义 Student，编译会报重复定义。
// #include "lab_bad.h"

int main()
{
    Student s;
    s.show();

    std::cout << std::endl;
    std::cout << "Uncomment #include \"lab_bad.h\" to reproduce the name conflict."
              << std::endl;

    return 0;
}
