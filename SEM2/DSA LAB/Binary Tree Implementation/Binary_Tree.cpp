// Beginning with an empty binary BT, Construct binary BT by inserting the values in the order given. 
// After constructing a binary BT perform following operations on it-
// 1.Perform inorder /preorder and post order traversal.
// 2.Change a BT so that the roles of the left and right pointers are swapped at every node
// 3.Find the height of BT <-
// 4.Copy this BT to another [operator=]~
// 5.Count number of leaves, number of internal nodes. <-
// 6.Erase all nodes in a binary BT.
// ->(implement both recursive and non-recursive methods)

#include<iostream>
#include<cstring>
using namespace std;
template <typename T>
class Stack
{
public:
    class StackNode
    {
    private:
        T data;
        StackNode *next;

    public:
        friend class Stack;
        StackNode(T &data)
        {
            this->data = data;
            next = NULL;
        }
        StackNode() { next = NULL; }
    };

private:
    StackNode *top;

public:
    Stack() { top = NULL; }
    void push(T x)
    {
        StackNode *tmp = new StackNode(x);
        tmp->next = top;
        top = tmp;
    };

    T pop()
    {
        StackNode *tmp;
        tmp = top;
        auto x = tmp->data;
        top = top->next;
        delete tmp;
        return x;
    };

    bool isEmpty() { return top == NULL ? 1 : 0; };
};


struct Node {
    int data;
    Node *right;
    Node *left;
};
Node* newNode(int data)  //Function to create a new node
{
    Node* node=new Node; //using new operator...
    node->data = data; //set the data
    node->left=NULL;// set the left pointer to NULL
    node->right=NULL;//  set the right pointer to NULL
    return node; //return the adress new node
};
Node *insert(Node*root) //Function to insert a new node into the tree
{
    // if(root == NULL) // if tree is empty then set root of the tree.
    // {
    //     root=newNode(data);
    // }
    // else if (data<=root->data) // if new node data is smaller than root recursively insert at left
    // {
    //     root->left=insert(root->left,data);
    // }
    // else //else recursively insert a right node
    // {
    //     root->right=insert(root->right,data);
    // }
    // return root; //return the adress of root. 
    
    int x;
    char a[20] {};
    cin.getline(a,20);
    if(strcmp(a,"$")==0)
    {
        return NULL;
    }
    
    x=atoi(a);
    Node *p=new Node;
    p=newNode(x);
    cout<<"Left of"<<x<<endl;
    p->left=insert(p->left);
    cout<<"Right of"<<x<<endl;
    p->right=insert(p->right);

    return p;

};
void preorder(Node *root) //preorder traversal
{
    //traverse the root ,then the left and then the right node. 
    if(root != NULL) 
    {
        cout<<root->data<<" "; 
        preorder(root->left);
        preorder(root->right);
    }

}

void  ipreorder(Node *p) //preorder traversal
{
    Stack<Node *> st;
    while (p != NULL || !st.isEmpty())
    {
        if (p != NULL)
        {
            cout << p->data << " ";
            st.push(p);
            p = p->left;
        }
        else
        {
            p = st.pop();
            p = p->right;
        }
    }
}

void postorder(Node *root) //postorder traversal
{
    //traverse the right,then the left and then the root.
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }

}
void ipostorder(Node *p) //postorder traversal
{
    Stack<long long int> st;
    long long int temp;
    while (p != NULL || !st.isEmpty())
    {
        if (p != NULL)
        {
            st.push((long long int)p);
            p = p->left;
        }
        else
        {
            temp = st.pop();
            if (temp > 0)
            {
                st.push(-1 * temp);
                p = (Node *)temp;
                p = p->right;
            }
            else
            {
                cout << ((Node *)(-1 * temp))->data << " ";
                p = NULL;
            }
        }
    }
}

void inorder(Node *root)//inorder traversal
{
    //traverse the left,then the root and then the right node.
    if(root != NULL)
    {
        inorder(root->left);
        cout<<root->data<<"->";
        inorder(root->right);

    }

}

