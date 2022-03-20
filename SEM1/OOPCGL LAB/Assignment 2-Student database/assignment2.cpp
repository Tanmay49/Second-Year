/*
Experiment Number 2 : Develop a program in C++ to create a database of
student’s information system
containing the following information: Name, Roll number, Class, Division,
Date of Birth, Blood group,
Contactaddress, Telephone number, Driving license no. and other. Construct
the database with
suitable member functions. Make use of constructor, default constructor,
copy constructor,
destructor, static member functions, friend class, this pointer, inline
code and dynamic
memory allocation operators-new and delete as well as exception handling.
*/
#include <bits/stdc++.h>
#include <limits>
#include <ctime>
#include <iostream>
#include <string.h>
using namespace std;

class StudData;

class Student
{                   //Declaring all the variables required.
    string*name;
    unsigned int* roll_no;
    string* cls;
    string *division;
    string* dob;
    string *bloodgroup;
    static int count;

public:
    Student() // Default Constructor
    {
        name = new string;
        roll_no = new unsigned int;
        cls =new string;
        division = new string;
        dob = new string;
        bloodgroup = new string;
    }

    Student(Student &s){     //copy constructor
        this->name=new string;
        *name=*s.name;
        this->roll_no=new unsigned int;
        *roll_no=*s.roll_no;
        this->cls=new string;
        *cls=*s.cls;
        this->division=new string;
        *division=*s.division;
        this->dob=new string;
        *dob=*s.dob;
        this->bloodgroup=new string;
        *bloodgroup=*s.bloodgroup;
        
}
        
    static int getCount()    //function for returning number of values is database
    {
        return count;
    }
    ~Student(){             //destructor
        delete division;
        delete bloodgroup;  
        }
    void getData(StudData *); //Declaration of function for getting input
    void dispData(StudData *);//Declaration of function for printing output
    void updata(StudData *);
    void delData(StudData *);
    
};

class StudData
{
    string* caddress;
    string *telno;
    string *dlno;
    friend class Student;        //Declaration of friend class 
public:
    StudData()  //default constructor
    {
        caddress =new string;
        telno = new string;
        dlno = new string;
    }
        StudData(StudData &s){ 
        this->caddress=new string;   //copy constructor
        *caddress=*s.caddress;
        this->telno=new string;
        *telno=*s.telno;
        this->dlno=new string;
        *dlno=*s.dlno;
    }
    ~StudData()  //destructor
    {
        delete telno;
        delete dlno;
    }

    void getStudData()    //Function to get data
    {
        cout << "Enter Contact Address : ";
        string addr;
        cin.get();
        getline(cin,addr);
        *caddress=addr;
        while (true)             //Exception Handling to check whether input number is valid or not.
        {
            cout << "Enter telephone number";
            try
            {
                string z;
                cin >> z;
                if (z.length() != 10)
                {
                    throw "Telephone number is not 10 characters long\n";
                }
                for (char i : z)
                {
                    if (!isdigit(i))
                    {
                        throw "Telephone number entered must be a number\n";
                        break;
                    }
                }
                *telno = z;
                break;
            }
            catch (const char *err)
            {
                cout << err;
            }
        }

        cout << "Enter Driving License Number : ";
        cin>>*this->dlno;
        
    }

    void dispStudData() //Function to display data
    {
        cout << "Contact Address : " <<* caddress << endl;
        cout << "Telephone Number : " << *telno << endl;
        cout << "Driving License Number : " << *dlno << endl;
    }
    void upStudData(){
        StudData a;
        string t;
        cout<<"Update add(previous add"<<*caddress<<")"<<endl;
        cin.ignore();
        cin>>*caddress;
        cout<<"Update phone number(previous number"<<*telno<<")"<<endl;
        cin.ignore();
        cin>>*telno;
        cout<<"Update phone dl number(previous number"<<*dlno<<")"<<endl;
        cin.ignore();
        cin>>*dlno;
        };
    void delSData()
    {
        
      delete caddress;
      delete telno;
      delete dlno;
      
    };
};

