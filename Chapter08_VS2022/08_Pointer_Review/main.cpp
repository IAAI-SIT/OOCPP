#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int* p = &a;
    cout << "a=" << a << '\n';
    cout << "&a=" << &a << '\n';
    cout << "p=" << p << '\n';
    cout << "*p=" << *p << '\n';
    *p = 20;
    cout << "after *p=20, a=" << a << '\n';
    return 0;
}
