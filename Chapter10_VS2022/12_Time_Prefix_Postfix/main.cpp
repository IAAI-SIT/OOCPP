#include <iostream>
using namespace std;

class Time
{
public:
    Time(int m = 0, int s = 0)
        : minute(m), second(s)
    {
    }

    Time operator++()
    {
        ++second;
        if (second >= 60)
        {
            second = 0;
            ++minute;
        }
        return *this;
    }

    Time operator++(int)
    {
        Time old = *this;
        ++(*this);
        return old;
    }

    void display() const
    {
        cout << minute << ":";
        if (second < 10)
            cout << "0";
        cout << second;
    }

private:
    int minute;
    int second;
};

int main()
{
    Time t(34, 59), a, b;

    a = ++t;
    cout << "after a = ++t" << endl;
    cout << "t = ";
    t.display();
    cout << ", a = ";
    a.display();
    cout << endl;

    b = t++;
    cout << "after b = t++" << endl;
    cout << "t = ";
    t.display();
    cout << ", b = ";
    b.display();
    cout << endl;

    return 0;
}
