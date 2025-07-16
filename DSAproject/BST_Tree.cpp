
#include "BST_Tree.h"
#include "account.h"

using namespace std;

BST_Node::BST_Node()
{
    left = nullptr;
    right = nullptr;
    account = Account();
}

BST_Node::BST_Node(Account account)
{
    this->left = nullptr;
    this->right = nullptr;
    this->account = account;
}

BST_Tree::BST_Tree() {}

void BST_Tree::add_Account(string name, string address, int accountno, int password, int balance)
{
    Account account = Account(name, address, accountno, password, balance);
    h.add(accountno, password);
    ofstream write;
    write.open("server.txt", ios::app);
    write << account.toString() << endl;
    write.close();
    BST_Node* temp = new BST_Node(account);

    BST_Node* current = Root;
    if (Root == nullptr)
    {
        Root = temp;
    }
    else
    {
        while (true)
        {
            if (accountno < current->account.account_number)
            {
                if (current->left == nullptr)
                {
                    current->left = temp;
                    break;
                }
                current = current->left;
            }

            if (accountno > current->account.account_number)
            {
                if (current->right == nullptr)
                {
                    current->right = temp;
                    break;
                }
                current = current->right;
            }
        }
    }
}

BST_Node* BST_Tree::delete_Account(BST_Node* root, int accountno)
{
    // cout << "accountno"<<root->account.account_number;
    if (root == nullptr)
        cout << "it seems that Tree is empty OR You have entered wrong data" << endl;
    else if (accountno < root->account.account_number)
        root->left = delete_Account(root->left, accountno);
    else if (accountno > root->account.account_number)
        root->right = delete_Account(root->right, accountno);
    else
    {
        if (root->left && root->right)
        {
            findMax(root->left);
            root->account.account_number = v.back();
            root->left = delete_Account(root->left, root->account.account_number);
        }
        else
        {
            cout << "aya" << endl;
            BST_Node* temp = root;
            if (root->left == nullptr)
                root = root->right;
            else if (root->right == nullptr)
                root = root->left;
            delete temp;
        }
    }
    return (root);
}

void BST_Tree::withdraw(int accountno, int amount)
{
    load_Server();
    BST_Node* temp = search(Root, accountno);
    temp->account.balance = temp->account.balance - amount;
    vector<int> data;
    ifstream read;
    read.open("transaction.txt", ios::app);
    int line = 0;
    while (!read.eof())
    {
        read >> line;
        if (line == accountno)
        {
            data.push_back(line);
            line = (amount * -1);
            data.push_back(line);
            continue;
        }
        data.push_back(line);
    }
    read.close();

    ofstream write;
    write.open("temp.txt", ios::app);
    for (int i = 0; i < data.size(); i++)
    {
        write << data[i] << endl;
    }
    write.close();
    remove("transaction.txt");
    rename("temp.txt", "transaction.txt");

    update_server(Root);
}

void BST_Tree::deposit(int accountno, int amount)
{
    load_Server();
    BST_Node* temp = search(Root, accountno);
    temp->account.balance = temp->account.balance + amount;

    vector<int> data;
    ifstream read;
    read.open("transaction.txt", ios::app);
    int line = 0;
    while (!read.eof())
    {
        read >> line;
        if (line == accountno)
        {
            data.push_back(line);
            line = amount;
            data.push_back(line);
            continue;
        }
        data.push_back(line);
    }
    read.close();

    ofstream write;
    write.open("temp.txt", ios::app);
    for (int i = 0; i < data.size(); i++)
    {
        write << data[i] << endl;
    }
    write.close();
    remove("transaction.txt");
    rename("temp.txt", "transaction.txt");

    update_server(Root);
}

void BST_Tree::editaccount_byAdmin() {}

