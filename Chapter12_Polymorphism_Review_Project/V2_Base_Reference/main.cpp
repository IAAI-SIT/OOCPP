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

class EmailNotification : public Notification
{
public:
    EmailNotification(string t)
        : Notification(t)
    {
    }

    void send() const override
    {
        cout << "Email to " << target << endl;
    }
};

class SmsNotification : public Notification
{
public:
    SmsNotification(string t)
        : Notification(t)
    {
    }

    void send() const override
    {
        cout << "SMS to " << target << endl;
    }
};

void dispatch(const Notification& n)
{
    n.send();
}

int main()
{
    EmailNotification email("alice@example.com");
    SmsNotification sms("13800000000");

    dispatch(email);
    dispatch(sms);

    return 0;
}
