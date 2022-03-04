/* ***************QUESTION*****************/

#include<iostream>
#include<cmath>
using namespace std;
class complex
{
     int real,img;
public:
   
    complex()   // default constructor
    {
    real=0;
    img=0;
    }
    complex operator +(complex); // declaration for addition
    complex operator *(complex); // declaration for multiplication
    friend ostream &operator<<(ostream&,complex&);  //output function
    friend istream &operator>>(istream&,complex&);  // input function
};
complex complex::operator +(complex obj)   
{
    complex temp;
    temp.real=real+obj.real;
    temp.img=img+obj.img;
    return (temp);
}

complex complex::operator *(complex obj)
{
    complex res;
    res.real=(real*obj.real)-(img*obj.img);
    res.img=(real*obj.img)+(img*obj.real);
    return (res);
}

istream &operator>>(istream & inp,complex& obj)  //defining (extraction)>> operator
{    
    cout << "Do you want to use the default values? (Yes/No) "; //Exception Handling to use default values.
        string z;
        cin >> z;
        if (z == "yes" ||z == "Yes" || z=="y" || z=="Y")
        {
            return inp;
        }
        else
        {
            for (;;)//Exception handling to check whether input is numeric.
            {
                cout << "Enter Complex no (real & imaginary): ";
                if (inp >> obj.real >> obj.img)
                {
                    return inp;
                    break;
                }
                else
                {
                    cout << "Invalid Complex Number\n";
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
            }
        }
    };



ostream &operator<<(ostream& out,complex& obj) //defining <<(insertion) operator
{
    char ch;
    out<<obj.real;   //displaying real part with object of ostream class
   if (obj.img<0){
        ch='-';
    }
    else{
        ch='+';
    }
    out<<ch<<abs(obj.img)<<"i"; //displaying imaginary part with object of ostream class
    return out;
}

int main()
{
    complex c1,c2,c3,c4;
    //Enter first complex number";
    
    cin>>c1;

    // Enter second complex number";
    
    cin>>c2;

    cout<<"\nArithmetic operations are :";
    c3=c1+c2;
    cout<<"\n Addition is:"<<c3;
   
    c4=c1*c2;
    cout<<"\n Multiplication is:"<<c4<<"\n";
    return 0;
}