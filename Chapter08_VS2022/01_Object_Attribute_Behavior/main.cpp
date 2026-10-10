#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    string name;
    int id;
    double score;

    void display() const 
    {
        cout << "id=" << id << ", name=" << name << ", score=" << score << '\n';
    }
};

int main()
{
    Student s;
    s.id = 1001;
    s.name = "Alice";
    s.score = 88.5;
    s.display();
    return 0;
}
