#include <iostream>
using namespace std;

class Base
{
private:
    int score{};

public:
    void setScore(int s) { score = s; }
    int getScore() const { return score; }
};

class Derived : public Base
{
public:
    void set()
    {
#if 0
        score = 90;       // 错误：score是Base的private成员
#endif
        setScore(90);     // 正确：通过Base提供的public接口
    }
};

int main()
{
    Derived d;
    d.set();
    cout << d.getScore() << endl;
    return 0;
}
