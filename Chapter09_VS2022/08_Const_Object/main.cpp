#include <iostream>
using namespace std;

class Time 
{
public:
    Time(int h, int m, int s) : hour(h), minute(m), second(s) 
    {
    }
    void setTime(int h, int m, int s)
    {
        hour=h;
        minute=m;
        second=s;
    }
    void show() const
    {
        cout << hour << ':' << minute << ':' << second << endl;
    }
private:
    int hour, minute, second;
};

int main()
{
    const Time t(10, 20, 30);
    t.show();
    // t.setTime(12, 0, 0); // 错误：不能通过常对象调用非const成员函数
    return 0;
}
