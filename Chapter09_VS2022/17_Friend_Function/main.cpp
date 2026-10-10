#include <iostream>
using namespace std;

class Rectangle 
{
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    friend double area(const Rectangle& r);
private:
    double width;
    double height;
};

double area(const Rectangle& r) {
    return r.width * r.height;
}

int main() {
    Rectangle r(5, 3);
    cout << "area = " << area(r) << endl;
    return 0;
}
