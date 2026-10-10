#include <iostream>
using namespace std;

class Rectangle
{
public:
    Rectangle(int l, int w)
        : length(l), width(w)
    {
    }

    bool operator==(const Rectangle& r) const
    {
        return length == r.length &&
               width == r.width;
    }

    bool operator!=(const Rectangle& r) const
    {
        return !(*this == r);
    }

private:
    int length;
    int width;
};

int main()
{
    Rectangle r1(3, 4);
    Rectangle r2(3, 4);
    Rectangle r3(3, 5);
    Rectangle r4(4, 3);

    cout << boolalpha;
    cout << "r1 == r2 : " << (r1 == r2) << endl;
    cout << "r1 != r3 : " << (r1 != r3) << endl;
    cout << "r1 == r4 : " << (r1 == r4) << endl;

    return 0;
}
