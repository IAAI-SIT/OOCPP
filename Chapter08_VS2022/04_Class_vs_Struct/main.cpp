#include <iostream>
using namespace std;

struct STime { int hour = 8; };   // 默认 public

class CTime {
public:
    void setHour(int h) { hour = h; }
    int getHour() const { return hour; }
private:
    int hour = 8;                 // class 中通常主动封装数据
};

int main() {
    STime a;
    a.hour = 10;
    CTime b;
    b.setHour(10);
    cout << a.hour << ' ' << b.getHour() << '\n';
    return 0;
}
