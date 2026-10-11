# 《面向对象程序设计》第13章 输入输出流 — Visual Studio 课堂源码

一个 Solution，多个独立可运行控制台项目；延续前面章节的课堂代码组织方式。

## 使用
1. 打开 `OOP_Chapter13_IO_Streams.sln`。
2. 右击要演示的项目 → “设为启动项目”。
3. `Ctrl+F5` 运行。

配置：C++17、x64、Debug/Release、UTF-8。若 Visual Studio 2026 提示重定向工具集，按本机已安装工具集升级即可。

## 项目映射
| 项目 | 章节 | 内容 | PPT |
|---|---|---|---|
| P13_01_StreamBasics | 13.1 | 流、流对象与标准 I/O | PPT 4–10 |
| P13_02_BufferFlush | 13.1 | 输出缓冲、\n、flush 与 endl | PPT 7–8 |
| P13_03_FormatOutput | 13.2 | 格式化输出 | PPT 12–17 |
| P13_04_CinWhitespace | 13.3 | cin >> 与空白字符 | PPT 19 |
| P13_05_CinGetlineTrap | 13.3 | cin >> 后接 getline：问题与修复 | PPT 23–25, 28 |
| P13_06_InputStateRecovery | 13.3 | 输入失败、clear() 与 ignore() | PPT 20–27 |
| P13_07_CharGetPut | 13.3 | 字符级 I/O：get() 与 put() | PPT 22, 26 |
| P13_08_FileOpenModes | 13.4 | ios::out 与 ios::app：覆盖和追加 | PPT 34 |
| P13_09_TextWriteRead | 13.5 | 完整文本文件示例：学生成绩写入与读取 | PPT 37–39 |
| P13_10_TextUppercase | 13.5 | 完整文本文件示例：小写转大写 | PPT 40–41 |
| P13_11_TextReadRobust | 13.5 | 文本读取：EOF 还是格式错误 | PPT 38–43 |
| P13_12_BinaryArray | 13.6 | 二进制文件：完整 int 数组 write/read | PPT 45–46 |
| P13_13_BinaryRecordFormat | 13.6 | 二进制文件：显式约定记录格式 | PPT 46–47 |
| P13_14_StringstreamBuildParse | 13.7 | stringstream：字段与字符串转换 | PPT 49–51 |
| P13_15_StringstreamValidate | 13.7 | stringstream：验证异常记录 | PPT 52–53 |
| P13_16_AI_CinGetlineReview | 13.3 | AI任务：复现并修复 cin >> / getline | PPT 28 |
| P13_17_AI_WhileEofReview | 13.5 | AI任务：while(!eof()) 对比验证 | PPT 39, 43 |
| P13_18_IntegratedDemo | 13.1–13.7 | 综合案例：文本文件 + stringstream + 格式化输出 | PPT 综合复习 |

## 课堂使用建议
- PPT 放关键代码，Solution 提供完整可运行代码。
- 保持“预测 → 运行 → 解释 → 验证”。
- `P13_16`、`P13_17` 对应 AI 审查任务。
- `P13_18_IntegratedDemo` 用于本章收尾。
- 文件类项目会在各自运行工作目录生成 `.txt` / `.bin` 文件，便于现场查看。
