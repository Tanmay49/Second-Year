#include<iostream>
#include<stack>
#include<math.h>
using namespace std;
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
    stack<char> st;
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
                 while(!st.empty() && st.top()!='(')
                 {
                     ret+=st.top();//concatenate string till opening bracket is reached.
                     st.pop();//pop element from stack.
                 }
                     st.pop();
         }
         else{
             while(!st.empty() && (prec(st.top())>=prec(s[i])))
             {
                 ret+=st.top();//if higher precedence found concatenate it and pop it out
                 st.pop();
             }
             st.push(s[i]);//else push it in stack
         }
    }
    while(!st.empty())
    {
        ret+=st.top();
        st.pop();
    }
return ret;
}
void peval(string s)
{
    stack<int> st;
    stack<char> op;
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
            while(op.top()!='(')
            {
            int op2=st.top();
            st.pop();
            int op1=st.top();
            st.pop();
            char c1=op.top();
            op.pop();
            int result= operation(op1, op2,c1);

            st.push(result);
            }
            op.pop();
        }
            else if(c=='+'||c=='-'||c=='*'||c=='/')
            {
                while(op.size()>0&&op.top()!='('&& prec(op.top())>=prec(c))
                {
                    int b=st.top();
                    st.pop();
                    int a=st.top();
                    st.pop();
                    char ch2=op.top();
                    op.pop();
                    int result= operation(a,b,ch2);

                    st.push(result);
                }
                op.push(c);
                            }
        
    }
    while(op.size()!=0)
            {
            int op2=st.top();
            st.pop();
            int op1=st.top();
            st.pop();
            char c1=op.top();
            op.pop();
            int result= operation(op1, op2,c1);

            st.push(result);
            }
    cout<<"Result of expression : "<<st.top()<<endl;
}
int main(){
    string c,d;
    cout<<"Enter equation";
    cin>>c;
    string e="(2+4)*5-1";
    d=itf(c);
    cout<<d<<endl;
    peval(e); 
}