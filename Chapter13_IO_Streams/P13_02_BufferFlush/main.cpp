#include <iostream>
using namespace std;
int main()
{
    char buf[1024] = {};

    // 必须在任何 cout 输出之前设置
    setvbuf(stdout, buf, _IOFBF, sizeof(buf));

    cout << "A";          // ① 先进入缓冲区
    int p1 = 0;           // 在这里停住：通常看不到 A

    cout << flush;        // ② 显式刷新
    int p2 = 0;           // 在这里停住：应看到 A

    cout << "B\n";        // ③ 只有换行，没有显式 flush
    int p3 = 0;           // 停住观察

    cout << "C" << endl;  // ④ 换行 + flush
    int p4 = 0;           // 应看到 B 和 C

    return 0;
}
