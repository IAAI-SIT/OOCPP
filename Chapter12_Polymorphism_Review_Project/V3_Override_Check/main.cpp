#include <iostream>
#include <string>
using namespace std;

class Notification
{
protected:
    string target;

public:
    Notification(string t)
        : target(t)
    {
    }

    virtual void send() const
    {
        cout << "Generic notification to " << target << endl;
    }
};

class AppNotification : public Notification
{
public:
    AppNotification(string t)
        : Notification(t)
    {
    }

    // 错误写法：void send() override
    // 少了 const，函数声明与基类虚函数不一致，编译器会报错。
    void send() const override
    {
        cout << "App push to " << target << endl;
    }
};

int main()
{
    AppNotification app("user_001");

    Notification* p = &app;
    p->send();

    return 0;
}
