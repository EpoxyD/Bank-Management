#ifndef BST_TREE_H_
#define BST_TREE_H_

#include <stdio.h>
#include <vector>

#include "account.h"
#include "Hashtable.h"

class BST_Node
{
    public:
        BST_Node* left;
        BST_Node* right;
        Account account;

        BST_Node();
        BST_Node(Account account);
};

class BST_Tree
{
    private:
        vector<int> v;
        Hashtable h;

    public:
        BST_Tree();
        BST_Node *Root = nullptr;
        void add_Account(std::string, std::string, int, int, int);
        BST_Node *delete_Account(BST_Node *, int);
        void withdraw(int, int);
        void deposit(int, int);
        void editaccount_byAdmin();
        void transfer(int, int, int);
        void transaction_history();
        void findMax(BST_Node *);
        void load_Server();
        void update_server(BST_Node *);
        BST_Node *search(BST_Node *, int);
        void printoinfo(BST_Node *);
};

#endif  // BST_TREE_H_
