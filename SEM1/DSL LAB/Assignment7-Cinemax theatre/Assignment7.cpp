/*
The ticket booking system of Cinemax theater has to be implemented using C++ program.
There are 10 rows and 7 seats in each row. Doubly circular linked list has to be maintained
to keep track of free seats at rows. Assume somerandom booking to start with. Use array to store
pointers (Head pointer) to each row. 

On demand

a) The list of available seats is to be displayed
b) The seats are to be booked
c) The booking can be cancelled
*/

#include <iostream>
using namespace std;
class node                         //Class to define a doubly circular linked list .
{ public: 
    node* next;                   //Next pointer
    node* prev; //Prev pointer
    int seat;   //Seat number
    string id;  //To take input for deletion 
    int status; 
    //Status of the booking. 
};
class cinemax      //Class to define functions that are to be performed.
{
public:
node* head,* tail ,* temp;  //head tail and temp pointer definitions.
cinemax()                  //Default constructor to set value of head to NULL indiacting a blank list formation.
{
head=NULL;
}
void create_list();
void display();
void book();
void cancel();
void avail();

};
void cinemax::create_list() //To create a doubly linked list
{
int i=1;
temp=new node;        //Dynamically allocate memory for the node.
temp->seat=1;         //Seat number=1
temp->status=0;       //Seat not booked 
temp->id="null";      // id is blank 
tail=head=temp;       
for(int i=2;i<=70;i++)
{
node *p;              // Creating an empty node 
p= new node;         //Creating a new node for 70 seats.
p->seat=i;
p->status=0;
p->id="null";
tail->next=p;
p->prev=tail;
tail=p;
tail->next=head;
head->prev=tail;     

}
}
void cinemax::display()
{
{ int r=1;          
node* temp;
temp=head;
int count=0;
cout<<"\n------------------------------------------------------------------------------------\n";
cout<<" Screen this way \n";
cout<<"------------------------------------------------------------------------------------\n";
while(temp->next!=head)    
{
if(temp->seat/10==0)
cout<<"S0"<<temp->seat<<" :";
else
cout<<"S"<<temp->seat<<" :";

if(temp->status==0)
cout<<"|_E_| ";
else
cout<<"|_B_| ";
count++;
if(count%7==0)
{
cout<<endl;
r++;
}
temp=temp->next;
}
cout<<"S"<<temp->seat<<" :";
if(temp->status==0)
cout<<"|_E_| ";
else
cout<<"|_B_| ";
}
}
void cinemax::book()
{ int x;
string y;
start:
cout<<"\n\n\nEnter seat number to be booked(Between 1 and 70)\n";
cin>>x;
cout<<"Enter your ID number\n";
cin>>y;
if(x<1||x>70)
{
cout<<"Enter correct seat number to book (1-70)\n";
goto start;
}
node *temp;
temp=new node;
temp=head;
while(temp->seat!=x)
{
temp=temp->next;
}

if(temp->status==1)
cout<<"Seat already booked!\n";
else{
temp->status=1;
temp->id=y;
cout<<"Seat "<<x<<" booked!\n";
}

}
void cinemax::cancel()
{
int x;
string y;
start:
cout<<"Enter seat number to cancel booking\n";
cin>>x;
cout<<"Enter you ID\n";
cin>>y;
if(x<1||x>70)
{
cout<<"Enter correct seat number to cancel (1-70)\n";
goto start;
}
node *temp;
temp=new node;
temp=head;
while(temp->seat!=x)
{
temp=temp->next;
}
if(temp->status==0)
{
cout<<"Seat not booked yet!!\n";
}
else
{
if(temp->id==y)
{
temp->status=0;
cout<<"Seat Cancelled!\n";
}

else
cout<<"Wrong User ID !!! Seat cannot be cancelled!!!\n";
}
}

int main()
{ cinemax obj;
obj.create_list();
int ch;
do
{
cout<<"\n*********************************************\n";
cout<<" MOVIE THEATRE\n";
cout<<"*********************************************\n";
cout<<"\n1.Current Seat Status\n2.Book Seat \n3.CancelSeat\n4.Exit\n";
cout<<"\nEnter Choice : ";
cin>>ch;
switch(ch)
{
case 1:obj.display();
break;
case 2: obj.book();
break;
case 3: obj.cancel();
break; 
}
}while(ch!=4);
return 0;
}
