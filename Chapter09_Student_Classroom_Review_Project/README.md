# 第8-9章综合复习：从 Student 到 Classroom

适用课程：《面向对象程序设计》
建议课堂：45分钟综合复习
编译标准：C++17（Visual Studio 2022 / g++ / clang++ 均可）

## 教学主线
对象怎么设计？ → 对象怎么初始化？ → 很多对象怎么管理？ → 对象怎么查找与修改？ → 对象怎么复制？ → 对象之间怎么共享与协作？

建议按 V1 → V6 逐步演示。课堂不要从零敲完整代码，完整版本预先准备；只现场修改关键的 5~10 行。

- V1_ClassAndObject：类、对象、private/public、成员函数、类内/类外定义
- V2_Constructor_Const_This：构造函数、重载、初始化列表、this、const、引用
- V3_ObjectArray_Pointer：对象数组、对象指针、对象引用
- V4_DynamicMemory：new/delete、动态对象数组、构造/析构顺序
- V5_ShallowCopy_Demo：安全演示浅拷贝共享同一内存（故意不 delete，避免双重释放导致课堂崩溃）
- V6_Final：深拷贝、对象赋值、static、friend，形成完整复习项目


## Visual Studio Solution

已提供 `OOP_Chapter8_9_Review.sln`。在 Visual Studio 中直接打开该 solution，可看到 V1～V6 六个独立控制台项目。

建议课堂使用：
1. 在“解决方案资源管理器”中右击要演示的版本（如 `V4_DynamicMemory`）。
2. 选择“设为启动项目”。
3. 使用 `Ctrl+F5` 运行；需要观察对象生命周期时可在构造/析构函数处设置断点。
4. 课堂依次切换 V1 → V6，不需要重新创建工程。

Solution 使用 C++17，默认提供 Debug/Release × x64 配置。

## 推荐课堂编译方式
根目录：

```bash
cmake -S . -B build
cmake --build build
```

也可在 Visual Studio 2022 中直接“打开文件夹”，选择对应 target 运行。

## V5 特别说明
V5 是“故障分析版本”。两个 Classroom 的 `students` 指针指向同一块数组，所以修改 c2 会影响 c1。
为了保证课堂演示稳定，V5 故意不释放这块内存；如果两个对象都按普通析构函数 `delete[] students`，程序结束时可能发生 double free。

## 课堂建议
每个版本都先让学生“预测”，再运行验证。不要把最终版本一开始全部展示。
