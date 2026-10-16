#pragma once

#include "Account.h"

#include <memory>
#include <string>
#include <vector>

class BankSystem {
public:
    bool createSavings(const std::string& owner, const std::string& number, double openingBalance);
    bool createCredit(const std::string& owner, const std::string& number,
                      double openingBalance, double creditLimit);
    bool deposit(const std::string& number, double amount);
    bool withdraw(const std::string& number, double amount);
    const Account* find(const std::string& number) const;
    void list(std::ostream& out) const;
    bool save(const std::string& filename) const;
    bool load(const std::string& filename);

private:
    Account* findMutable(const std::string& number);
    std::vector<std::unique_ptr<Account>> accounts_;
};
