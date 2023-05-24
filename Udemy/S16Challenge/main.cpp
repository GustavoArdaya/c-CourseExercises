// Section 16 
// Challenge 
#include <iostream>
#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std; 

int main() {
    cout.precision(2);
    cout << fixed;
   
    // Accounts
    // vector<Account> accounts;
    // accounts.push_back(Account {});
    // accounts.push_back(Account {"Larry"});
    // accounts.push_back(Account {"Moe", 2000} );
    // accounts.push_back(Account {"Curly", 5000} );
    
    // display(accounts);
    // deposit(accounts, 1000);
    // withdraw(accounts,2000);
    
    // Savings 

    Account *p1 = new Savings_Account {};
    Account *p2 = new Savings_Account {"Superman"}; 
    Account *p3 = new Savings_Account {"Batman", 2000};
    Account *p4 = new Savings_Account {"Wonderwoman", 5000, 5.0};

    vector<Account *> sav_accounts {p1, p2, p3, p4};
    
    // sav_accounts.push_back(p1);
    // sav_accounts.push_back(new Savings_Account {"Superman"} );
    // sav_accounts.push_back(new Savings_Account {"Batman", 2000} );
    // sav_accounts.push_back(new Savings_Account {"Wonderwoman", 5000, 5.0} );

    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts,2000);

    
    return 0;
}

