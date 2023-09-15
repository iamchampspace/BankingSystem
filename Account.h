#include <vector>
#include <string>
#include "Transaction.h"
using namespace std;


class Account
{
    private:
        int balance;
        vector<Transaction> log;
        int limit;
    public:
        Account();
        vector<string> Report();
        bool Deposit(int amount);
        bool Withdraw(int amount);
        int GetBalance() {
            return balance;
        }
};