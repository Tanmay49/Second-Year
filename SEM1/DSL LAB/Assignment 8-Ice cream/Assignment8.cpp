#include <iostream>
#include <conio.h>
using namespace std;
class Node {
    int data;  //satores data of node
    Node *next; //stores address of next node
    public:
    friend class Linkedlist;
    
    Node(int a) //default constructor
    {
        data=a;
        next=NULL;
    }
    
};

class Linkedlist{
    Node* head; //stores address of first node
    public:
    Linkedlist()
    {
        head=NULL;
    }
    Linkedlist Intersection(Linkedlist A,Linkedlist B);
    Linkedlist Union(Linkedlist A,Linkedlist B);
    Linkedlist Comp(Linkedlist A,Linkedlist B);
    void insertNode(int); // to insert a node at any postion
    void printSet(); // prints linked list
    

};

void Linkedlist::insertNode(int x)
{
    Node *t;
    t=new Node(x); //constructor
    if(head==NULL){
        head=t;
        }
    else{
        t->next=head;
        head=t;
    }
}

Linkedlist Linkedlist::Intersection(Linkedlist A ,Linkedlist B)
{   Node *t1,*t2;
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

Linkedlist Linkedlist::Union(Linkedlist A,Linkedlist B)
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
        if (flag!=1) //does not like
        {   
            
            result.insertNode(t1->data);
        }
        t1=t1->next;


    }
    return result;
}

void Linkedlist::printSet()
{
    Node *t1;
    t1=this->head;
    while(t1!=NULL)
    {
        cout<<t1->data<<" ";
        t1=t1->next;
    }    
}

int main()
{
    Linkedlist all,intersecn,unin,Vanilla,Butterscotch,compli;
    int count,Acount,Bcount,roll;
    cout<<"Enter the total number of students in class : ";
    cin>>count;
    
    for(int i=0;i<count;i++){
        cout<<"\nEnter the roll number of students in class "<<endl;
        cin>>roll;
        all.insertNode(roll);
    }

    cout<<"Enter the no.of.students that like Vanilla Icecream "<<endl;
    cin>>Acount;
    for(int i=0;i<Acount;i++){
        cout<<"Enter the roll number : ";
        cin>>roll;
        Vanilla.insertNode(roll);
    }

    cout<<"Enter the no.of.students that like Butterscotch Icecream "<<endl;
    cin>>Bcount;
    for(int i=0;i<Bcount;i++){
        cout<<"Enter the roll number : ";
        cin>>roll;
        Butterscotch.insertNode(roll);
    }

    intersecn = intersecn.Intersection(Vanilla, Butterscotch);
    unin = unin.Union(Vanilla, Butterscotch);
    compli=compli.Comp(all,unin);
    cout << "\n Students who like vanilla IceCream " << endl;
    Vanilla.printSet();
    cout << "\n Students who like Butterscotch IceCream " << endl;
    Butterscotch.printSet();
    cout << "\n A - Students who like both Vanilla and Butterscotch Icecream " << endl;
    intersecn.printSet();
    cout<<"\n B - Students who like either Vanilla or Butterscotch "<<endl;
    unin.printSet();
    cout << "\n C - Students who like neither Vanilla nor Butterscotch " << endl;
    compli.printSet();
    return 0;
}