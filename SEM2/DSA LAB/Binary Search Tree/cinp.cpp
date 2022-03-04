#include<iostream>
#include<cstring>
using namespace std;
bool correct(string a)
{
    bool op=true;
    for(int i=0;i<a.length();i++)
    {
        char ch=a[i];
        if(ch>=97 && ch<=122)
        {
            continue;
        }
        else
        {
            op=false;
        }
    }
    return op;
};

int main(){
    string a;
    cout<<"Enter string :";
    cin>>a;
    cout<<correct(a);
    if(correct(a)==true)
    {
        cout<<"Correct String ";
    } 
    else{
        cout<<"Invalid";
    }

    return 0;
}