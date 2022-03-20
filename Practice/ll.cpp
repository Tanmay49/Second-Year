#include<iostream>
using namespace std;
class Node
{
    public:
    int number;
    Node *next;

    Node()
    {
        this->number =NULL;
        this->next = NULL;
    }
    Node(int data)
    {
        this->number = data;
        this->next =NULL;
    }
};
class LL
{
    public:
    Node* start;
    LL() 
    {
        start=NULL;
    }
    void create(int);
    void print();
};

void LL::create(int data)
{
    Node *temp=new Node();
}
int main(){ 

    return 0;
}