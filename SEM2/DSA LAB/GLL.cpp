
//IMPLEMENT SET USING GLL

#include <iostream>

using namespace std;

class node
{
    bool flag;
    node *next;
    union subnode //Union is used for efficient memory utilization
    {
        node *down; // down pointer  for creating sublist
        char data;
    } u;

public:
    friend class gll;
};

class gll
{
    node *head;

public:
    gll()
    {
        head = NULL;
    }

    void createlist();
    node *createsublist();
    void display();
    void displaysublist(node *);
};

void gll ::createlist()
{
    node *tmpnode, *sublist;
    char data;
    node *tmp = head;

    //Choice for whether to add a single element or create a sublist
    cout << "1)Add a single element  \n"
         << "2)Create sublist  \n";

    int opt;
    cout << "Enter choice" << endl;

    cin >> opt;
    if (opt == 1)
    {

        tmpnode = new node;
        cout << "Enter data" << endl;
        cin >> data;
        tmpnode->u.data = data;
        tmpnode->next = nullptr;
        tmpnode->flag = 0;
    }
    else if (opt == 2)
    {
        tmpnode = new node;
        tmpnode->flag = 1;
        tmpnode->u.down = createsublist(); //Call for create sublist function which will generate sublist and return the start pointer which is assigned to down pointer
        tmpnode->next = nullptr;
    }
    if (head == NULL)
    {
        head = tmpnode;
    }
    else
    {
        while (tmp->next != nullptr) //moving to last pointer
        {
            tmp = tmp->next;
        }
        tmp->next = tmpnode;
    }

    cout << "Node added\n";
}

node *gll ::createsublist()
{
    node *start = NULL, *tmp; //Start pointer is the local head pointer of the sublist
    int no=1;


    while (1)
    {
        cout << "For node "<<no<<" - \n" ;
        node *a;

        char data;
        cout << "1)Add a single element  \n"
             << "2)Create sublist  \n"
             << "3)End\n";

        int opt;
        cout << "Enter your choice\n";
        cin >> opt;
        
            if (opt == 1)
            {
                a = new node;
                cout << "Enter data\n";
                cin >> data;
                a->u.data = data;
                a->flag = 0;
                a->next = nullptr;
            }

            else if (opt == 2)

            {
                a = new node;
                a->flag = 1;
                a->u.down = createsublist(); //recursive call for create sublist function which returns the head pointer of the list which is then assigned to down pointer
                a->next = nullptr;
            }
            else if ( opt == 3)
            {
                break ;
            }

            if (start == NULL)
            {
                start = a;
            }
            else
            {
                tmp = start;
                while (tmp->next != NULL)
                {
                    tmp = tmp->next;
                }
                tmp->next = a;
            }

            cout << "Sublist node added\n";
            no++ ;
            
    }
    return start;
}

void gll ::display()
{

    node *tmp, *a = nullptr;
    if (head == nullptr)
    {
        cout << "Empty list " << endl;
        return;
    }

    tmp = head;
    cout << "( ";
    while (tmp != NULL)
    {
        if (tmp->flag == 1) //  1 for showing that node contains a sublist
        {
            a = tmp->u.down;

            displaysublist(a); //call for display sublist function
        }
        else
        {
            cout << " " << tmp->u.data << ", ";
        }
        tmp = tmp->next;
    }

    cout << " )\n";
}

void gll ::displaysublist(node *t)
{
    cout << "( ";
    while (t != nullptr)
    {
        if (t->flag == 0)
        {
            cout << " " << t->u.data << " , ";
        }
        else
        {

            displaysublist(t->u.down); //recursive call for display sublist function
        }
        t = t->next;
    }

    cout << " ) ";
}

int main()
{
    gll a;
    while (1)
    {

        cout << "1)Add a node\n"
             << "2)Display list\n"
             << "3)Exit\n";

        int opt;
        cout << "Enter the operation you want to perform\n";
        cin >> opt;
        if (opt == 1)
        {
            a.createlist();
        }
        else if (opt == 2)
        {
            a.display();
        }
        else if (opt == 0)
        {
            cout << "Program terminated\n";
            return 0;
        }
        else
        {
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}