#include <iostream>
using namespace std;

class Student {
public:
    bool setScore(double s) {
        if (s < 0 || s > 100) return false;
        score = s;
        return true;
    }
    double getScore() const { return score; }
private:
    double score{};
};

int main() {
    Student s;
    cout << boolalpha << s.setScore(95) << "  score=" << s.getScore() << '\n';
    cout << boolalpha << s.setScore(-10) << "  score=" << s.getScore() << '\n';
    return 0;
}
