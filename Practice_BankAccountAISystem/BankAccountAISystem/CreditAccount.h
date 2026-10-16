#pragma once

#include "Account.h"

class CreditAccount final : public Account {
public:
    CreditAccount(const std::string& owner, const std::string& number,
                  double balance, double creditLimit)
        : Account(owner, number, balance), creditLimit_(creditLimit) {}

    std::string accountType() const override { return "信用账户"; }
    double creditLimit() const { return creditLimit_; }

    bool withdraw(double amount) override {
        if (amount <= 0.0 || amount > balance_ + creditLimit_) return false;
        balance_ -= amount;
        return true;
    }

    void display(std::ostream& out) const override {
        Account::display(out);
        out << "信用额度：" << std::fixed << std::setprecision(2) << creditLimit_ << "\n"
            << "已使用额度：" << std::fixed << std::setprecision(2)
            << (balance_ < 0.0 ? -balance_ : 0.0) << "\n";
    }

private:
    double creditLimit_;
};
