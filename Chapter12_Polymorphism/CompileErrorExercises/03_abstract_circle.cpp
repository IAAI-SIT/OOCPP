// 预期编译失败：Circle::area() 缺少 const，Circle 仍是抽象类。
class Shape { public: virtual double area() const = 0; };
class Circle : public Shape { public: double area() { return 0; } };
int main() { Circle c; return 0; }
