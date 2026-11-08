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

    void send() const
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

    void send() const
    {
        cout << "Email to " << target << endl;
    }
};

int main()
{
    EmailNotification email("alice@example.com");

    email.send();

    Notification* p = &email;
    p->send();

    return 0;
}
