#include <iostream>
#include <string>
using namespace std;
        template <class T>
        class Stack
        {
        public:
                Stack();
                void push(T i);
                T pop();
                bool empty();
                int top;
        T st[100];
                
        };

        template <class T>
        Stack<T>::Stack()
        {
                top = -1;
        }

        template <class T>
        void Stack<T>::push(T i)
        {
                st[++top] = i;
        }

        template <class T>
        T Stack<T>::pop()
        {
                return st[top--];
        }
        template <class T>
        bool Stack<T>::empty()
        {
            return top==-1;
        }
bool isBalanced(string expr) {
   Stack<char> s;
   char ch;
   for (int i=0; i<expr.length(); i++) {    //for each character in the expression, check conditions
      if (expr[i]=='('||expr[i]=='['||expr[i]=='{') {    //when it is opening bracket, push into     stack
         s.push(expr[i]);
         cout<<expr[i]<<" is pushed into stack"<<endl;
         continue;
      }
      if (s.empty())    //stack cannot be empty as it is not opening bracket, there must be closing     bracket
         return false;
         switch (expr[i]) {
            case ')':    //for closing parenthesis, pop it and check for braces and square brackets
               ch =s.pop(); 
               cout<<ch<<" is popped "<<endl;
               
               if (ch=='{' || ch=='[')
               {
                  cout<<"opening bracket not found"<<endl;
                  return false;

               }
                  
                  break;
            case '}': //for closing braces, pop it and check for parenthesis and square brackets
               ch = s.pop();
               cout<<ch<<" is popped "<<endl;
               if (ch=='(' || ch=='[')
               {
                   cout<<"{ bracket not found"<<endl;
                  return false;
                 }  break;
            case ']': //for closing square bracket, pop it and check for braces and parenthesis
               ch = s.pop();
               cout<<ch<<" is popped "<<endl;
               if (ch =='(' || ch == '{')
               {
                   cout<<"[ bracket not found"<<endl;
                  return false;
                 }  break;
         }
      }
      return (s.empty()); //when stack is empty, return true
}
int main(){ 
    string expr ;
   cout << "Enter string";
   cin >> expr;
   if (isBalanced(expr))
      cout << "Balanced";
   else
      cout << "Not Balanced";
    
     return 0;
}