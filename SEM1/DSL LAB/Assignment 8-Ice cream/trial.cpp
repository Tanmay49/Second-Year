#include<iostream>
#include<vector>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    friend class SSL;
    Node()
    {
        data = 0;
        next =NULL;
    }
    Node(int data)
    {
        this->data=data;
        this->next = NULL;
    }
};
class SLL
{
    Node *head;
    public:
    SLL()
    {head = NULL;}
    SLL intersection(SLL A, SLL B);
    SLL Uni(SLL A, SLL B);
    SLL Comp(SLL A, SLL B);
void iNode(int data)
    {
        Node*newNode= new Node(data);

        if(head==NULL)
        {
        head = newNode;
        return;
        }
        Node *temp = head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
       }
        
void printList()
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

};
SLL SLL ::intersection(SLL A, SLL B){
    Node *t1,*t2;
    SLL result;
    t1=A.head; //head of A
    t2=B.head; //head of B
    while(t2!=NULL)
    {   
        t1=A.head;
        while(t1!=NULL)
        {   
            if (t1->data==t2->data)
            {  
               result.iNode(t2->data);
           
            } 
            t1=t1->next;
        }
        t2=t2->next;
    }
    return result;
}
SLL SLL::Uni(SLL A,SLL B)
{
    SLL result;
    Node *t1,*t2; 
    int flag=0;
    t1=A.head;
    t2=B.head; 
    while(t1!=NULL)
    {
        result.iNode(t1->data);
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
            result.iNode(t2->data);
        }
        t2=t2->next;
    }
    return result;  
}

SLL SLL::Comp(SLL All ,SLL unin)
{
    SLL result;
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
            
            result.iNode(t1->data);
        }
        t1=t1->next;


    }
    return result;
}

  
// Driver Code
int main()
{
    SLL vanila,butterscotch,total,intersection,uni,comp,int2;
    int v,b,t;
    int a;
    cout<<"Enter total number of students who like vanilla";
    cin>>v;
    for (int i=0; i<v; i++)
    {
        cout<<"Enter roll number";
        cin>>a;
        vanila.iNode(a);
    }
    cout<<"Enter total number of students who like butterscotch";
    cin>>b;
    for (int i=0; i<b; i++)
    {
        cout<<"Enter roll number";
        cin>>a;
        butterscotch.iNode(a);
    }
     bool go=true;
    while(go)
    {try
    {
cout<<"Enter total number of students who are present in the class";
    cin>>t;
    if(t<v+b)
    {
        throw 1;
    }
    else{
        go=false;
    }    
    }
    catch(...)
    {
        cout<<"Total cannot be less than"<<a+b<<endl;
    }
    }
    for (int i=0; i<t; i++)
    {
        cout<<"Enter roll number";
        cin>>a;
        

        total.iNode(a);
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