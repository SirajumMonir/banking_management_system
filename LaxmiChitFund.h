#ifndef LAXMI_CHIT_FUND_H
#define LAXMI_CHIT_FUND_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream> 

using namespace std;


// PILLAR 1: ENCAPSULATION


class Account {
protected:
    string accNumber;
    double balance;
    string type;

public:
    Account(string num, double initialBalance, string t) : accNumber(num), balance(initialBalance), type(t) {}
    virtual ~Account() {}


    string getAccountNumber() const { return accNumber; }
    double getBalance() const { return balance; }
    string getType() const { return type; }


    void deposit(double amount) {
        if (amount > 0) balance += amount;
    }


// PILLAR 2: ABSTRACTION

public:
    virtual void withdraw(double amount) = 0;
    
    virtual void displayDetails() const {
        cout << "Acc No: " << accNumber << " | Balance: $" << balance << " | Type: " << type << endl;
    }
};


// PILLAR 3: INHERITANCE


class SavingsAccount : public Account { // <--- Inheritance
private:
    double minBalance;
public:
    SavingsAccount(string num, double initialBalance) 
        : Account(num, initialBalance, "Savings"), minBalance(1000.0) {}


// PILLAR 4: POLYMORPHISM
    void withdraw(double amount) override {
        if (amount > 0 && (balance - amount >= minBalance)) {
            balance -= amount;
            cout << ">> [LAXMI CHIT FUND] Success! Withdrew from Savings." << endl;
        } else {
            cout << ">> [ALERT] Transaction failed! Scheme requires min balance of $1000." << endl;
        }
    }
};

class CurrentAccount : public Account { // <--- Inheritance
public:
    CurrentAccount(string num, double initialBalance) 
        : Account(num, initialBalance, "Current") {}


// PILLAR 4: POLYMORPHISM
    void withdraw(double amount) override {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << ">> [LAXMI CHIT FUND] Success! Withdrew from Current." << endl;
        } else {
            cout << ">> [ALERT] Insufficient balance for withdrawal." << endl;
        }
    }
};

// EXTRA STORAGE LAYER
void loadDatabase(vector<Account*>& db) {
    ifstream inFile("bank_db.txt");
    if (!inFile) return; 

    string num, type;
    double bal;
    while (inFile >> num >> bal >> type) {
        if (type == "Savings") {
            db.push_back(new SavingsAccount(num, bal));
        } else if (type == "Current") {
            db.push_back(new CurrentAccount(num, bal));
        }
    }
    inFile.close();
}

void saveDatabase(const vector<Account*>& db) {
    ofstream outFile("bank_db.txt"); 
    for (Account* acc : db) {
        outFile << acc->getAccountNumber() << " " << acc->getBalance() << " " << acc->getType() << "\n";
    }
    outFile.close();
}

#endif