#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Transaction
{
private:
    int amount;
    string type;

public:
    Transaction(int amt, string kind) : amount(amt), type(kind) {}
    string Report()
    {
        string report;
        report += "   ";
        report += type;
        report += " ";
        report += to_string(amount);
        return report;
    }
};

class Account
{
private:
    int balance;
    vector<Transaction> log;

public:
    Account() : balance(0) {}

    vector<string> Report()
    {
        vector<string> report;
        report.push_back("Balance is " + to_string(balance));
        report.push_back("Transaction History:");
        for (auto t : log)
        {
            report.push_back(t.Report());
        }
        report.push_back("---------------");
        return report;
    }

    bool Deposit(int amount)
    {
        if (amount >= 0)
        {
            balance += amount;
            log.push_back(Transaction(amount, "Deposit"));
            return true;
        }
        else
        {
            return false;
        }
    }

    bool Withdraw(int amount)
    {
        if (amount <= 0 || balance < amount)
        {
            return false;
        }

        balance -= amount;
        log.push_back(Transaction(amount, "Withdraw"));
        return true;
    }

    int GetBalance()
    {
        return balance;
    }
};

int main()
{
    Account account;
    int choice;
    bool accountOpened = false;

    do
    {
        cout << "Menu:" << endl;
        cout << "1. Open Account" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Display Account" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (!accountOpened)
            {
                accountOpened = true;
                cout << "Account opened successfully!" << endl;
            }
            else
            {
                cout << "Account is already opened." << endl;
            }
            break;

        case 2:
            if (accountOpened)
            {
                int depositAmount;
                cout << "Enter the amount to deposit: ";
                cin >> depositAmount;
                if (account.Deposit(depositAmount))
                {
                    cout << "Deposit successful!" << endl;
                }
                else
                {
                    cout << "Invalid deposit amount." << endl;
                }
            }
            else
            {
                cout << "Please open an account first." << endl;
            }
            break;

        case 3:
            if (accountOpened)
            {
                int withdrawAmount;
                cout << "Enter the amount to withdraw: ";
                cin >> withdrawAmount;
                if (account.Withdraw(withdrawAmount))
                {
                    cout << "Withdrawal successful!" << endl;
                }
                else
                {
                    cout << "Invalid withdrawal amount or insufficient balance." << endl;
                }
            }
            else
            {
                cout << "Please open an account first." << endl;
            }
            break;

        case 4:
            if (accountOpened)
            {
                cout << "Account Details:" << endl;
                for (const string& reportLine : account.Report())
                {
                    cout << reportLine << endl;
                }
            }
            else
            {
                cout << "Please open an account first." << endl;
            }
            break;

        case 5:
            cout << "Exiting the program." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 5);

    return 0;
}
