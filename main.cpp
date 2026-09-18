#include <iostream>
#include <vector>
#include <string>
#include "LaxmiChitFund.h"

using namespace std;

int main() {
    vector<Account*> bankDatabase;
    loadDatabase(bankDatabase);
    
    int choice;
    string accNum;
    double amount;

    while (true) {
        cout << "\n==================================================" << endl;
        cout << "      \U0001F4B0 WELCOME TO LAXMI CHIT FUND CORE \U0001F4B0" << endl;
        cout << "==================================================" << endl;
        cout << "1. Create New Account (Scheme Entry)" << endl;
        cout << "2. Deposit Money (Investment)" << endl;
        cout << "3. Withdraw Money (21 Din Me Paisa Double!)" << endl;
        cout << "4. Display All Ledger Records" << endl;
        cout << "5. Exit & Save Database" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << "Enter Choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int type;
                cout << "Choose Account Type (1. Savings | 2. Current): "; cin >> type;
                cout << "Enter Account Number: "; cin >> accNum;
                cout << "Enter Initial Investment: $"; cin >> amount;

                if (type == 1) bankDatabase.push_back(new SavingsAccount(accNum, amount));
                else bankDatabase.push_back(new CurrentAccount(accNum, amount));
                
                saveDatabase(bankDatabase); 
                cout << ">> Success! Investor added to Laxmi Chit Fund Database." << endl;
                break;
            }
            case 2: {
                cout << "Enter Account Number: "; cin >> accNum;
                bool found = false;
                for (Account* acc : bankDatabase) {
                    if (acc->getAccountNumber() == accNum) {
                        cout << "Enter Deposit Amount: $"; cin >> amount;
                        acc->deposit(amount); 
                        saveDatabase(bankDatabase); 
                        cout << ">> Ledger Updated successfully!" << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) cout << ">> [ERROR] Investor Record not found!" << endl;
                break;
            }
            case 3: {
                cout << "Enter Account Number: "; cin >> accNum;
                bool found = false;
                for (Account* acc : bankDatabase) {
                    if (acc->getAccountNumber() == accNum) {
                        cout << "Enter Withdrawal Amount: $"; cin >> amount;
                        

                        acc->withdraw(amount); 
                        
                        saveDatabase(bankDatabase); 
                        found = true;
                        break;
                    }
                }
                if (!found) cout << ">> [ERROR] Investor Record not found!" << endl;
                break;
            }
            case 4:
                if (bankDatabase.empty()) {
                    cout << "\n>> Ledger is currently empty." << endl;
                } else {
                    cout << "\n--- LAXMI CHIT FUND CURRENT LEDGER REGISTRY ---" << endl;
                    for (Account* acc : bankDatabase) {
                        acc->displayDetails(); 
                    }
                }
                break;

            case 5:
                saveDatabase(bankDatabase); 
                for (Account* acc : bankDatabase) delete acc;
                cout << "\nAll records synced securely to 'bank_db.txt'. 21 Din Me Paisa Double Process Active!" << endl;
                return 0;

            default:
                cout << "Invalid Choice! Anuradha coordinates only 1 to 5." << endl;
        }
    }
    return 0;
}
