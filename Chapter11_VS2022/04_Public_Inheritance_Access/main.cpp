#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    void study() const { cout << "study" << endl; }

protected:
    int score{};

private:
    string password = "secret";
};

class Graduate : public Student
{
public:
    void test()
    {
        study();       // 正确：基类public成员
        score = 90;    // 正确：基类protected成员
        cout << "score = " << score << endl;

#if 0
        password = "123"; // 错误：不能直接访问基类private成员
#endif
    }
};

int main()
{
    Graduate g;
    g.study();         // 正确：public继承后仍为public
    g.test();
#if 0
    cout << g.score;   // 错误：类外不能访问protected成员
#endif
    return 0;
}
