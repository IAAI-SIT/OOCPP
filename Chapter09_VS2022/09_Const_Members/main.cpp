#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    Student(int i, string n, double s)
        : id(i), name(n), score(s) 
    {
    }

    int getId() const
    {
        return id;
    }
    double getScore() const
    {
        return score;
    }
    void setScore(double s)
    {
        score = s;
    }

    void show() const
    {
        cout << id << ' ' << name << ' ' << score << endl;
    }
private:
    const int id;
    string name;
    double score;
};

int main() 
{
    Student a(1001, "Tom", 90);
    const Student b(1002, "Alice", 95);

    a.setScore(92);
    a.show();
    b.show();
    cout << "b.id = " << b.getId() << endl;
    // b.setScore(96); // 错误：常对象不能调用非const成员函数
    return 0;
}
