#include <iostream>
using namespace std;

class Student {
public:
    void setScore(double s) { score = s; }
    void display() const { cout << "score=" << score << '\n'; }
private:
    double score{};
};

int main() {
    Student s;
    Student& r = s;
    r.setScore(90);
    s.display();
    r.display();
    return 0;
}
