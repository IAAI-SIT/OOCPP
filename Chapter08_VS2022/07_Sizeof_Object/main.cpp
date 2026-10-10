#include <iostream>
using namespace std;

class Time {
public:
    void show() const { cout << hour << ':' << minute << ':' << second << '\n'; }
private:
    int hour{};
    int minute{};
    int second{};
};

int main() {
    Time t;
    cout << "sizeof(Time) = " << sizeof(Time) << " bytes\n";
    cout << "对象保存数据成员；成员函数代码不会为每个对象复制一份。\n";
    return 0;
}
