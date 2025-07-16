#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <string>

using namespace std;

class Account
{
    public:
        Account(string name = "", string address = "", int accountno = 0, int password = 0, int balance = 0);
        string toString();
        string name;
        string address;
        int account_number;
        int password;
        int balance;

    private:
};

#endif  // ACCOUNT_H_
