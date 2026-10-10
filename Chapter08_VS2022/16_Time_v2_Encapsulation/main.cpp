#include <iostream>
using namespace std;

class Time {
public:
    void setTime(int h, int m, int s) {
        hour = h; minute = m; second = s;
    }
    void show() const { cout << hour << ':' << minute << ':' << second << '\n'; }
private:
    int hour{};
    int minute{};
    int second{};
};

int main() {
    Time t;
    t.setTime(12, 30, 45);
    t.show();
    return 0;
}
