#include "account.h"
#include <sstream>

Account::Account(string name, string address, int accountno, int password, int balance)
{
    this->name = name;
    this->address = address;
    this->account_number = accountno;
    this->password = password;
    this->balance = balance;
}

ostream& operator<<(ostream& os, const Account& account)
{
    os << account.account_number << ';' << account.name << ';' << account.address << ';' << account.balance << ';' << account.password;
    return os;
}

string Account::toString()
{
    stringstream ss;
    ss << (*this);
    return ss.str();
}
