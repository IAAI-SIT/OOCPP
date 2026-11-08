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

class AppNotification : public Notification
{
public:
    AppNotification(string t, string x)
        : Notification(t, x)
    {
    }

    void send() const override
    {
        cout << "[App] " << target << " <- " << text << endl;
    }
};

class VoiceNotification : public Notification
{
public:
    VoiceNotification(string t, string x)
        : Notification(t, x)
    {
    }

    void send() const override
    {
        cout << "[Voice] " << target << " <- " << text << endl;
    }
};

void dispatch(const Notification& n)
{
    n.showSummary();
    n.send();
}

int main()
{
    // 假设输入合法，1 <= n <= 10。
    // 每条输入：类型 目标 消息
    // 类型：E / S / A / V，消息不含空格。

    Notification* queue[10];

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        char type;
        string target;
        string text;

        cin >> type >> target >> text;

        if (type == 'E')
        {
            queue[i] = new EmailNotification(target, text);
        }
        else if (type == 'S')
        {
            queue[i] = new SmsNotification(target, text);
        }
        else if (type == 'A')
        {
            queue[i] = new AppNotification(target, text);
        }
        else
        {
            queue[i] = new VoiceNotification(target, text);
        }
    }

    for (int i = 0; i < n; ++i)
    {
        dispatch(*queue[i]);
    }

    for (int i = 0; i < n; ++i)
    {
        delete queue[i];
    }

    return 0;
}
