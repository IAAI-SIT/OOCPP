// 预期编译失败：show() 没有重写 show() const。
class Base { public: virtual void show() const {} };
class Derived : public Base { public: void show() override {} };
int main() { return 0; }
