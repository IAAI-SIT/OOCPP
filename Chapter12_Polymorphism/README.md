# 第12章 多态性与虚函数——配套源码

依据《12 多态性与虚函数_实践AI版.pptx》2026-10-02修改版（56页）编写。

## 打开和运行

1. 先将整个压缩包解压，再打开 Chapter12_Polymorphism.sln。
2. 使用安装了“使用 C++ 的桌面开发”的 Visual Studio 2022 或更新版本。
3. 在解决方案资源管理器中，右键要演示的项目，选择“设为启动项目”。
4. 按 Ctrl+F5 运行；每个项目都有独立 main.cpp，不要将多个示例合成一个项目。
5. Ex12、Ex13 需要键盘输入，格式见各项目 sample_input.txt；所有项目附 expected_output.txt。

工程使用C++14模式，源码只需C++11语法。不使用预编译头，不依赖第三方库。VS2022使用v143，VS18及以上当前配置使用v145；若本机工具集不同，在项目属性中选择已安装工具集。

## 示例与PPT对应表

| 项目 | 内容 | PPT页码 |
|---|---|---|
| Ex01_StaticPolymorphism | 函数重载与运算符重载 | 4、6、7 |
| Ex02_NonVirtual | 不加virtual：直接调用与基类指针 | 9—15 |
| Ex03_VirtualPointer | 加virtual后比较输出 | 5、16—18、20—21 |
| Ex04_VirtualReference | 基类引用的动态调用 | 19、32 |
| Ex05_Override | override与对象、指针、引用 | 22—26、29—31 |
| Ex06_InheritedVirtual | 不重写则沿用基类实现 | 27 |
| Ex07_ConstMismatch | 少了const：名称隐藏而非重写 | 28—29 |
| Ex08_VirtualDestructor | 虚析构：先派生类后基类 | 35—37 |
| Ex09_AbstractShape | 纯虚函数、具体类和统一引用接口 | 38—46 |
| Ex10_AbstractCorrection | AI任务5：修复签名不匹配 | 43 |
| Ex11_InterfaceDesign | AI任务6：纯虚接口与可复用行为 | 47 |
| Ex12_DynamicShapes | 综合案例：运行时动态创建对象 | 49—52 |
| Ex13_TriangleExtension | 综合实践：增加Triangle | 53—54 |

## 教学使用说明

- AI任务1：Ex01—Ex03；AI任务2：比较Ex02、Ex03。
- AI任务3：Ex07与CompileErrorExercises/01，对照Ex05修复。
- AI任务4：Ex08。非虚析构反例不能靠某一次运行结果证明安全。
- AI任务5：CompileErrorExercises/02、03，对照Ex10；两个实例化错误及其原因不是三个独立错误。
- AI任务6：Ex11是独立设计练习，包含draw()和showArea()；与Ex09、Ex12、Ex13的Shape定义分开。
- Ex12完整对应第50—52页，固定容量Shape* p[10]，运行时输入决定数量和实际对象类型。
- Ex13只增加Triangle类及T输入分支。最后的面积计算循环、释放循环与Ex12保持一致。
- 动态案例按PPT约定假设输入合法且读取成功：1 <= n <= 10，类型为大写C/R（扩展版另有T），尺寸为正数。为突出多态，未加入输入恢复与异常处理，不作为生产输入处理范例。
- new创建对象；virtual实现动态调用。动态多态不要求对象必须由new创建。
- Ex11中的指针指向局部对象，不能delete；Ex12/13中的指针指向new创建的对象，分别delete p[i]。局部指针数组p本身不需要delete[]。
- 每个示例的类定义独立，不把跨项目同名类混在一个程序中。

## 运行示例

Ex12输入：
```
2
C 2
R 3 4
```
输出：
```
12.5664
12
```

Ex13输入：
```
3
C 2
R 3 4
T 4 5
```
输出：
```
12.5664
12
10
```

## 验证

13个正常示例已经用本机MSVC 14.51以C++14、/W4、/utf-8编译，并逐一核对输出。动态案例还检查了n=1和n=10。故意编译错误文件不参加正常solution生成。

完整 Visual Studio solution 已在本机 VS18 / v145、Debug x64 配置下整体生成成功，生成的13个程序均通过预期输出核对。VS2022 / v143配置已提供，未在本机实测。
