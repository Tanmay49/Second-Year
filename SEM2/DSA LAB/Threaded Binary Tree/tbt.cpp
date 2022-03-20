#include <iostream>
#include <cstdio>
using namespace std;
class Node
{
private:
    typedef struct T_Node
    {
        int data;
        T_Node *left;
        T_Node *right;
        bool lbit;
        bool rbit;
    } node;
    node *root;
    node *dummy, *New, *parent, *temp;

public:
    Node()
    {
        root = NULL;
    }
    void create();
    void display();
    void inorder(node *, node *);
    void insert(node *, node *);
    struct T_Node * leftmost();
};

void Node::create()
{
    New = new node;
    New->left = NULL;
    New->right = NULL;
    New->lbit = 0;
    New->rbit = 0;

    cout << "Enter data: " << endl;
    cin >> New->data;
    if (root == NULL)
    {
        root = New;
        dummy = new node;
        dummy->data = -999;
        dummy->left = root;
        root->left = dummy;
        root->right = dummy;
    }
    else
        insert(root, New);
}

void Node::insert(node *root, node *New)
{
    char ch;
    cout << "Where do you want to insert" << root->data << endl;
    cin >> ch;
    if ((ch == 'r' || ch == 'R'))
    {
        if (root->rbit == 0)
        {
            New->right = root->right;
            New->left = root;
            root->rbit = 1;
            root->right = New;
        }
        else
        {
            insert(root->right, New);
        }
    }
    else
    {
        if (root->lbit == 0)
        {
            New->left = root->left;
            New->right = root;
            root->lbit = 1;
            root->left = New;
        }
        else
        {
            insert(root->left, New);
        }
    }
}
void Node::display()
{
    if(root==NULL)
    {
        cout<<"Tree is empty!"<<endl;
    }
    else
    inorder(root,dummy);
}

void Node::inorder(node *temp, node *dummy)
{

    while (temp != dummy)
    {
        while (temp->lbit== 1)
        temp = temp->left;
    cout << temp->data;
    while (temp->rbit==0)
    {
        temp = temp->right;
        if(temp==dummy)
        return;
        cout<<temp->data<<'-';
    }
    temp = temp->right;

    }

    
}

int main()
{
    Node a;
    char ch = 'n';
    do
    {
        /* code */
        a.create();
        cout << "More?" << endl;
        cin>>ch;
    } while (ch == 'y');
    a.display();

    return 0;
}