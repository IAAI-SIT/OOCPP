#include <iostream>
using namespace std;

class Account;

class Auditor {
public:
    void check(const Account& a) const;
};

class Account {
    friend class Auditor;
public:
    Account(double b) : balance(b) {}
private:
    double balance;
};

void Auditor::check(const Account& a) const {
    cout << "balance = " << a.balance << endl;
}

int main() {
    Account account(10000);
    Auditor auditor;
    auditor.check(account);
    return 0;
}
