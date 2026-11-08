#include <iostream>
#include <string>
using namespace std;

class Notification
{
protected:
    string target;
    string text;

public:
    Notification(string t, string x)
        : target(t), text(x)
    {
    }

    virtual void send() const = 0;

    void showSummary() const
    {
        cout << target << ": " << text << endl;
    }

    virtual ~Notification()
    {
    }
};

class EmailNotification : public Notification
{
public:
    EmailNotification(string t, string x)
        : Notification(t, x)
    {
    }

    void send() const override
    {
        cout << "[Email] " << target << " <- " << text << endl;
    }
};

class SmsNotification : public Notification
{
public:
    SmsNotification(string t, string x)
        : Notification(t, x)
    {
    }

    void send() const override
    {
        cout << "[SMS] " << target << " <- " << text << endl;
    }
};

void dispatch(const Notification& n)
{
    n.showSummary();
    n.send();
}

int main()
{
    // Notification n("target", "hello");
    // 编译错误：抽象类不能直接创建对象。

    EmailNotification email("alice@example.com", "Meeting");
    SmsNotification sms("13800000000", "Code");

    dispatch(email);
    dispatch(sms);

    return 0;
}
