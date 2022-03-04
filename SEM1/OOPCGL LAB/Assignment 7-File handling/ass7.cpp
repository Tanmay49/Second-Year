/*
Write a C++ program that creates an output file, writes information to it, closes the file, open it 
again as an input file and read the information from the file. 
*/
#include<iostream>
#include<fstream>
/*1.fstreambase
ifstream-->Derived from 1[Used to read information from a file]
ofstream-->Derived from 1[Used to write information from a file]
*/
#include<string>
using namespace std;
void readfile()  //Function to read data from file.
{
    ifstream in; // in object created of ifstream clas.
    in.open("ass7.txt");//.open used to open the file
     if (!in)
    {
        cout << "Error opening the file" << endl;
        return;
    }
     
    string l;     // string l creaetd to read data from file.
    

    while(in.eof()==0)//End of file used to read all data present in the file
    {
        getline(in, l);
        cout<<l<<endl;// printing all data present in the file
    }
    in.close(); // close the file

}
void writefile() //Function to write data to file
{
    const int max=2500;
    char a[max];
    ofstream outfile;
    outfile.open("ass7.txt"); // append to file so previous data is not deleted.
    cout<<"Enter what you want to enter...ending with a $"<<endl;
    cin.get(a, max,'$');
    cin.ignore(100000,'\n');
    outfile<<a<<endl;
    outfile.close(); // close

}
void appendfile() //Function to append data to file
{
    const int max=2500;
    char a[max];
    ofstream out;
    out.open("ass7.txt", std::ios_base::app);
    cout<<"Enter what you want to enter...ending with a $"<<endl;
    cin.get(a,max,'$');
    cin.ignore(100000,'\n');
    out<<a<<endl;
    out.close(); // close the file
}
int main()
{
    int ch={0};
    char ans;
    do
    {
        cout << "*********Menu********" << endl;
        cout << "1. Write Data(To write in a fresh file)" << endl;
        cout << "2. Append Data(To continue writing)" << endl; ;
        cout << "3. Read Data" << endl;
        cout << "4. Exit"<<endl;
        cout << "Choose operations u want to perform? ";
        cin >> ch;

        switch (ch)
        {
        case 1:
        {
            writefile();
            break;
        }
        case 2:
        {
            appendfile();
            break;
        }

        case 3:
        {
            readfile();
            break;
        }
        case 4:
        {
            exit(0);
            break;
        }
        default:
        {
            cout << "INVALID CHOICE" << endl;
            break;
        }
        }
       cout<<"Do you want to continue(y/n)"<<endl;
       cin>>ans;
    } while (ans=='y');
    return 0;
}