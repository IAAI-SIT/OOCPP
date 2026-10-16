#pragma once

#include "Account.h"

class SavingsAccount final : public Account {
public:
    SavingsAccount(const std::string& owner, const std::string& number, double balance)
        : Account(owner, number, balance) {}

    std::string accountType() const override { return "储蓄账户"; }
};
