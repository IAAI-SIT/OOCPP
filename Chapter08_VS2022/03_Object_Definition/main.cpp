#include <iostream>
using namespace std;

class Counter {
public:
    void add() { ++value; }
    int get() const { return value; }
private:
    int value{};
};

int main() {
    Counter c1;
    Counter c2;
    c1.add(); c1.add();
    c2.add();
    cout << "c1=" << c1.get() << ", c2=" << c2.get() << '\n';
    return 0;
}
