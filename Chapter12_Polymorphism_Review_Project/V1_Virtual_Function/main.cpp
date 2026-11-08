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

int main()
{
    Notification base("system");
    EmailNotification email("alice@example.com");

    Notification* p = &base;
    p->send();

    p = &email;
    p->send();

    return 0;
}
