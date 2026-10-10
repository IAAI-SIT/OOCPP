#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    Student(string n = "unknown", double s = 0)
        : name(n), score(s) {
        ++count;
        cout << "construct " << name << endl;
    }

    Student(const Student& other)
        : name(other.name), score(other.score) {
        ++count;
        cout << "copy construct " << name << endl;
    }

    ~Student() {
        cout << "destruct " << name << endl;
        --count;
    }

    void setScore(double score) { this->score = score; }
    double getScore() const { return score; }
    void show() const { cout << name << ": " << score << endl; }

    static int getCount() { return count; }
    friend double scoreOf(const Student& s);

private:
    string name;
    double score;
    static int count;
};

int Student::count = 0;

double scoreOf(const Student& s) {
    return s.score;
}

int main() {
    cout << "count = " << Student::getCount() << endl;

    Student students[3] = {
        Student("Tom", 90), Student("Alice", 95), Student("Bob", 82)
    };

    Student* p = &students[0];
    p->setScore(91);

    const Student& ref = students[1];
    ref.show();

    Student copy = students[2];
    copy.show();
    cout << "friend score = " << scoreOf(copy) << endl;
    cout << "count = " << Student::getCount() << endl;

    return 0;
}
