
#include "BST_Tree.h"
#include "Hashtable.h"
#include "admin.h"
#include "customer.h"

void boot()
{
    Hashtable H;
    BST_Tree T;
    H.starthash();
    T.load_Server();
}
int main()
{
    void boot();

    int condition = 0;
    while (true)
    {
        cout << "YOU want to login as:" << endl << endl;
        cout << "1-ADMIN" << endl;
        cout << "2-STAFF" << endl;
        cout << "3-CUSTOMER" << endl;
        cin >> condition;
        if (condition == 1)
        {
            admin();
        }
        if (condition == 2)
        {
        }
        if (condition == 3)
        {
            customer();
        }
        else
        {
            cout << "Option must be 1, 2 or 3." << endl;
            cout << "Received: " << condition << endl;
            break;
        }
    }

    return 0;
}
