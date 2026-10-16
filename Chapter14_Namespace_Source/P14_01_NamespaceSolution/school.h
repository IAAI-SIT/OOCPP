#pragma once
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

    inline void print()
    {
        std::cout << "school::print()" << std::endl;
    }
}
