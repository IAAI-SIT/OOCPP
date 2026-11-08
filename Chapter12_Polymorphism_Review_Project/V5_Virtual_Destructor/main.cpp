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

    virtual void send() const = 0;

    virtual ~Notification()
    {
        cout << "Notification dtor" << endl;
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

    ~EmailNotification() override
    {
        cout << "EmailNotification dtor" << endl;
    }
};

int main()
{
    Notification* p = new EmailNotification("alice@example.com");

    p->send();
    delete p;

    return 0;
}
