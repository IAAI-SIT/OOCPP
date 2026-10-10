#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    Student() : name("unknown"), score(0) 
    {
    }
    Student(string n, double s) : name(n), score(s) 
    {
    }
    void show() const
    { 
        cout << name << ": " << score << endl;
    }
    double getScore() const 
    {
        return score; 
    }
private:
    string name;
    double score;
};

int main() 
{
    Student students[3] = 
    {
        Student("Tom", 90),
        Student("Alice", 95),
        Student("Bob", 82)
    };

    double sum = 0;
    for (int i = 0; i < 3; ++i)
    {
        students[i].show();
        sum += students[i].getScore();
    }
    cout << "average = " << sum / 3 << endl;
    return 0;
}
