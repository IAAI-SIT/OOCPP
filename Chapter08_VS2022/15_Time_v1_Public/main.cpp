#include <iostream>
using namespace std;

class Time {
public:
    int hour{};
    int minute{};
    int second{};
};

int main() {
    Time t;
    t.hour = 100;     // 可以编译：这正是问题所在
    t.minute = -5;
    t.second = 80;
    cout << t.hour << ':' << t.minute << ':' << t.second << '\n';
    return 0;
}
