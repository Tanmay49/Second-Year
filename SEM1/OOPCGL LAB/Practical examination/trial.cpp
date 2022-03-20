/*
 * Imagine a publishing company which does marketing for book and audio cassette versions.
 * Create a class publication that stores the title (a string) and price (type float) of publications.
 *  From this class derive two classes: book which adds a page count (type int) and tape which adds a
 *  playing time in minutes (type float).

Write a program that instantiates the book and tape class, allows user to enter data and displays
the data members. If an exception is caught, replace all the data member values with zero values.
Do exception handling for all inputs
*/
#include<iostream>
#include<stdlib.h>
const int maxrow=10;
using namespace std;

class Publication //Class Publication defined as Super class.
{
public:
	string title; //defining title variable to take input of title.
	string titles[maxrow]={}; //defining title array to store all the titles.
	float price;//defining price variable to store prices.
	float prices[maxrow]={};//
};
class Book:public Publication // Defining Book class. Base class or derived class.
{
public:
	int pgcnt=1;//defining page count variable to store page count.
	int pgcnts[maxrow]={};//defining page count array to store all the page count.
	void Addrecord()  //add record function to take input from user.
	//ADD FUNCTION WORKING PROPERLY!!
	//EXCEPTION HANDLING WORKING!!
	{
		char c;
		bool go=true;
		cin.ignore();//so that getline function can work properly.
		try //try catch block for exception handling
		{

			cout<<"Enter Publication information : ";
			getline(cin,title);//taking input using getline function.
			if(title.length()==0)//if length is 0 set all values to 0.
			{
				throw 0;
			}
			else
			{
				for (int i=0;i<title.length();i++)
				{
					char temp=title[i];//if only digit set all parameters to 0;
					if(isdigit(temp))
					{
						throw 0;
						break;
					}
				}
			}
		}
		catch(...)  //catch block where all parameters are set to 0;
		{
			title="   ";
			price=0.0;
			pgcnt=0;
			cin.clear();
		   cin.ignore(10000000,'\n');
		}
		if(title!="   ")  //Take further input only if title is not blank.
		{
		while (go)  //Exception handling for price
		{
			try
			{
				cout<<"Enter price ";
				if(cin>>price)
				{
					if(price<0)  //if price is less than 0 set parameters to 0.
					{
						throw 0;
						cin.clear();
					}
					else
					{
						cin.get(c);  //
						if(c!='\n')
						{
							throw 0;
							cin.clear();
						}
						else
						{
							go=false;
						}

					}
				}
				else
				{
					throw 1;
				}
			}
			catch(...)
			{
				title="   ";
				price=0.0;
				pgcnt=0;
				cin.clear();
				cin.ignore(10000000,'\n');
				go=false;  // setting bool to false so it exits out of the loop.
			}
		}
		go=true;
		//SIMILAR EXCEPTION HANDLING FOR PAGE COUNT AS PRICE.
		if(pgcnt!=0)
		{
			while (go)
					{
						try
						{
							cout<<"Enter page count ";
							if(cin>>pgcnt)
							{
								if(pgcnt<0)
								{
									throw 0;
									cin.clear();
								}
								else
								{
									cin.get(c);
									if(c!='\n')
									{
										throw 0;
										cin.clear();
									}
									else
									{
										go=false;
									}

								}
							}
							else
							{
								throw 1;
							}
						}
						catch(...)
						{
							title="   ";
							price=0.0;
							pgcnt=0;
							cin.clear();
							cin.ignore(10000000,'\n');
							go=false;
						}
						for (int x=0;x<maxrow;x++)
								{
									if(titles[x]=="\0")
									{
									titles[x]=title;
									prices[x]=price;
									pgcnts[x]=pgcnt;
									pgcnt=1;
									break;
									}
								}

					}
		}
		else
		{
		for (int x=0;x<maxrow;x++)
		{
			if(titles[x]=="\0")
			{
			titles[x]=title;
			prices[x]=price;
			pgcnts[x]=pgcnt;
			pgcnt=1;
			break;
			}
		}
		}
		}
		else
				{
				for (int x=0;x<maxrow;x++)
				{
					if(titles[x]=="\0")
					{
					titles[x]=title;
					prices[x]=price;
					pgcnts[x]=pgcnt;
					pgcnt=1;
					break;
					}
				}
				}
	}
	void display()//Function to display the data.
	//DISPLAY DATA SUCCESSFULLY!!
	//DATA PRESENTATION IN A GOOD WAY REMAINING.
	{
		system("CLS");
		cout<<"Current Record(s)"<<endl;
		int count={0};
		cout<<"======================="<<endl;
		cout<<"No.  |  NAME  |  PRICE OF THE PUBLICATION  | PAGE COUNT "<<endl;
		for(int i=0;i<maxrow;i++)
		{
			if(titles[i]!="\0")
			{
				count++;
				cout<<count<<"  "<<titles[i]<<"  "<<prices[i]<<"  "<<pgcnts[i]<<endl;
			}
		}
		if(count==0)
		{
			cout<<"Database Empty.No Book present."<<endl;
		}
		cout<<"======================="<<endl;
	}
	void update(string a)// UPDATE FUNCTION TO UPDATE DATA.
	{

		//UPDATE FUNCTION WORKING.EXCEPTION HANDLING ALSO WORKING. CHECKED FOR CHARACTER,NEGATIVE NUMBER AS INPUT.
		char c;
		bool go=true;
		int count={0};//Setting up a counter so that if no book is found throw error message.
		for(int i=0;i<maxrow;i++)
			{
			if(titles[i]==a)
				{
				count ++;
				try
								{
									cin.ignore();//so that getline function can work properly.
									cout<<"Enter Publication information : ";
									getline(cin,title);
									if(title.length()==0)
									{
										throw 0;
									}
									else
									{
										for (int i=0;i<title.length();i++)
										{
											char temp=title[i];
											if(isdigit(temp))
											{
												throw 0;
												break;
											}
										}
									}
								}
								catch(...)
								{
									title="   ";
									price=0.0;
									pgcnt=0;
									cin.clear();
								   cin.ignore(10000000,'\n');
								}
								if(title!="   ")
								{
				while (go)
						{
							try
							{
								cout<<"Enter new  price ";
								if(cin>>price)
								{
									if(price<0)
									{
										throw 0;
										cin.clear();
									}
									else
									{
										cin.get(c);
										if(c!='\n')
										{
											throw 0;
											cin.clear();
										}
										else
										{
											go=false;
										}

									}
								}
								else
								{
									throw 1;
								}
							}
							catch(...)
							{
								title="   ";
								price=0.0;
								pgcnt=0;
								cin.clear();
								cin.ignore(10000000,'\n');
								go=false;
							}
						}
						go=true;
						if(pgcnt!=0)
						{
							while (go)
									{
										try
										{
											cout<<"Enter new page count ";
											if(cin>>pgcnt)
											{
												if(pgcnt<0)
												{
													throw 0;
													cin.clear();
												}
												else
												{
													cin.get(c);
													if(c!='\n')
													{
														throw 0;
														cin.clear();
													}
													else
													{
														go=false;
													}

												}
											}
											else
											{
												throw 1;
											}
										}
										catch(...)
										{
											title="   ";
											price=0.0;
											pgcnt=0;
											cin.clear();
											cin.ignore(10000000,'\n');
											go=false;
										}
													titles[i]=title;
													prices[i]=price;
													pgcnts[i]=pgcnt;
													pgcnt=1;
													break;
									}
						}
						else
						{
							titles[i]=title;
							prices[i]=price;
							pgcnts[i]=pgcnt;
							pgcnt=1;
							break;
							}
								}
								else
														{
															titles[i]=title;
															prices[i]=price;
															pgcnts[i]=pgcnt;
															pgcnt=1;
															break;
															}

				}
			}
		if(count==0)
		{
			cout<<"\n\nNo book exists.\n";
		}
	}
	void deleteb (string a)//FUNCTION FOR DELETE
	{
		//Function working properly.
		//Data deleted successfully.
		int count={0};
		for(int i=0;i<maxrow;i++)
		{
			if(titles[i]==a)
			{
				count++;
				titles[i]="";
				prices[i]=0.0;
				pgcnts[i]=0;
				cout<<"Data of book successfully deleted\n\n";
				break;


			}
		}
		if(count==0)
		{
			cout<<"No book found!!.Cannot Delete!"<<endl;
		}
	}
	void searc(string a)//Function for searching of data in database.
	{
		//FUNCTION WORKING PROPERLY!!
		int count={0};
		cout<<"======================="<<endl;
		cout<<"No.  |  NAME  |  PRICE OF THE PUBLICATION  | PAGE COUNT "<<endl;
		for(int i=0;i<maxrow;i++)
		{
			if(titles[i]==a)
			{
				count++;
				cout<<count<<"  "<<titles[i]<<"  "<<prices[i]<<"  "<<pgcnts[i]<<endl;
				break;
			}
		}
		if(count==0)
		{
			cout<<"\n\n\n Book not found\n";
		}

	}

};
class Tape:public Publication //Defining Tape class.Base class or derived class.
{
public:
	float pltime=1;//defining page count variable to store page count.
	float pltimes[maxrow]={};//defining page count array to store all the page count.
	void Addrecordt()  //add record function to take input from user.
	//ADD FUNCTION WORKING PROPERLY!!
	//EXCEPTION HANDLING WORKING!!
	{
		char c;
		bool go=true;
		try
				{
					cin.ignore();//so that getline function can work properly.
					cout<<"Enter Publication information : ";
					getline(cin,title);
					if(title.length()==0)
					{
						throw 0;
					}
					else
					{
						for (int i=0;i<title.length();i++)
						{
							char temp=title[i];
							if(isdigit(temp))
							{
								throw 0;
								break;
							}
						}
					}
				}
				catch(...)
				{
					title="   ";
					price=0.0;
					pltime=0;
					cin.clear();
				   cin.ignore(10000000,'\n');
				}
				if(title!="   ")
				{
		while (go)
		{
			try
			{
				cout<<"Enter price ";
				if(cin>>price)
				{
					if(price<0)
					{
						throw 0;
						cin.clear();
					}
					else
					{
						cin.get(c);
						if(c!='\n')
						{
							throw 0;
							cin.clear();
						}
						else
						{
							go=false;
						}

					}
				}
				else
				{
					throw 1;
				}
			}
			catch(...)
			{
				title="   ";
				price=0.0;
				pltime=0;
				cin.clear();
				cin.ignore(10000000,'\n');
				go=false;
			}
		}
		go=true;
		if(pltime!=0)
		{
			while (go)
					{
						try
						{
							cout<<"Enter play time ";
							if(cin>>pltime)
							{
								if(pltime<0)
								{
									throw 0;
									cin.clear();
								}
								else
								{
									cin.get(c);
									if(c!='\n')
									{
										throw 0;
										cin.clear();
									}
									else
									{
										go=false;
									}

								}
							}
							else
							{
								throw 1;
							}
						}
						catch(...)
						{
							title="   ";
							price=0.0;
							pltime=0;
							cin.clear();
							cin.ignore(10000000,'\n');
							go=false;
						}
						for (int x=0;x<maxrow;x++)
								{
									if(titles[x]=="\0")
									{
									titles[x]=title;
									prices[x]=price;
									pltimes[x]=pltime;
									pltime=1;
									break;
									}
								}

					}
		}
		else
		{
		for (int x=0;x<maxrow;x++)
		{
			if(titles[x]=="\0")
			{
			titles[x]=title;
			prices[x]=price;
			pltimes[x]=pltime;
			pltime=1;
			break;
			}
		}
		}
				}
				else
						{
						for (int x=0;x<maxrow;x++)
						{
							if(titles[x]=="\0")
							{
							titles[x]=title;
							prices[x]=price;
							pltimes[x]=pltime;
							pltime=1;
							break;
							}
						}
						}

	}
	void displayt()//Function to display the data.
	//DISPLAY DATA SUCCESSFULLY!!
	//DATA PRESENTATION IN A GOOD WAY REMAINING.
	{
		system("CLS");
		cout<<"Current Record(s)"<<endl;
		int count={0};
		cout<<"======================="<<endl;
		cout<<"No.  |  NAME  |  PRICE OF THE PUBLICATION  | PLAY TIME "<<endl;
		for(int i=0;i<maxrow;i++)
		{
			if(titles[i]!="\0")
			{
				count++;
				cout<<count<<"  "<<titles[i]<<"  "<<prices[i]<<"  "<<pltimes[i]<<endl;
			}
		}
		if(count==0)
		{
			cout<<"Database Empty.No TAPE present."<<endl;
		}
		cout<<"======================="<<endl;
	}
	void updatet(string a)// UPDATE FUNCTION TO UPDATE DATA.
	{

		//UPDATE FUNCTION WORKING.EXCEPTION HANDLING ALSO WORKING. CHECKED FOR CHARACTER,NEGATIVE NUMBER AS INPUT.
		char c;
		bool go=true;
		int count={0};//Setting up a counter so that if no book is found throw error message.
		for(int i=0;i<maxrow;i++)
			{
			if(titles[i]==a)
				{
				count ++;
				try
								{
									cin.ignore();//so that getline function can work properly.
									cout<<"Enter Publication information : ";
									getline(cin,title);
									if(title.length()==0)
									{
										throw 0;
									}
									else
									{
										for (int i=0;i<title.length();i++)
										{
											char temp=title[i];
											if(isdigit(temp))
											{
												throw 0;
												break;
											}
										}
									}
								}
								catch(...)
								{
									title="   ";
									price=0.0;
									pltime=0;
									cin.clear();
								   cin.ignore(10000000,'\n');
								}
								if(title!="   ")
								{
				while (go)
						{
							try
							{
								cout<<"Enter new  price ";
								if(cin>>price)
								{
									if(price<0)
									{
										throw 0;
										cin.clear();
									}
									else
									{
										cin.get(c);
										if(c!='\n')
										{
											throw 0;
											cin.clear();
										}
										else
										{
											go=false;
										}

									}
								}
								else
								{
									throw 1;
								}
							}
							catch(...)
							{
								title="   ";
								price=0.0;
								pltime=0;
								cin.clear();
								cin.ignore(10000000,'\n');
								go=false;
							}
						}
						go=true;
						if(pltime!=0)
						{
							while (go)
									{
										try
										{
											cout<<"Enter new play time ";
											if(cin>>pltime)
											{
												if(pltime<0)
												{
													throw 0;
													cin.clear();
												}
												else
												{
													cin.get(c);
													if(c!='\n')
													{
														throw 0;
														cin.clear();
													}
													else
													{
														go=false;
													}

												}
											}
											else
											{
												throw 1;
											}
										}
										catch(...)
										{
											title="   ";
											price=0.0;
											pltime=0;
											cin.clear();
											cin.ignore(10000000,'\n');
											go=false;
										}
													titles[i]=title;
													prices[i]=price;
													pltimes[i]=pltime;
													pltime=1;
													break;
									}
						}
						else
						{
							titles[i]=title;
							prices[i]=price;
							pltimes[i]=pltime;
							pltime=1;
							break;
							}
								}

								else
														{
															titles[i]=title;
															prices[i]=price;
															pltimes[i]=pltime;
															pltime=1;
															break;
															}
				}
			}
		if(count==0)
		{
			cout<<"\n\nNo book exists.\n";
		}
	}
	void deletebt (string a)//FUNCTION FOR DELETE
	{
		//Function working properly.
		//Data deleted successfully.
		int count={0};
		for(int i=0;i<maxrow;i++)
		{
			if(titles[i]==a)
			{
				count++;
				titles[i]="";
				prices[i]=0.0;
				pltimes[i]=0;
				cout<<"Data of book successfully deleted\n\n";
				break;


			}
		}
		if(count==0)
		{
			cout<<"No book found!!.Cannot Delete!"<<endl;
		}
	}
	void searct(string a)//Function for searching of data in database.
	{
		//FUNCTION WORKING PROPERLY!!
		int count={0};
		cout<<"======================="<<endl;
		cout<<"No.  |  NAME  |  PRICE OF THE PUBLICATION  | PLAY TIME "<<endl;
		for(int i=0;i<maxrow;i++)
		{
			if(titles[i]==a)
			{
				count++;
				cout<<count<<"  "<<titles[i]<<"  "<<prices[i]<<"  "<<pltimes[i]<<endl;
				break;
			}
		}
		if(count==0)
		{
			cout<<"\n\n\n Tape not found\n";
		}

	}
};

