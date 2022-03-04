#include <iostream>
using namespace std;
//hello world
//hello 
struct Node
{
    int data;
    Node *left;
    Node *right;
    bool lbit;
    bool rbit;
};

Node *newNode(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->lbit = 0;
    newNode->rbit = 0;
    return newNode;
}
int main()
{

    return 0;
}