
#include "BST_Tree.h"
#include "Hashtable.h"
#include "admin.h"
#include "customer.h"

using namespace std;

void boot()
{
    Hashtable H;

    cout << H.start << endl;

    BST_Tree T;
    H.starthash();
    T.load_Server();
}

enum role
{
    ROLE_ADMIN = 1,
    ROLE_STAFF = 2,
    ROLE_CUSTOMER = 3,
};

int main()
{
    void boot();

    Customer c = Customer();

    int condition = 0;
    while (true)
    {
        cout << "YOU want to login as:" << endl << endl;
        cout << "1-ADMIN" << endl;
        cout << "2-STAFF" << endl;
        cout << "3-CUSTOMER" << endl;
        cin >> condition;
        switch ((enum role)condition)
        {
            case ROLE_ADMIN:
                admin();
                break;
            case ROLE_STAFF:
                break;
            case ROLE_CUSTOMER:
                customer();
                break;
            default:
                cout << "Option must be 1, 2 or 3." << endl;
                cout << "Received: " << condition << endl;
                break;
        }
    }

    return 0;
}
