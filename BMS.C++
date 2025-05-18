
#include <iostream>
#include <string>
using namespace std;

const int MAX_ACCOUNTS = 100;

struct BankAccount {
    int accountNumber;
    string name;
    float balance;
};

BankAccount accounts[MAX_ACCOUNTS];
int totalAccounts = 0;

// Function to create a new account
void createAccount() {
    if (totalAccounts >= MAX_ACCOUNTS) {
        cout << "Account limit reached!" << endl;
        return;
    }

    BankAccount newAccount;
    cout << "Enter Account Number: ";
    cin >> newAccount.accountNumber;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, newAccount.name);
    cout << "Enter Initial Balance: ";
    cin >> newAccount.balance;

    accounts[totalAccounts++] = newAccount;
    cout << "Account created successfully!" << endl;
}

// Function to deposit money
void depositMoney() {
    int accNo;
    float amount;
    cout << "Enter Account Number: ";
    cin >> accNo;

    for (int i = 0; i < totalAccounts; ++i) {
        if (accounts[i].accountNumber == accNo) {
            cout << "Enter Amount to Deposit: ";
            cin >> amount;
            accounts[i].balance += amount;
            cout << "Amount Deposited Successfully!" << endl;
            return;
        }
    }

    cout << "Account not found!" << endl;
}

// Function to withdraw money
void withdrawMoney() {
    int accNo;
    float amount;
    cout << "Enter Account Number: ";
    cin >> accNo;

    for (int i = 0; i < totalAccounts; ++i) {
        if (accounts[i].accountNumber == accNo) {
            cout << "Enter Amount to Withdraw: ";
            cin >> amount;
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                cout << "Withdrawal Successful!" << endl;
            } else {
                cout << "Insufficient Balance!" << endl;
            }
            return;
        }
    }

    cout << "Account not found!" << endl;
}

// Function to check balance
void checkBalance() {
    int accNo;
    cout << "Enter Account Number: ";
    cin >> accNo;

    for (int i = 0; i < totalAccounts; ++i) {
        if (accounts[i].accountNumber == accNo) {
            cout << "Account Holder: " << accounts[i].name << endl;
            cout << "Current Balance: Rs." << accounts[i].balance << endl;
            return;
        }
    }

    cout << "Account not found!" << endl;
}

int main() {
    int choice;

    do {
        cout << "\n--- Bank Management System ---\n";
        cout << "1. Create New Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createAccount(); break;
            case 2: depositMoney(); break;
            case 3: withdrawMoney(); break;
            case 4: checkBalance(); break;
            case 5: cout << "Thank you for using the system!\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
