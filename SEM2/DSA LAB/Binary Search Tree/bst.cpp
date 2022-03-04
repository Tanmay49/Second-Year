// A Dictionary stores keywords and its meanings. Provide facility for adding new keywords,
// deleting keywords, updating values of any entry.
// Provide facility to display whole data sorted in ascending/ Descending order.
// Also find how many maximum comparisons may require for finding any keyword.
// Use Binary Search Tree for implementation.
#include <iostream>
using namespace std;
int count{0};
bool correct(string a)
{
    bool op = true;
    for (int i = 0; i < a.length(); i++)
    {
        char ch = a[i];
        if (ch >= 97 && ch <= 122)
        {
            continue;
        }
        else if (ch == 32 || ch == 44 || ch == 39 || ch == 46) // 32 is space 44 is comma 39 is apostrophe 46 fullstop.
        {
            continue;
        }
        else
        {
            op = false;
        }
    }
    return op;
};

struct Node
{
    string keyword, meaning;
    Node *left, *right;
};

Node *newNode(string keyword, string meaning)
{
    Node *newNode = new Node;
    newNode->keyword = keyword;
    newNode->meaning = meaning;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
};

Node *insert(Node *root, string keyword, string meaning)
{
    if (root == NULL)
    {
        root = newNode(keyword, meaning);
    }
    else if (keyword <= root->keyword)
    {
        root->left = insert(root->left, keyword, meaning);
    }
    else
    {
        root->right = insert(root->right, keyword, meaning);
    }

    return root;
};

Node *create(Node *root)

{
    string keyword, meaning;
    bool x, y = true;
    while (x)
    {
        try
        {
            cout << "Enter keyword : ";
            getline(cin >> ws, keyword);
            if (correct(keyword) == false)
            {
                throw 1;
            }
            else
            {
                x = false;
            }
        }
        catch (...)
        {
            cout << "Enter valid string" << endl;
        }
    }
    while (y)
    {
        try
        {

            cout << "Enter meaning : ";
            getline(cin >> ws, meaning);
            if (correct(meaning) == false)
            {
                throw 1;
            }
            else
            {
                y = false;
            }
        }
        catch (...)
        {
            cout << "Enter valid string" << endl;
        }
    }

    root = insert(root, keyword, meaning);
    return root;
};

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);

        cout << root->keyword << " : " << root->meaning << endl;
        inorder(root->right);
    }
}

void reverseorder(Node *root)
{
    if (root != NULL)
    {
        reverseorder(root->right);
        cout << root->keyword << " : " << root->meaning << endl;
        reverseorder(root->left);
    }
}

Node *searc(Node *root, string keyword)
{
    count += 1;
    if (root == NULL || root->keyword == keyword)
    {
        return root;
    }
    if (root->keyword < keyword)
    {
        return searc(root->right, keyword);
    }
    else
    {
        return searc(root->left, keyword);
    }
};

Node *s(Node *root)
{
    string search;
    bool x = true;
    while (x)
    {
        try
        {

            cout << "Enter Search element : ";
            cin >> search;

            if (correct(search))
            {
                x = false;
            }
            else
            {
                throw 1;
            }
        }
        catch (...)
        {
            cout << "Enter valid string" << endl;
        }
    }
    Node *a;
    a = searc(root, search);
    return a;
}

void update(Node *root, string keyword, string up_meaning)
{
    Node *a;
    a = searc(root, keyword);
    if (a)
    {
        a->meaning = up_meaning;
    }
    else
    {
        cout << "Word Not Found" << endl;
    }
}

Node *Minvalue(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }

    return root;
};

Node *deleteNode(Node *root, string key)
{
    if (root == NULL)
        return root;

    else if (key < root->keyword)
        root->left = deleteNode(root->left, key);
    else if (key > root->keyword)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete (root);
            root = NULL;
        }
        else if (root->left == NULL)
        {
            Node *temp = root;
            root = root->right;
            delete temp;
        }

        else if (root->right == NULL)
        {
            Node *temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            Node *temp = Minvalue(root->right);
            root->keyword = temp->keyword;
            root->meaning = temp->meaning;
            root->right = deleteNode(root->right, temp->keyword);
        }
    }
    return root;
}
int main()
{
    Node *root = NULL;
    Node *a, *c;
    int ch;
    string up_keyword;
    string keyword;
    do
    {
        cout << "MENU" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Print in ascending order" << endl;
        cout << "3. Print in descending order" << endl;
        cout << "4. Search" << endl;
        cout << "5.Update" << endl;
        cout << "6.Delete" << endl;
        cout << "-1. Exit" << endl;
        cout << "Enter operation to be performed : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            root = create(root);
            break;
        case 2:
            if (root == NULL)
            {
                cout << "**********************" << endl;
                cout << "Tree is empty" << endl;
                cout << "**********************" << endl;
            }
            else
            {
                cout << "**********************" << endl;
                inorder(root);
                cout << "**********************" << endl;
            }
            break;
        case 3:
            if (root == NULL)
            {
                cout << "**********************" << endl;
                cout << "Tree is empty" << endl;
                cout << "**********************" << endl;
            }
            else
            {
                cout << "**********************" << endl;
                reverseorder(root);
                cout << "**********************" << endl;
            }
            break;
        case 4:
            if (root == NULL)
            {
                cout << "**********************" << endl;
                cout << "Tree is empty" << endl;
                cout << "**********************" << endl;
            }
            else
            {
                a = s(root);
                if (a)
                {
                    cout << "**********************" << endl;
                    cout << "Found " << endl;
                    cout << a->keyword << " : " << a->meaning << endl;
                    cout << "Number of comparisons" << count << endl;
                    count = 0;
                    cout << "**********************" << endl;
                }
                else
                {
                    cout << "**********************" << endl;
                    cout << "Not found " << endl;
                    cout << "Number of comparisons" << count << endl;
                    count = 0;
                    cout << "**********************" << endl;
                }
            }
            break;
        case 5:

            cout << "Original string : ";
            cin >> keyword;
            cout << endl;
            c = searc(root, keyword);
            if (c)
            {
                cout << "New meaning : ";
                cin >> up_keyword;
                update(root, keyword, up_keyword);
            }
            else
            {
                cout << "No word present" << endl;
            }
            break;

        case 6:
            string key;
            cout << "Enter string : ";
            cin >> key;
            Node *b = searc(root, key);
            if (b)
                root = deleteNode(root, key);
            else
            {
                cout << "Element not present in tree" << endl;
            }
            break;
        }
    } while (ch != -1);
    cout << "Thank You";
    return 0;
}