int main()
{
	int ch={0};//To take input from user for operation to be performed.
	string a;//String input from user for searching.
	Book b;//b object created for Book class.
	Tape t;//t object created for Book class.
	system("CLS");//Clear the screen.
	do// Main menu code.
	{
		cout<<"**********MENU***********"<<endl;
		cout<<"1.Create a book\n";
		cout<<"2.Display all the books\n";
		cout<<"3.Update Book data\n";
		cout<<"4.Delete Book data\n";
		cout<<"5.Search Book data\n";
		cout<<"6.Create Tape data\n";
		cout<<"7.Display all the tapes\n";
		cout<<"8.Update Tape data\n";
		cout<<"9.Delete Tape data\n";
		cout<<"10.Search Tape data\n";
		cout<<"11.Exit\n\n\n";
		cout<<"Enter operation to be performed\n";
		cin>>ch;
		switch(ch)
		{
		case 1:
			b.Addrecord();
			system("CLS");
			break;

		case 2:
			b.display();
			break;
		case 3:
			system("CLS");
			cout<<"Please enter book name for which you want to update data : ";
			cin>>a;
			b.update(a);
			break;
		case 4:
			system("CLS");
			cout<<"Please enter book name for which you want to delete data : ";
			cin>>a;
			b.deleteb(a);
			break;
		case 5:
			system("CLS");
			cout<<"Please enter book name for which you want to search data";
			cin>>a;
			b.searc(a);
			break;
		case 6:
			t.Addrecordt();
			system("CLS");
			break;

		case 7:
	    	t.displayt();
			break;
		case 8:
			system("CLS");
			cout<<"Please enter book name for which you want to update data : ";
			cin>>a;
			t.updatet(a);
			break;
		case 9:
			system("CLS");
			cout<<"Please enter book name for which you want to delete data : ";
			cin>>a;
			t.deletebt(a);
			break;
		case 10:
		    system("CLS");
			cout<<"Please enter book name for which you want to search data";
			cin>>a;
			t.searct(a);
			break;
		}

	}while(ch!=11);
	cout<<"Thank You.";

	return 0;
}