void BST_Tree::transfer(int sender_accountno, int reciever_accountno, int sender_amount)
{
    // happening in tree
    BST_Node* sender = search(Root, sender_accountno);
    sender->account.balance = sender->account.balance - sender_amount;
    BST_Node* reciever = search(Root, reciever_accountno);
    reciever->account.balance = reciever->account.balance + sender_amount;
    update_server(Root);

    // Now happening in the transacton file

    //  for sender
    vector<int> data;
    ifstream read;
    read.open("transaction.txt", ios::app);
    int line = 0;
    while (!read.eof())
    {
        read >> line;
        if (line == sender_accountno)
        {
            data.push_back(line);
            line = (sender_amount * -1);
            data.push_back(line);
            continue;
        }
        data.push_back(line);
    }
    read.close();

    ofstream write;
    write.open("temp.txt", ios::app);
    for (int i = 0; i < data.size(); i++)
    {
        write << data[i] << endl;
    }
    write.close();
    remove("transaction.txt");
    rename("temp.txt", "transaction.txt");

    //  for reciever
    read.open("transaction.txt", ios::app);
    line = 0;
    while (!read.eof())
    {
        read >> line;
        if (line == reciever_accountno)
        {
            data.push_back(line);
            line = sender_amount;
            data.push_back(line);
            continue;
        }
        data.push_back(line);
    }
    read.close();

    write.open("temp.txt", ios::app);
    for (int i = 0; i < data.size(); i++)
    {
        write << data[i] << endl;
    }
    write.close();
    remove("transaction.txt");
    rename("temp.txt", "transaction.txt");
}

void BST_Tree::transaction_history() {}

void BST_Tree::findMax(BST_Node* root)
{
    if (root)
    {
        findMax(root->left);
        v.push_back(root->account.account_number);
        findMax(root->right);
    }
}

void BST_Tree::load_Server()
{
    ifstream read;
    read.open("server.txt", ios::app);

    string name = "";
    string adress = "";
    int accountno = 0;
    int password = 0;
    int balance = 0;
    // cin.ignore();
    while (!read.eof())
    {
        getline(read, name);
        getline(read, adress);
        read >> accountno;
        read >> password;
        read >> balance;
        read.ignore();
        read.ignore();
        /*
                        cout << name << endl;
                        cout << adress << endl;
                        cout << accountno << endl;
                        cout << password << endl;
                        cout << balance << endl;

                        */
        if (name != "" && adress != "" && accountno != 0 && password != 0)
        {
            // cout << "enter hua" << endl;
            BST_Node* temp = new BST_Node(Account(name, adress, accountno, password, balance));
            BST_Node* current = Root;
            if (Root == nullptr)
            {
                Root = temp;
            }
            else
            {
                while (true)
                {
                    if (accountno < current->account.account_number)
                    {
                        if (current->left == nullptr)
                        {
                            current->left = temp;
                            break;
                        }
                        current = current->left;
                    }

                    if (accountno > current->account.account_number)
                    {
                        if (current->right == nullptr)
                        {
                            current->right = temp;
                            break;
                        }
                        current = current->right;
                    }
                    if (accountno == current->account.account_number)
                    {
                        break;
                    }
                }
            }
        }
    }
    read.close();
}

void BST_Tree::update_server(BST_Node* root)
{
    static int i = 0;
    if (i == 0)
    {
        i++;
        remove("server.txt");
    }
    ofstream write;
    write.open("server.txt");
    if (root)
    {
        update_server(root->left);
        write << root->account.name << endl;
        write << root->account.address << endl;
        write << root->account.account_number << endl;
        write << root->account.password << endl;
        write << root->account.balance << endl;
        update_server(root->right);
    }
    write.close();
}

BST_Node* BST_Tree::search(BST_Node* root, int accountno)
{
    if (root == nullptr)
        return (nullptr);
    else if (accountno < root->account.account_number)
        return (search(root->left, accountno));
    else if (accountno > root->account.account_number)
        return (search(root->right, accountno));
    return (root);
}

void BST_Tree::printoinfo(BST_Node* root)
{
    if (root)
    {
        printoinfo(root->left);
        cout << root->account.name << endl;
        cout << root->account.address << endl;
        cout << root->account.account_number << endl;
        cout << root->account.password << endl;
        cout << root->account.balance << endl;
        printoinfo(root->right);
    }
}
