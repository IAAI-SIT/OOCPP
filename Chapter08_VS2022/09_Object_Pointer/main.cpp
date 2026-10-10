#include <iostream>
using namespace std;

class Time {
public:
    void setHour(int h) { hour = h; }
    void show() const { cout << "hour=" << hour << '\n'; }
private:
    int hour{};
};

int main() {
    Time t;
    Time* p = &t;
    p->setHour(12);
    p->show();
    (*p).show();       // 与 p->show() 等价
    return 0;
}
