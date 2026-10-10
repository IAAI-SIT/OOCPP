// 预期编译失败：Shape 是抽象类。
class Shape { public: virtual double area() const = 0; };
int main() { Shape s; return 0; }