inline void Student::updata(StudData *b)
{
    Student x;
    string t;
    cout<<"Update name(previous name: "<<*name<<endl;
    cin>>*name;
    while (true)                           //Exception handling to check whther a number is entered as roll number.
    {
        cout<<"Update roll number(previous roll number: "<<*roll_no<<endl;
            if (cin >> *roll_no)
            {
                break;
            }
            else
            {
                cout << "Invalid RollNo Number\n";
                cin.clear();
                cin.ignore(1000, '\n');
            }

    }
    cout<<"Update div(previous div: "<<*division<<endl;
    cin.ignore();
    cin>>*division;
    cout<<"Update cls(previous class: "<<*cls<<")"<<endl;
    cin.ignore();
    cin>>*cls;
    cout<<"Update dob(previous dob: "<<*dob<<")"<<endl;
    string c;
    cin.ignore();
    getline(cin,c);
    *dob=c;
    while (true)                 //Exception Handling to check whether calid bloodgroup is entered.
        {
            cout<<"Update bloodgroup(previous bloodgroup: "<<*bloodgroup<<endl;
            try
            {
                cin >> *this->bloodgroup;
                if (*this->bloodgroup == "A+" || *this->bloodgroup == "A-" || *this->bloodgroup == "B+" || *this->bloodgroup == "B-" || *this->bloodgroup == "AB+" || *this->bloodgroup == "AB+" || *this->bloodgroup == "O+" || *this->bloodgroup == "O-")
                {
                    break;
                }
                else
                {
                    throw "Blood group is not valid\n";
                }
            }
            catch (const char *err)
            {
                cout << err;
            }
        };
    b->upStudData();
};
inline void Student::delData(StudData *z)
{  
    
    delete name;
    delete roll_no;
    delete dob;
    delete division;
    delete cls;
    delete bloodgroup;
    z->delSData();
    count--;

}
inline void Student::getData(StudData *st)  //INline function to get data.
{   cout << "Enter name : ";
    cin>>*name;
    while (true)                           //Exception handling to check whther a number is entered as roll number.
    {
        cout << "Enter Roll no: ";
            if (cin >> *roll_no)
            {
                break;
            }
            else
            {
                cout << "Invalid RollNo Number\n";
                cin.clear();
                cin.ignore(1000, '\n');
            }

    }
    
    cout << "Enter Class(FE/SE/TE/BE) : ";
    string cl;
    cin.get();
    getline(cin, cl);
    *cls=cl;
    cout << "Enter Division : ";
    cin>>*division;
    cout << "Enter Date of Birth : ";
    string d;
    cin.get();
    getline(cin, d);
    *dob=d;
    while (true)                 //Exception Handling to check whether calid bloodgroup is entered.
        {
            cout << "Enter your blood group: ";
            try
            {
                cin >> *this->bloodgroup;
                if (*this->bloodgroup == "A+" || *this->bloodgroup == "A-" || *this->bloodgroup == "B+" || *this->bloodgroup == "B-" || *this->bloodgroup == "AB+" || *this->bloodgroup == "AB+" || *this->bloodgroup == "O+" || *this->bloodgroup == "O-")
                {
                    break;
                }
                else
                {
                    throw "Blood group is not valid\n";
                }
            }
            catch (const char *err)
            {
                cout << err;
            }
        }
    st->getStudData();      // pointer to function to get further data
    count++;
};

inline void Student::dispData(StudData *st1)//Function to display data
{
    cout << "Student Name : " << *name << endl;
    cout << "Roll Number : " << *roll_no << endl;
    cout << "Class : " << *cls << endl;
    cout << "Division : " << *division << endl;
    cout << "Date of Birth : " << *dob << endl;
    cout << "Blood Group : " <<*bloodgroup << endl;
    st1->dispStudData(); // pointer to function to display further data
};

int Student::count;

int main()  //Main function
{
    Student *stud1[100];     //array of objects of class Student
    StudData *stud2[100];    //array of objects of class StudData
    int n = 0;               //counter
    char ch;      
    int deleted;   
    int po;        

    do
    {
        stud1[n] = new Student;   
        stud2[n] = new StudData;
        stud1[n]->getData(stud2[n]);  //Calling getData() function to get data from user
        n++;
        cout << "Do you want to add another student (y/n) : ";
        cin >> ch;
        cin.get();
    } while (ch == 'y' || ch == 'Y');//Condition to add more objects to database.

    /*
  
    for (int i = 0; i < n; i++)
    {
        cout << "---------------------------------------------------------------" << endl;
        stud1[i]->dispData(stud2[i]);//Calling function dispData() to print values in database
    }*/
    int a={0};
    while (a!=-1)
    {
        
    cout<<"**************MENU************"<<endl;
    cout<<"1.Read database"<<endl;
    cout<<"2.Update database"<<endl;
    cout<<"3.Create new element in Database"<<endl;
    cout<<"4. Delete database"<<endl;
    cout<<"-1.Exit"<<endl;
    cin>>a;
    switch (a)
    {
    case 1:
    for (int i = 0; i < n; i++)
    {
        if(i!=po){
        
        cout << "---------------------------------------------------------------" << endl;
        stud1[i]->dispData(stud2[i]);
        }//Calling function dispData() to print values in database
    }

    cout << "---------------------------------------------------------------" << endl;
    cout<<"Total Students : "<<Student::getCount()<<endl;
    cout<< "---------------------------------------------------------------" << endl;
        
        break;
    case 2:
     int pos;
     cout<<"Enter position at which you want to update"<<endl;
     cin>>pos;
     if(Student::getCount()<pos || pos<0){
         cout<<"Enter valid postion"<<endl;
         break;
     }
     else{
      
     
    stud1[pos]->updata(stud2[pos]);
    }
    break;
    case 3:
    int posi;
    cout<<"Create"<<endl;
    cin>>posi;
    stud1[posi]=new Student;
    stud2[posi]=new StudData;
    stud1[posi]->getData(stud2[posi]);
    n++;
    break;
    case 4:
    
    cout<<"Enter position you want to delete"<<endl;
    cin>>po;

    stud1[po]->delData(stud2[po]);
    break;
    case -1:
        cout << "Exit" << endl;
        a=-1;
        break;
    default:
    cout<<"Enter valid choice"<<endl;
        break;
    }
    }
    
  
    return 0;
}

//End of programme.