void iinorder(Node *p)//inorder traversal
{
    Stack<Node *> st;
    while (p != NULL || !st.isEmpty())
    {
        if (p != NULL)
        {
            st.push(p);
            p = p->left;
        }
        else
        {
            p = st.pop();
            cout << p->data << " ";
            p = p->right;
        }
    }
}

void reversal(Node *root)//reversal
{
    if (root==NULL)
    return;
    
    Node *temp;
    reversal(root->left);
    reversal(root->right);
    temp=root->left;
    root->left=root->right;
    root->right=temp;
} 
int height(Node *root) //height of tree
{
    // Find height of left subtree
    //Find height of right subtree.
    //Compare them and return the max+1 amoung them. +1 is for the current node.
    if(root == NULL)
    {
        return -1;
    }
    else 
    {
        int ldepth=height(root->left);
        int rdepth=height(root->right);

        if(ldepth>rdepth)
        return (ldepth+1);

        else return (rdepth+1);
    }
}

Node *copy(Node *root)//copy tree
{
    if(root == NULL)
    {
        return nullptr;
    }
    Node *newroot=new Node;
    newroot=newNode(root->data);//copy data from old to new

    newroot->left=copy(root->left);
    newroot->right=copy(root->right);

    return newroot; //return the new root adress
}

int leaves(Node *root)
{
    if(root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    } 
    else 
    {
        return leaves(root->left)+leaves(root->right);
    }
}
int internal(Node *root)
{
    if(root == NULL || (root->left == NULL && root->right == NULL))
    return 0;
    
    return 1+ internal(root->left)+internal(root->right);
}

void delet(Node *root)
{
    if (root==NULL)
    return;

    delet(root->left);
    delet(root->right);

    delete root;

}
int main(){

//           40
//         /    \
//        34     45
//       /         \     
//       12        46
//       /
//      2
//     /
//    1 
    Node *root=NULL;
    Node *root_copy;
    int data;
    int ch;
    // cout<<"Enter data";
    // cin>>data;
    cout<<"Enter root of the tree";
    root=insert(root);
    do
    {
    cout<<endl;
    cout<<"MENU"<<endl;
    cout<<"1.Preorder "<<endl;
    cout<<"2.Postorder"<<endl;
    cout<<"3.Inorder"<<endl;
    cout<<"4.Height of Binary tree"<<endl;
    cout<<"5.Copy"<<endl;
    cout<<"6.Number of leaves"<<endl;
    cout<<"7.Number of internal nodes"<<endl;
    cout<<"8. Delete"<<endl;
    cout<<"9.Reverse"<<endl;
    cout<<"10.Iterative preorder"<<endl;
    cout<<"11.Iterative postorder"<<endl;
    cout<<"12.Iterative inorder"<<endl;
    cout<<"-1. Exit"<<endl;
    cout<<"Enter operation to be performed : ";
    cin>>ch;
    switch(ch)
    {
    
    break;
    case 1:
    if (root==NULL)
    cout<<"Tree is empty"<<endl;
    else
    preorder(root);
    break;
    case 2:
    if (root==NULL)
    cout<<"Tree is empty"<<endl;
    else
    postorder(root);
    break;
    case 3:
    if (root==NULL)
    cout<<"Tree is empty"<<endl;
    else
    inorder(root);
    break;
    case 4:
    cout<<"The height of the tree is : "<<height(root)<<endl;
    break;
    case 5:
    root_copy=copy(root);
    if (root_copy==NULL)
    cout<<"The tree is empty"<<endl;
    else{
    cout<<"The tree has been copied"<<endl;
    cout<<"The inorder traversal is : ";
    inorder(root_copy);}
    cout<<endl;
    break;
    case 6:
    cout<<"The number of leave are :"<<leaves(root);
    break;
    case 7:
    cout<<"The number of of internal nodes are :"<<internal(root);
    break;
    case 8:
    delet(root);
    cout<<"The tree has been deleted"<<endl;
    root=NULL;
    break;
    case 9:
    reversal(root); 
    break;
    case 10:
    ipreorder(root);
    break;
    case 11:
    ipostorder(root);
    break;
    case 12:
    iinorder(root);
    break;
    }}while(ch!=-1);
    cout<<"Thank You"; 
    return 0;
}