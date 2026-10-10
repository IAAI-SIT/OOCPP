#include <iostream>
#include <string>
using namespace std;

class Student 
{
public:
    Student()
    {
    }
    Student(string n) : name(n), score(0)
    {
    }
    Student(string n, double s) : name(n), score(s) 
    {
    }
    void show() const 
    {
        cout << name << ": " << score << endl;
    }
private:
    string name;
    double score;
};

class Box {
public:
    Box(int h = 10, int w = 10, int len = 10)
        : height(h), width(w), length(len) 
    {
    }
    void show() const 
    { 
        cout << height << ' ' << width << ' ' << length << endl; 
    }
private:
    int height, width, length;
};

int main()
{
    Student a;
    Student b("Tom");
    Student c("Alice", 95);
    a.show();
    b.show(); 
    c.show();

    Box b1;
    Box b2(15);
    Box b3(15, 20);
    Box b4(15, 20, 25);
    b1.show(); 
    b2.show(); 
    b3.show();
    b4.show();
    return 0;
}
