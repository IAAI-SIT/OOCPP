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
    Time t(34, 59);

    cout << "before: ";
    t.display();
    cout << endl;

    ++t;

    cout << "after ++t: ";
    t.display();
    cout << endl;

    return 0;
}
