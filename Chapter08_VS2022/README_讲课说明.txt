第8章《类和对象》VS2022课堂演示代码

打开：Chapter08.sln
环境：Visual Studio 2022，Platform Toolset v143，C++17，x64

建议课堂顺序：
01 Object/属性/行为
02 public/private 与封装
03 对象定义
04 class 与 struct
05 成员函数
06 类外定义成员函数与 ::
07 sizeof(Object) 小实验
08 指针快速复习
09 对象指针与 ->
10 引用快速复习
11 对象引用
12 反例：public 数据成员导致非法状态
13 封装后的 Student
14 多文件工程：Student.h + Student.cpp + main.cpp（接口与实现分离）
15 Time v1：能运行但设计不好
16 Time v2：加入封装
17 Time v3：加入数据合法性验证
18 CDate：综合案例，衔接实验一

课堂建议：
- 每个项目都可独立运行。
- 12、15 项适合先运行再让学生指出设计问题。
- 13、17、18 项适合配合 AI 做代码审查和测试用例设计。
- AI生成的建议需要通过编译、运行和测试验证。
