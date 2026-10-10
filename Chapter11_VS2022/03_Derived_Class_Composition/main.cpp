#include <iostream>
#include <string>
using namespace std;

class Student
{
protected:
    string name;
    double score{};

public:
    Student(string n, double s) : name(n), score(s) {}

    void showStudent() const
    {
        cout << name << ", " << score << endl;
    }
};

class Graduate : public Student
{
private:
    string topic;

public:
    Graduate(string n, double s, string t)
        : Student(n, s), topic(t) {}

    void showGraduate() const
    {
        showStudent();
        cout << "topic: " << topic << endl;
    }
};

int main()
{
    Graduate g("Alice", 92, "Retinal OCT");
    g.showGraduate();
    return 0;
}
