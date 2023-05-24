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
   
    Account *p1 = new Savings_Account {};
    Account *p2 = new Savings_Account {"Superman"}; 
    Account *p3 = new Savings_Account {"Batman", 2000};
    Account *p4 = new Savings_Account {"Wonderwoman", 5000, 5.0};

    vector<Account *> sav_accounts {p1, p2, p3, p4};
    
    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts,2000);

    
    return 0;
}

