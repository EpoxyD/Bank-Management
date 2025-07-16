#include "customer.h"

using namespace std;

Customer::Customer()
{
    cout << "Constructing Customer" << endl;
}

void Customer::greet()
{
    cout << "welcome CUSTOMER" << endl;
    cout << "choose the following please" << endl;
    cout << "press 1 to see account details" << endl;
    cout << "press 2 to see transaction history  " << endl;
    cout << "press 3 to exit" << endl;
}

void customer()
{
    BST_Tree t;
    Hashtable h;
    int condition = 0;
    while (condition != 3)
    {
        cout << "welcome CUSTOMER" << endl;
        cout << "choose the following please" << endl;
        cout << "press 1 to see account details" << endl;
        cout << "press 2 to see transaction history  " << endl;
        cout << "press 3 to exit" << endl;
        cin >> condition;
        if (condition == 1)
        {
            int accountno;
            cout << "please enter account number" << endl;
            cin >> accountno;
            BST_Node* temp = t.search(t.Root, accountno);
            cout << "Account Details Are : " << endl << endl;
            cout << "NAME :" << temp->account.name << endl;
            cout << "ADRESS :" << temp->account.address << endl;
            cout << "ACCOUNT NUMBER :" << temp->account.account_number << endl;
            cout << "PASSWORD :" << temp->account.password << endl;
            cout << "BALANCE :" << temp->account.balance << endl;
        }
        if (condition == 2)
        {
            // transaction file print karani ha account search kr k
        }
        if (condition == 3)
        {
            condition = 3;
        }
    }
}
