#pragma once
#include <iostream>

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

    inline void print()
    {
        std::cout << "lab::print()" << std::endl;
    }
}
