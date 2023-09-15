#include <string>
using namespace std;

class Transaction
{
    private:
        int amount;
        string type; //a better way exists

    public:
        Transaction(int amt, string kind);
        string Report();
};