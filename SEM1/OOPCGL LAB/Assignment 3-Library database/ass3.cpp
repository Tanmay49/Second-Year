/*
Imagine a publishing company which does marketing for book and audio cassette 
versions. Create a class publication that stores the title (a string) and price (type float) of 
a publication. 
From this class derive two classes: book, which adds a page count (type int), and tape, 
which adds a playing time in minutes (type float).
Write a program that instantiates the book and tape classes, allows user to enter data 
and displays the data members. If an exception is caught, replace all the data member 
values with zero values.
*/
#include<iostream>
#include<stdlib.h>
using namespace std;
const int maxrow=10;
class Publications                      // publication class starts
{ 
    public:
    float Pricebook[maxrow]={};
    string Titlebook[maxrow]={}; 
    float price;
    string title;
};
class Book:public Publications
{
public:
    float Pagecount[maxrow]={};
    float pgcnt=1;
   void Addrecord()
    {
        cin.ignore();
        cout<<"Enter Publication info : ";
        getline(cin,title);
        try{
            cout<<"Enter price of publication : ";
            if(price<=0)
            {
                throw price;
            }
        }
        catch(...)
        {
            title="    ";
            price=0.0;
            pgcnt=0;
        }
        if (pgcnt!=0)
        {
           try
            {
                cout<<"Enter page count : ";
                cin>>pgcnt;
                if(pgcnt<=0)
                {
                    throw pgcnt;
                }
        
            }
            catch(...)
            {
                    title="    ";
                    price=0.0;
                    pgcnt=0;
            }
            for (int x=0;x<maxrow;x++)
        {
            if(Titlebook[x]=="\0")
            {
                Titlebook[x]=title;
                Pricebook[x]=price;
                Pagecount[x]=pgcnt;
                pgcnt=1;
                break;
            }
        }
        }
        else
        {
            for (int x=0;x<maxrow;x++)
        {
            if(Titlebook[x]=="\0")
            {
                Titlebook[x]=title;
                Pricebook[x]=price;
                Pagecount[x]=pgcnt;
                pgcnt=1;
                break;
            }

        }
        }
            
        
        }
    void DisplayBook()
    {
        system("CLS");
        cout<<"Current Record(s)"<<endl;
        cout<<"======================================"<<endl;
        int counter=0;
        cout<<"No. |      NAME      |    Price    |   Page Count"<<endl<<"------------------------------------\n";
        for(int x=0; x< maxrow;x++)
        {
            if(Titlebook[x]!="\0")
            {
               counter++;
               cout<<" "<<counter<<"         "<<Titlebook[x]<<"          "<<Pricebook[x]<<"           "<<Pagecount[x]<< endl;

            }
        }
        if (counter==0)
        {
            cout<<"No data present"<<endl;

        }
        cout<<"======================================"<<endl;
    }
    void UpdateBook(string search)
    {
        int counter=0;
        for (int x=0;x<maxrow;x++)
        {
            if(Titlebook[x]==search)
            {
                counter++;
                cout<<"Enter new title for book : "<<endl;
                getline(cin,title);
                Titlebook[x]=title;
                cout<<"Enter new price for book : "<<endl;
                cin>>price;
                Pricebook[x]=price;
                cout<<"Enter new page count for book : "<<endl;
                cin>>pgcnt;
                Pagecount[x]=pgcnt;
                }
        }
        if (counter==0)
        {
        cout<<"Book does not exist!";        
        }
    }
    void DeleteBook(string search)

    {
        int counter=0;
        for (int x=0;x<maxrow;x++)
        {
            if (Titlebook[x]==search)
            {
               counter++;
               Titlebook[x]="";
               Pricebook[x]='0';
               Pagecount[x]='0';
               cout<<"Successfully Deleted!";
               break;
            }   
        }
        if (counter==0)
        {
            cout<<"Book does not exist!";
        }

    }
    void Search(string search)
    {
        system("CLS");
        cout<<"Current Record(s)"<<endl;
        cout<<"======================================"<<endl;
        int counter=0;
        for(int x=0;x<maxrow;x++)
        {
            
            if(Titlebook[x]==search)
        {
            counter++;
            cout<<" "<<counter<<"         "<<Titlebook[x]<<"          "<<Pricebook[x]<<"           "<<Pagecount[x]<<endl;
            break;
        }
        }
           if( counter==0)
           {
               cout<<"No record Found!";
               
           }        
       
}
   };
