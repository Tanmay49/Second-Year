#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *prev;
};
Node *create(int data)
{
    Node* newnode=new Node();
    newnode->data = data;
    newnode->next =NULL;
    newnode->prev =NULL;
};

Node *create(Node*root,int data)
{
    Node* newnode=create(data);

    if(root==NULL)
    {
        root = newnode;
        return root;
    }
    else
    {
        Node*temp=root;
    while(temp->next!= NULL)
    {
        temp=temp->next;
    }
    temp->next= newnode;
    temp
    }
}
int main()
{

    return 0;
}