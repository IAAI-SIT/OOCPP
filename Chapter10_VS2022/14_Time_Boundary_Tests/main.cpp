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

void showCase(const char* title, const Time& t)
{
    cout << title;
    t.display();
    cout << endl;
}

int main()
{
    Time t1(34, 58);
    ++t1;
    showCase("34:58 -> ", t1);

    Time t2(34, 59);
    ++t2;
    showCase("34:59 -> ", t2);

    Time t3(34, 58);
    ++t3;
    ++t3;
    showCase("34:58 + two increments -> ", t3);

    Time t4(34, 59);
    Time a = ++t4;
    showCase("prefix result a = ", a);
    showCase("prefix object t4 = ", t4);

    Time b = t4++;
    showCase("postfix result b = ", b);
    showCase("postfix object t4 = ", t4);

    return 0;
}
