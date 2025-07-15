#ifndef BST_NODE_H_
#define BST_NODE_H_

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class BST_Node
{
    public:
        BST_Node* left;
        BST_Node* right;
        std::string name;
        std::string adress;
        int account_number;
        int password;
        int balance;

        BST_Node();
        BST_Node(std::string, std::string, int, int, int);
};

#endif  // BST_NODE_H_