class Tape: public Publications
{
    public:
    float time[maxrow]={};
    float playtime=1;
    void addrecord()
    {
        cin.ignore();
        cout<<"Enter Publication info : ";
        getline(cin,title);
        try
        {
            cout<<"Enter price of publication : ";
            cin>>price;
            if (price<=0)
            {
                throw price;
            }
        }
        catch(...)
        {
            title="    ";
            price=0.0;
            playtime=0;
        }
        if(playtime!=0)
        {
            try
            {
                cout<<"Enter play time : ";
                cin>>playtime;
                if(playtime<=0)
                {
                    throw playtime;
                }
        
            }
            catch(...)
            {
                    title="    ";
                    price=0.0;
                    playtime=0;
            }
            for (int x=0;x<maxrow;x++)
        {
            if(Titlebook[x]=="\0")
            {
                Titlebook[x]=title;
                Pricebook[x]=price;
                time[x]=playtime;
                playtime=1;
                
                break;
            }
        }
            
        
        }
        else
        {
            for (int x=0;x<maxrow;x++)
        {
            if(Titlebook[x]=="\0")
            {
                Titlebook[x]=title;
                Pricebook[x]=price;
                time[x]=playtime;
                playtime=1;
                break;
            }
        }

        }
    }
    void UpdateTape(string search)
    {
        int counter=0;
        for (int x=0;x<maxrow;x++)
        {
            if(Titlebook[x]==search)
            {
                counter++;
                cout<<"Enter new title for Tape : "<<endl;
                getline(cin,title);
                Titlebook[x]=title;
                cout<<"Enter new price for Tape : "<<endl;
                cin>>price;
                Pricebook[x]=price;
                cout<<"Enter new play time for Tape : "<<endl;
                cin>>playtime;
                time[x]=playtime;
                }
        }
        if (counter==0)
        {
        cout<<"Tape does not exist!";        
        }
    }
    void DeleteTape(string search)

    {
        int counter=0;
        for (int x=0;x<maxrow;x++)
        {
            if (Titlebook[x]==search)
            {
               counter++;
               Titlebook[x]="";
               Pricebook[x]='0';
               time[x]='0';
               cout<<"Successfully Deleted!";
               break;
            }   
        }
        if (counter==0)
        {
            cout<<"Book does not exist!";
        }

    }   
    void Search(string search)
    {
        system("CLS");
        cout<<"Current Record(s)"<<endl;
        cout<<"======================================"<<endl;
        int counter=0;
        for(int x=0;x<maxrow;x++)
        {
            
            if(Titlebook[x]==search)
        {
            counter++;
            cout<<" "<<counter<<"         "<<Titlebook[x]<<"          "<<Pricebook[x]<<"          "<<time[x]<<endl;
            break;
        }
        }
           if( counter==0)
           {
               cout<<"No record Found!";
               
           }        
       
}
    void DisplayTape()
    {
        system("CLS");
        cout<<"Current Record(s)"<<endl;
        cout<<"======================================"<<endl;
        int counter=0;
        cout<<"No. |      NAME      |    Price    |   Time"<<endl<<"-------------------------------------------------\n";
        for(int x=0; x< maxrow;x++)
        {
            if(Titlebook[x]!="\0")
            {
               counter++;
               cout<<" "<<counter<<"         "<<Titlebook[x]<<"          "<<Pricebook[x]<<"          "<<time[x]<< endl;

            }
        }
        if (counter==0)
        {
            cout<<"No data present"<<endl;

        }
        cout<<"======================================"<<endl;
    }
    };

int main()
{
    string titles;
    Book b;
    Tape t;
    int usersChoice = {0};
    system("CLS");
   
    do
       {
        cout << "\n********MENU*********" << endl;
        cout << "1. Create data for new Book\n";
        cout << "2. Update data for book\n";
        cout << "3. Display all books\n";
        cout << "4. Delete book \n";
        cout << "5. Search Book\n";
        cout << "6. Create data for new Tape\n";
        cout << "7. Update data for Tape\n";
        cout << "8. Display all Tape\n";
        cout << "9. Delete Tape \n";
        cout << "10. Search Tape\n";
        cout << "-1. Exit\n";
        cout << "Chose a operation to perform ";
        cin >> usersChoice;
        switch (usersChoice)
        {
        case 1:
            b.Addrecord();
            system("CLS");
            break;
        case 2:
            cin.ignore();
            cout<<"Enter book name to be updated"<<endl;
            getline(cin,titles);
            b.UpdateBook(titles);
            break;
        case 3:
            b.DisplayBook();
            break;
        case 4:
            cin.ignore();
            cout<<"Delete by ID"<<endl;
            getline(cin,titles);
            b.DeleteBook(titles);
            cin.ignore();
            system("CLS");
            break;
        case 5:
            cin.ignore();
            cout<<"Enter book name : "<<endl;
            getline(cin,titles);
            b.Search(titles);
            break;
        case 6:
        t.addrecord();
        system("CLS");
        break;
        case 7:
            cin.ignore();
            cout<<"Enter tape name to be updated"<<endl;
            getline(cin,titles);
            t.UpdateTape(titles);
            break;
        case 8:
        t.DisplayTape();
        break;
        case 9:
            cin.ignore();
            cout<<"Delete by ID"<<endl;
            getline(cin,titles);
            t.DeleteTape(titles);
            cin.ignore();
            system("CLS");
            break;
        case 10:
         cin.ignore();
            cout<<"Enter tape name : "<<endl;
            getline(cin,titles);
            t.Search(titles);
            break;
        };
       }while (usersChoice!=-1);
        
    return 0;
}
