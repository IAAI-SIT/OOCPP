#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

int main()
{
    // 方式1：完整限定
    std::string name = "Tom";
    double score = 92.5;

    std::cout << std::left
              << std::setw(10)
              << name
              << std::right
              << std::fixed
              << std::setprecision(1)
              << std::setw(6)
              << score
              << std::endl;

    // 方式2：只引入需要的名字
    using std::cout;
    using std::endl;

    cout << "using declaration" << endl;

    // 方式3：课堂短示例中也常看到
    // using namespace std;

    std::stringstream ss;
    ss << 1001 << " " << name << " " << score;

    cout << "stringstream: "
         << ss.str()
         << endl;

    return 0;
}
