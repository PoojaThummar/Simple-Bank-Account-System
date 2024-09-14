#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class BankAccount {
private:
    string accountHolder;
    double balance;

public:
    BankAccount(string holder, double initialBalance) : accountHolder(holder), balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
        } else {
            cout << "Invalid amount!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew: $" << amount << endl;
        } else {
            cout << "Insufficient balance or invalid amount!" << endl;
        }
    }

    void displayBalance() {
        cout << "Balance: $" << balance << endl;
    }

    void saveToFile() {
        ofstream outFile("account.txt");
        outFile << "Account Holder: " << accountHolder << endl;
        outFile << "Balance: $" << balance << endl;
        outFile.close();
    }
};

int main() {
    string holder;
    double initialBalance;

    cout << "Enter account holder's name: ";
    getline(cin, holder);
    cout << "Enter initial balance: $";
    cin >> initialBalance;

    BankAccount account(holder, initialBalance);
    account.deposit(100.0);
    account.withdraw(50.0);
    account.displayBalance();
    account.saveToFile();

    return 0;
}
