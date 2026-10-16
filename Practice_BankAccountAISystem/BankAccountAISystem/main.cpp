#include "BankSystem.h"

#include <iostream>
#include <limits>
#include <string>

namespace {
int readInt(const std::string& prompt) {
    int value{};
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        std::cout << "输入无效，请重新输入。\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

double readDouble(const std::string& prompt) {
    double value{};
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        std::cout << "输入无效，请重新输入。\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

std::string readLine(const std::string& prompt) {
    std::cout << prompt;
    std::string value;
    std::getline(std::cin, value);
    return value;
}

void showMenu() {
    std::cout << "\n===== 智能银行账户系统 =====\n"
              << "1. 开立储蓄账户\n"
              << "2. 开立信用账户\n"
              << "3. 存款\n"
              << "4. 取款\n"
              << "5. 查询账户\n"
              << "6. 显示全部账户\n"
              << "7. 保存账户数据\n"
              << "8. 读取账户数据\n"
              << "0. 退出\n";
}
}

int main() {
    BankSystem bank;
    const std::string defaultFile = "accounts.txt";

    while (true) {
        showMenu();
        const int choice = readInt("请选择：");
        if (choice == 0) break;

        if (choice == 1 || choice == 2) {
            const std::string owner = readLine("户主姓名：");
            const std::string number = readLine("账号：");
            const double balance = readDouble("初始余额：");
            bool success = false;
            if (choice == 1) {
                success = bank.createSavings(owner, number, balance);
            } else {
                const double limit = readDouble("信用额度：");
                success = bank.createCredit(owner, number, balance, limit);
            }
            std::cout << (success ? "开户成功。\n" : "开户失败，请检查账号是否重复或输入是否有效。\n");
        } else if (choice == 3 || choice == 4) {
            const std::string number = readLine("账号：");
            const double amount = readDouble("金额：");
            const bool success = choice == 3 ? bank.deposit(number, amount) : bank.withdraw(number, amount);
            std::cout << (success ? "操作成功。\n" : "操作失败，请检查账号、金额或可用额度。\n");
        } else if (choice == 5) {
            const std::string number = readLine("账号：");
            const Account* account = bank.find(number);
            if (account) account->display(std::cout);
            else std::cout << "未找到该账户。\n";
        } else if (choice == 6) {
            bank.list(std::cout);
        } else if (choice == 7) {
            std::cout << (bank.save(defaultFile) ? "保存成功。\n" : "保存失败。\n");
        } else if (choice == 8) {
            std::cout << (bank.load(defaultFile) ? "读取成功。\n" : "读取失败，请检查数据文件。\n");
        } else {
            std::cout << "没有该菜单项。\n";
        }
    }
    std::cout << "系统已退出。\n";
    return 0;
}
