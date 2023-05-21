#include "Trust_Account.h"
#include <string>

Trust_Account::Trust_Account(std::string name = def_name, double balance =def_balance, double int_rate = def_int_rate)
    : Account {name, balance}, int_rate{int_rate} {        
}

bool Trust_Account::deposit(double amount) {
    if (amount > 5000) {
        amount += 50;
    }
    return Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount) {
    if (withdraw_count <= 3 && amount < (balance * 0.2)) {
        withdraw_count++;
        return Account::withdraw(amount);        
    }
    withdraw_count++;
    return false; 
}

std::ostream &operator<<(std::ostream &os, const Trust_Account &account) {
    os << "[Trust_Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "%]";
    return os;
}