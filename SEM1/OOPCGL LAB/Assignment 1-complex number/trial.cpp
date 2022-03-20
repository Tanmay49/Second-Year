#include<iostream>
#include<cmath>
using namespace std;
class Complex
{
    int real,img;
    public:
    
    friend  ostream &operator<< (ostream &out,Complex const &  obj );
    friend istream & operator>> (istream &in,Complex & obj );
        Complex(int r=0,int i=0)
        {
            real =r;
            img =i;
        }
        Complex operator + (Complex &obj)
        {
            Complex res;
            res.real =real + obj.real;
            res.img =img + obj.img;
            return res;
        }
        Complex operator * (Complex &obj)
        {
            Complex res;
            res.real=(real*obj.real)-(img*obj.img);
            res.img=(real*obj.img)+(img*obj.real);
            return res;
        }
};
ostream & operator<< (ostream &out,Complex const  & obj )
{
    char c;
    if(obj.img>=0)
    {
        c='+';
    }
    else
    {
        c='-';
    }
    out << obj.real<<c;
    out << abs (obj.img)<<"i";
    return out;
};
istream & operator>> (istream & in,Complex  & obj )
{
    char c;
    cout<<"Do you want to take default values?";
    cin>>c;
    if(c=='y'||c=='Y')
    return in;
    else
    {
    cout<<"Enter real part\n";
    in>>obj.real;
    cout<<"Enter imag part\n";
    in>>obj.img;
    return in;
}}
    int main(){ 
        Complex c1,c2,c3,c4;
        cout<<"Enter first number\n";
        cin>>c1;
        cout<<"Enter second number\n";
        cin>>c2;
        c3=c1+c2;
        c4=c1*c2;
        cout<<"First number : ";
        cout<<c1;
        cout<<"Second number : ";
        cout<<c2;
        cout<<"addition is";
        cout<<c3;
        cout<<"subtraction is";
        cout<<c4;
     return 0;
}