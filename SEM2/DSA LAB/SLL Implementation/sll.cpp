#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

Node *newNode(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node *insert_at(Node *root, int data, int pos)
{
    Node *newNod = newNode(data);
    Node *temp = root;
    if (pos == 1)
    {
        newNod->next = temp;
        root = newNod;
    }
    for (int i = 0; i < pos - 2; i++)
    {
        temp = temp->next;
    }
    newNod->next = temp->next;
    temp->next = newNod;
    return root;
}

Node *insert(Node *root, int data)
{
    Node *newNod = newNode(data);
    if (root == NULL)
    {
        root = newNod;
        return root;
    }
    else
    {
        Node *temp = root;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNod;
    }
    return root;
}

Node *insert_at_front(Node *root, int data)
{
    Node *newNod = newNode(data);
    newNod->next = root;
    root = newNod;
    return root;
}

void print(Node *root)
{
    for (Node *temp = root; temp != NULL; temp = temp->next)
    {
        cout << temp->data << "->";
    }
}

Node* Delete(Node *root, int pos) 
{
    Node *temp = root;
    if (root == NULL)
    {
        cout << "LL is empty";
        return root;
    }
    if (pos == 1)
    {
        root = temp->next;
        delete (temp);
        return root;
    }
    for (int i = 0; i < pos - 2; i++)
    {
        temp = temp->next;  
    }
// Node *temp1=temp->next;
    temp->next = temp->next->next;
    delete (temp->next);
    return root;

}

Node *reverse(Node *root)
{
    
    for(Node*temp=root;temp->next != NULL; temp=temp->next);
     
}
int main()
{
    Node *root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    print(root);
     cout << endl;
     root = insert_at_front(root, 0);
     root = insert_at_front(root, -1);
     root = insert_at_front(root, -2);
    print(root);
    cout << endl;
    root=Delete(root, 1);
    print(root);
    return 0;
}