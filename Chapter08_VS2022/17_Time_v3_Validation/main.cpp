#include <iostream>
using namespace std;

class Time {
public:
    bool setTime(int h, int m, int s) {
        if (h < 0 || h > 23 || m < 0 || m > 59 || s < 0 || s > 59)
            return false;
        hour = h; minute = m; second = s;
        return true;
    }
    void show() const { cout << hour << ':' << minute << ':' << second << '\n'; }
private:
    int hour{};
    int minute{};
    int second{};
};

int main() {
    Time t;
    const int tests[][3] = {{12,30,45},{23,59,59},{24,0,0},{-1,20,30},{12,60,0}};
    for (const auto& x : tests) {
        bool ok = t.setTime(x[0], x[1], x[2]);
        cout << x[0] << ':' << x[1] << ':' << x[2] << " -> " << (ok ? "valid" : "invalid") << '\n';
    }
    return 0;
}
