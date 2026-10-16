# 第14章 C++工具——命名空间：课堂源代码

本 Solution 对应当前 27 页《第14章 C++工具——命名空间_实践AI版》PPT。

## 项目与PPT对应

| Project | 课堂内容 | 对应PPT |
|---|---|---|
| P14_00_NameConflict | 两个头文件都在全局作用域定义 Student，复现同名冲突 | 第4–5页 |
| P14_01_NamespaceSolution | 用 school / lab 命名空间解决 Student 同名问题 | 第6–7页 |
| P14_02_NamespaceMembers | 命名空间中的变量、函数、类；A:: / B:: | 第8–10页 |
| P14_03_UsingDeclaration | using school::Student；只引入一个名字 | 第13–14页 |
| P14_04_UsingNamespace | using namespace school；一次引入整个命名空间 | 第15页 |
| P14_05_Ambiguity | 两个 using namespace 导致 show() 二义性 | 第16–17页 |
| P14_06_UsingScope | using 声明的作用域 | 第18页 |
| P14_07_StdNamespace | std::、using声明、using namespace std | 第21–24页 |
| P14_08_IntegratedDemo | school::Student + lab::Student + std 综合 | 第25–26页 |

## 课堂使用建议

继续使用本课程统一方式：

**先预测 → 编译 / 运行 → 解释 → 验证**

### P14_00_NameConflict

默认可以编译。

在 `main.cpp` 中取消：

```cpp
// #include "lab_bad.h"
```

前面的注释，再重新生成项目，可直接看到两个全局 `Student` 的重复定义错误。

### P14_05_Ambiguity

默认可以编译。

取消：

```cpp
// show();
```

前面的注释，再编译，可直接观察 `A::show()` 和 `B::show()` 带来的二义性。

## 注意

这些工程只覆盖当前课程大纲保留的“命名空间”内容，
不包含原教材第14章中的异常处理和早期函数库。
