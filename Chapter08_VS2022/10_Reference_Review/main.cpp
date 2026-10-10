#include <iostream>
using namespace std;

void addOne(int& x) { ++x; }

int main() {
    int a = 10;
    int& r = a;
    cout << "a=" << a << ", r=" << r << '\n';
    r = 20;
    cout << "after r=20, a=" << a << '\n';
    addOne(a);
    cout << "after addOne(a), a=" << a << '\n';
    return 0;
}
