#include <iostream>
using namespace std;

class Buffer {
public:
    Buffer(int v) {
        value = new int(v);
    }
    ~Buffer() {
        delete value;
    }
    void show() const { cout << *value << endl; }
private:
    int* value;
};

int main() {
    cout << "This example demonstrates the risk only." << endl;
    cout << "Do not copy Buffer with the compiler-generated copy constructor." << endl;
    cout << "A shallow copy would make two objects own the same address." << endl;
    return 0;
}
