#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    string name;
    int score{};

    void showStudent() const
    {
        cout << name << ", " << score << endl;
    }
};

class Graduate : public Student
{
public:
    string researchArea;

    void showGraduate() const
    {
        showStudent();
        cout << "researchArea: " << researchArea << endl;
    }
};

int main()
{
    Graduate g;
    g.name = "Tom";
    g.score = 90;
    g.researchArea = "Medical AI";
    g.showGraduate();
    return 0;
}
