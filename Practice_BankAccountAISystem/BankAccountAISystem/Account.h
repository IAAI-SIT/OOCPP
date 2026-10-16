#pragma once

#include <iomanip>
#include <iostream>
#include <string>

class Account {
public:
    Account(std::string owner, std::string number, double balance)
        : owner_(std::move(owner)), number_(std::move(number)), balance_(balance) {}
    virtual ~Account() = default;

    const std::string& owner() const { return owner_; }
    const std::string& number() const { return number_; }
    double balance() const { return balance_; }

    bool deposit(double amount) {
        if (amount <= 0.0) return false;
        balance_ += amount;
        return true;
    }

    virtual bool withdraw(double amount) {
        if (amount <= 0.0 || amount > balance_) return false;
        balance_ -= amount;
        return true;
    }

    virtual std::string accountType() const = 0;
    virtual void display(std::ostream& out) const {
        out << "账户类型：" << accountType() << "\n"
            << "户主：" << owner_ << "\n"
            << "账号：" << number_ << "\n"
            << "余额：" << std::fixed << std::setprecision(2) << balance_ << "\n";
    }

protected:
    std::string owner_;
    std::string number_;
    double balance_;
};
