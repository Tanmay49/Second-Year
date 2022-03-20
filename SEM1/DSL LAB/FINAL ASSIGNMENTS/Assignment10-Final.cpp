/*INFIX TO POSTFIX*/
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
                T peek();
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
        template <class T>
        T Stack<T>:: peek()
        {
            return st[top];
        }   


 int prec(char c)
{
     if(c=='/'||c=='*')
    {
    return 2;}
    else if(c=='+'||c=='-')
    {return 1;}
    else
    {return 0;}
}
int operation(int a,int b,char c)
{
    if (c=='+')
    {
        return a+b;
    }
    else if (c=='-')
    {
        return a-b;
    }
    else if (c=='*')
    {
        return a*b;
    }
    else if (c=='/')
    {
        return a/b;
    }
    else{
        return 1;
    }
}
string itf(string s)
{
    Stack<char> st;
    string ret;
    for(int i=0;i<s.length();i++)
    {
         if((s[i]>='0'&& s[i]<='9'))
         {
             ret+=s[i]; //if it is a number or a char concatenate it to string.
            }
        else if(s[i]=='(')//if it is an opening bracket push it in the stack
             {
                 
                 st.push(s[i]);
             }
             else if(s[i]==')')
             {
                 while(!st.empty() && st.peek()!='(')
                 {
                     ret+=st.peek();//concatenate string till opening bracket is reached.
                     st.pop();//pop element from stack.
                 }
                     st.pop();
         }
         else{
             while(!st.empty() && (prec(st.peek())>=prec(s[i])))
             {
                 ret+=st.peek();//if higher precedence found concatenate it and pop it out
                 st.pop();
             }
             st.push(s[i]);//else push it in stack
         }
    }
    while(!st.empty())
    {
        ret+=st.peek();
        st.pop();
    }
return ret;
}
void peval(string s)
{
    Stack<int> st;
    Stack<char> op;
    for (int i = 0; i < s.length();i++)
    {
        char c = s[i];
        if(c=='(')
        {
            op.push(c);
        }
        else if((s[i]>='0'&& s[i]<='9'))
        {
            st.push(c-'0');
        }
        else if(c==')')
        {
            while(op.peek()!='(')
            {
            int op2=st.peek();
            st.pop();
            int op1=st.peek();
            st.pop();
            char c1=op.peek();
            op.pop();
            int result= operation(op1, op2,c1);

            st.push(result);
            }
            op.pop();
        }
            else if(c=='+'||c=='-'||c=='*'||c=='/')
            {
                while(!op.empty()&&op.peek()!='('&& prec(op.peek())>=prec(c))
                {
                    int b=st.peek();
                    st.pop();
                    int a=st.peek();
                    st.pop();
                    char ch2=op.peek();
                    op.pop();
                    int result= operation(a,b,ch2);

                    st.push(result);
                }
                op.push(c);
                            }
        
    }
    while(!op.empty())
            {
            int op2=st.peek();
            st.pop();
            int op1=st.peek();
            st.pop();
            char c1=op.peek();
            op.pop();
            int result= operation(op1, op2,c1);

            st.push(result);
            }
    cout<<"Result of expression : "<<st.peek()<<endl;
}
int main()
{
    string c,x;
    cout<<"Enter string : ";
    cin>>c;
    x=itf(c);
    cout<<x<<endl;
    peval(c);
    return 0;
}