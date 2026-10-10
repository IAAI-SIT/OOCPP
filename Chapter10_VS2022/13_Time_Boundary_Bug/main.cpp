#include <iostream>
using namespace std;

class Time
{
public:
    Time(int m = 0, int s = 0)
        : minute(m), second(s)
    {
    }

    // 故意保留的边界 Bug：second 从 59 变成 60 时，60 > 60 为假。
    Time operator++()
    {
        ++second;
        if (second > 60)   // 应改为 >= 60
        {
            second = 0;
            ++minute;
        }
        return *this;
    }

    void display() const
    {
        cout << minute << ":" << second << endl;
    }

private:
    int minute;
    int second;
};

int main()
{
    Time t(34, 59);
    ++t;

    cout << "Bug result: ";
    t.display();          // 34:60

    return 0;
}
