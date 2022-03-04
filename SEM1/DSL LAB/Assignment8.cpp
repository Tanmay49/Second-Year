#include <iostream>
using namespace std;
  
// Node class to represent
// a node of the linked list.
class Node {
public:
    int data;
    Node* next;
  
    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }
  
    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
  
// Linked list class to
// implement a linked list.
class Linkedlist {
    Node* head;
  
public:
    // Default constructor
    Linkedlist() { head = NULL; }
  
    // Function to insert a
    // node at the end of the
    // linked list.
    void insertNode(int);
  
    // Function to print the
    // linked list.
    void printList();
  
    // Function to delete the
    // node at given position
    int search(int);
    int ispresent(Linkedlist A,int);
    Linkedlist intersection(Linkedlist A, Linkedlist B);
    Linkedlist Uni(Linkedlist A, Linkedlist B);
    Linkedlist Comp(Linkedlist A, Linkedlist B);;
    
};
// Function to insert a new node.
void Linkedlist::insertNode(int data)
{
    // Create the new Node.
    Node* newNode = new Node(data);
  
    // Assign to head
    if (head == NULL) {
        head = newNode;
        return;
    }
  
    // Traverse till end of list
    Node* temp = head;
    while (temp->next != NULL) {
  
        // Update temp
        temp = temp->next;
    }
  
    // Insert at the last.
    temp->next = newNode;
}
  
// Function to print the
// nodes of the linked list.
void Linkedlist::printList()
{
    Node* temp = head;
  
    // Check for empty list.
    if (head == NULL) {
        cout << "List empty" << endl;
        return;
    }
  
    // Traverse the list.
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int Linkedlist::search(int search)
{
    Node* temp = head;
    while (temp != NULL) {
        if(temp->data!=search) {
            temp = temp->next;
        }
        else{
           return 1;
           break;  
        }
    }
};
int Linkedlist::ispresent(Linkedlist A,int search)
{
    Node *t1;
    t1=A.head;
    while(t1 != NULL) {
        if(t1->data!=search) {
            t1 = t1->next;
        }
        else{
            return 1;
        }
    }
};
  
Linkedlist Linkedlist ::intersection(Linkedlist A, Linkedlist B){
    Node *t1,*t2;
    Linkedlist result;
    t1=A.head; //head of A
    t2=B.head; //head of B
    while(t2!=NULL)
    {   
        t1=A.head;
        while(t1!=NULL)
        {   
            if (t1->data==t2->data)
            {  
               result.insertNode(t2->data);
           
            } 
            t1=t1->next;
        }
        t2=t2->next;
    }
    return result;
}
Linkedlist Linkedlist ::Uni(Linkedlist A, Linkedlist B)
{
    Linkedlist result;
    Node *t1,*t2; 
    int flag=0;
    t1=A.head;
    t2=B.head; 
    while(t1!=NULL)
    {
        result.insertNode(t1->data);
        t1=t1->next;
    }
    t1=A.head;
    while(t2!=NULL)
    {   
        flag=0;
        t1=A.head;
        while(t1!=NULL)
        {
            if (t1->data==t2->data)
            {
                flag=1;
            }
            t1=t1->next;
        }

        if (flag!=1)
        {
            result.insertNode(t2->data);
        }
        t2=t2->next;
    }
    return result;  
}

Linkedlist Linkedlist::Comp(Linkedlist All ,Linkedlist unin)
{
    Linkedlist result;
    Node *t1,*t2;
    t1=All.head;
    t2=unin.head;
    int flag=0;
    while(t1!=NULL)
    {   
        flag=0;
        t2=unin.head;
        while(t2!=NULL)
        {
            if (t1->data==t2->data)
            {
                flag=1;
            }
            t2=t2->next;   
        }
        if (flag!=1) 
        {   
            
            result.insertNode(t1->data);
        }
        t1=t1->next;


    }
    return result;
}

// Driver Code
int main()
{
    Linkedlist total,vanila,butterscotch,intersection,uni,comp,int2;
    int t,v,b;
    cout<<"Enter total number of students: ";
    cin>>t;
    int x;
    cout<<"Enter roll number";
    cin>>x;
    total.insertNode(x);
    for (int i=1; i<t; i++)
    {
        int y;
        cout<<"\nEnter roll number";
        cin>>y;
        if(total.search(y)==1)
        {
            cout<<"roll number exists\n";
            i-=1;
        }
        else{
            total.insertNode(y);
        }
        
    }
    bool go=true;
    while(go){
    cout<<"\nEnter total number of students who eat vanila ";
    cin>>v;
    if(v>t)
    {
        cout<<"total number of students who eat vanila cannot be greater than students present in class";
    }
    else{
        go=false;
    }
    }
    int a;
    bool goo=true;
    while(goo){
    cout<<"Enter roll number";
    cin>>a;
    if(vanila.ispresent(total,a)==1)
            {
                vanila.insertNode(a);
                goo=false;
            }
            else{
                cout<<"roll number not present in class\n";
            }
    }
    for(int i=1;i<v;i++)
    {
        int z;
        cout<<"Enter roll number : ";
        cin>>z;
        if(vanila.search(z)==1)
        {
            cout<<"Roll number already exists\n";
            i-=1;
        }
        else{
            if(vanila.ispresent(total,z)==1)
            {
                vanila.insertNode(z);
            }
            else{
                cout<<"roll number not present in class\n";
                i-=1;
            }
        }
    }
    bool bo=true;
    while(bo){
    cout<<"\nEnter total number of students who eat butterscotch ";
    cin>>b;
    if(b>t)
    {
        cout<<"total number of students who eat butterscotch cannot be greater than students present in class";
    }
    else{
        bo=false;
    }
    }
     int q;
    bool boo=true;
    while(boo){
    cout<<"Enter roll number";
    cin>>q;
    if(butterscotch.ispresent(total,q)==1)
            {
                butterscotch.insertNode(q);
                boo=false;
            }
            else{
                cout<<"roll number not present in class\n";
            }
    }
    for(int i=1;i<b;i++)
    {
        int z;
        cout<<"Enter roll number : ";
        cin>>z;
        if(butterscotch.search(z)==1)
        {
            cout<<"Roll number already exists\n";
            i-=1;
        }
        else{
            if(butterscotch.ispresent(total,z)==1)
            {
                butterscotch.insertNode(z);
            }
            else{
                cout<<"roll number not present in class\n";
                i-=1;
            }
        }
    }        
    cout<<"Students who like vanilla";
    vanila.printList();
    cout<<endl;
    cout<<"Students who like Butterscotch";
    butterscotch.printList();
    cout<<endl;
    intersection=intersection.intersection(vanila,butterscotch);
    cout<<"Students who like both Vanilla and Butterscotch : ";
    intersection.printList();
    cout<<endl;
    uni=uni.Uni(vanila,butterscotch);
    int2=int2.Comp(uni,intersection);
    cout<<"Students who like either Vanilla or Butterscotch : ";
    int2.printList();
    cout<<endl;
    comp=comp.Comp(total,uni);
    cout<<"Students who like neither : ";
    comp.printList();
    return 0;
}