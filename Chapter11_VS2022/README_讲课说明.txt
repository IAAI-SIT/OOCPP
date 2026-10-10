第11章 继承与派生 —— VS2022 课堂代码包

使用方法：用 Visual Studio 2022 打开 Chapter11.sln。所有项目均按 C++17 配置。
说明：故意不能编译的语句都放在 #if 0 ... #endif 中，需要课堂演示错误时可临时改为 #if 1。

PPT对应关系：
01. [11.1] 从重复代码到继承  ->  01_Inheritance_Basics
02. [11.2] 派生类声明方式  ->  02_Derived_Class_Syntax
03. [11.3] 派生类的构成：基类部分 + 新增部分  ->  03_Derived_Class_Composition
04. [11.4] public继承中的访问属性  ->  04_Public_Inheritance_Access
05. [11.4] private与protected继承  ->  05_Private_Protected_Inheritance
06. [11.4] 编译错误：派生类不能直接访问基类private  ->  06_Private_Member_Error
07. [11.4] 多级派生 A -> B -> C  ->  07_Multilevel_Inheritance
08. [11.5] 派生类构造函数调用基类构造函数  ->  08_Derived_Constructor
09. [11.5] 构造与析构顺序  ->  09_Ctor_Dtor_Order
10. [11.5] 含子对象时的构造与析构顺序  ->  10_Subobject_Ctor_Dtor_Order
11. [11.5] 基类有默认构造函数  ->  11_Default_Base_Constructor
12. [11.6] Teacher + Student 多重继承  ->  12_Multiple_Inheritance
13. [11.6] 多重继承同名成员的二义性  ->  13_Multiple_Inheritance_Ambiguity
14. [11.6] 派生类同名成员隐藏基类成员  ->  14_Name_Hiding
15. [11.6] 普通菱形继承：两份Person子对象  ->  15_Diamond_Inheritance
16. [11.6] 虚基类：共享一份Person  ->  16_Virtual_Base_Class
17. [11.7] 派生类对象赋给基类对象：只保留基类部分  ->  17_Object_Slicing
18. [11.7] 基类引用绑定派生类对象  ->  18_Base_Reference
19. [11.7] 基类指针指向派生类对象  ->  19_Base_Pointer
20. [11.8] 继承与组合：is-a / has-a  ->  20_Inheritance_vs_Composition
21. [11.9] 综合实践：Person -> Student -> Graduate  ->  21_Integrated_Lab

建议课堂使用：
1. 先预测输出或判断能否编译；
2. 再运行代码验证；
3. AI任务只用于解释/审查，最终以编译和运行结果验证。

重点错误演示：
- 04_Public_Inheritance_Access：基类 private / protected 访问限制
- 06_Private_Member_Error：派生类直接访问基类 private 成员
- 13_Multiple_Inheritance_Ambiguity：多重继承同名成员二义性
- 15_Diamond_Inheritance：普通菱形继承产生两份 Person
- 17_Object_Slicing：派生类对象赋给基类对象只保留基类部分
- 19_Base_Pointer：Student* 不能直接调用 Graduate 新增接口