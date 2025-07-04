#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

class Transaction {
public:
    string type;
    double amount;
    string timestamp;

    Transaction(string t, double a) {
        type = t;
        amount = a;
        time_t now = time(0);
        timestamp = ctime(&now);
        timestamp.pop_back();
    }

    void display() {
        cout << "[" << timestamp << "] " << type << ": ₹" << amount << endl;
    }
};

class Account {
private:
    double balance;
    vector<Transaction> history;

public:
    string accountNumber;
    Account(string accNo) {
        accountNumber = accNo;
        balance = 0.0;
    }

    void deposit(double amount) {
        balance += amount;
        history.push_back(Transaction("Deposit", amount));
        cout << "Deposited ₹" << amount << " successfully.\n";
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance.\n";
            return;
        }
        balance -= amount;
        history.push_back(Transaction("Withdrawal", amount));
        cout << "Withdrew ₹" << amount << " successfully.\n";
    }

    void transfer(Account &to, double amount) {
        if (amount > balance) {
            cout << "Insufficient balance.\n";
            return;
        }
        balance -= amount;
        to.balance += amount;
        history.push_back(Transaction("Transfer to " + to.accountNumber, amount));
        to.history.push_back(Transaction("Transfer from " + accountNumber, amount));
        cout << "Transferred ₹" << amount << " to " << to.accountNumber << " successfully.\n";
    }

    void showBalance() {
        cout << "Current Balance: ₹" << balance << endl;
    }

    void showTransactions() {
        cout << "Transaction History:\n";
        for (auto &t : history) {
            t.display();
        }
    }
};

class Customer {
public:
    string name;
    string customerId;
    Account account;

    Customer(string n, string id) : account(id + "_A1") {
        name = n;
        customerId = id;
    }

    void showDetails() {
        cout << "Customer: " << name << "\nID: " << customerId << "\nAccount: " << account.accountNumber << endl;
    }
};

int main() {
    Customer c1("Alice", "C001");
    Customer c2("Bob", "C002");

    int choice;
    double amount;

    while (true) {
        cout << "\n1. Deposit\n2. Withdraw\n3. Transfer\n4. View Balance\n5. View Transactions\n6. Exit\nChoose: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                c1.account.deposit(amount);
                break;
            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                c1.account.withdraw(amount);
                break;
            case 3:
                cout << "Enter amount to transfer to Bob: ";
                cin >> amount;
                c1.account.transfer(c2.account, amount);
                break;
            case 4:
                c1.account.showBalance();
                break;
            case 5:
                c1.account.showTransactions();
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid option.\n";
        }
    }

    return 0;
}
