#include <iostream>
using namespace std;

class Student {
public:
    bool setScore(double s) {
        if (!isValidScore(s)) return false;
        score = s;
        return true;
    }
    double getScore() const { return score; }
private:
    bool isValidScore(double s) const { return s >= 0 && s <= 100; }
    double score{};
};

int main() {
    Student s;
    for (double x : {95.0, -10.0, 105.0}) {
        cout << "set " << x << " -> " << boolalpha << s.setScore(x)
             << ", current=" << s.getScore() << '\n';
    }
    return 0;
}
