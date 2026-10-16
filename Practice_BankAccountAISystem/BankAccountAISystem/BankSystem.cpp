#include "BankSystem.h"
#include "CreditAccount.h"
#include "SavingsAccount.h"

#include <fstream>
#include <iomanip>
#include <sstream>

namespace {
std::vector<std::string> split(const std::string& line) {
    std::vector<std::string> fields;
    std::stringstream stream(line);
    std::string field;
    while (std::getline(stream, field, '|')) fields.push_back(field);
    return fields;
}
}

Account* BankSystem::findMutable(const std::string& number) {
    for (const auto& account : accounts_) {
        if (account->number() == number) return account.get();
    }
    return nullptr;
}

const Account* BankSystem::find(const std::string& number) const {
    for (const auto& account : accounts_) {
        if (account->number() == number) return account.get();
    }
    return nullptr;
}

bool BankSystem::createSavings(const std::string& owner, const std::string& number, double openingBalance) {
    if (owner.empty() || number.empty() || openingBalance < 0.0 || find(number)) return false;
    accounts_.push_back(std::make_unique<SavingsAccount>(owner, number, openingBalance));
    return true;
}

bool BankSystem::createCredit(const std::string& owner, const std::string& number,
                              double openingBalance, double creditLimit) {
    if (owner.empty() || number.empty() || openingBalance < 0.0 || creditLimit < 0.0 || find(number)) return false;
    accounts_.push_back(std::make_unique<CreditAccount>(owner, number, openingBalance, creditLimit));
    return true;
}

bool BankSystem::deposit(const std::string& number, double amount) {
    Account* account = findMutable(number);
    return account && account->deposit(amount);
}

bool BankSystem::withdraw(const std::string& number, double amount) {
    Account* account = findMutable(number);
    return account && account->withdraw(amount);
}

void BankSystem::list(std::ostream& out) const {
    if (accounts_.empty()) {
        out << "当前没有账户。\n";
        return;
    }
    out << "\n========== 账户列表 ==========\n";
    for (const auto& account : accounts_) {
        account->display(out);
        out << "------------------------------\n";
    }
}

bool BankSystem::save(const std::string& filename) const {
    std::ofstream out(filename);
    if (!out) return false;
    out << std::fixed << std::setprecision(2);
    for (const auto& account : accounts_) {
        if (const auto* credit = dynamic_cast<const CreditAccount*>(account.get())) {
            out << "C|" << credit->owner() << '|' << credit->number() << '|'
                << credit->balance() << '|' << credit->creditLimit() << '\n';
        } else {
            out << "S|" << account->owner() << '|' << account->number() << '|'
                << account->balance() << "\n";
        }
    }
    return true;
}

bool BankSystem::load(const std::string& filename) {
    std::ifstream in(filename);
    if (!in) return false;

    std::vector<std::unique_ptr<Account>> loaded;
    std::string line;
    while (std::getline(in, line)) {
        const auto fields = split(line);
        try {
            if (fields.size() == 4 && fields[0] == "S") {
                loaded.push_back(std::make_unique<SavingsAccount>(fields[1], fields[2], std::stod(fields[3])));
            } else if (fields.size() == 5 && fields[0] == "C") {
                loaded.push_back(std::make_unique<CreditAccount>(fields[1], fields[2], std::stod(fields[3]), std::stod(fields[4])));
            } else {
                return false;
            }
        } catch (const std::exception&) {
            return false;
        }
    }
    accounts_ = std::move(loaded);
    return true;
}
