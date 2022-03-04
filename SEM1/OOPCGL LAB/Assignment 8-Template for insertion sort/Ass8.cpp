
/*
Write a function template for selection sort that inputs, sorts and outputs an integer array 
and a float array.


class->object.
template->class.
Templates are defined so as to follow DRY principle.   
T can take int,float,char.
Selection sort has time complexity of O(n^2) for best as well as worst case senario.*/
#include<iostream>
#include<stdlib.h>
#define size 100
using namespace std;
bool go=true;
int n;
char c;
template<class T>
void selsort (T A[])
{
    T temp;
    for(int i = 0; i < n-1; i++) //Outer for loop to traverse through the array.
    {
        int min=i;              // Setting first element as  minimum . 
        for (int j = i+1; j <n;j++)//Inner for loop to find element smallest in the array and swapping it 
        {                          // with min 
            if(A[j] < A[min])
            {
                min=j;
            }
        };
        if(min!=i)
        {
            temp=A[i];
            A[i]=A[min];;
            A[min]=temp;
        };
    }
    cout<<"The sorted list is : ";
    int x;
    for (x=0; x < n; x++)// Printing the array in sorted order.
        cout << A[x] << " ";
    cout << endl;

}
int main()
{
int a[size];//defining array as int type
float b[size];//defining array as float type

int ch;//To take input for operation to be executed.
int i;
char ans;
do
    {
		while(go)
		{
			try
			{
				cout<<"\nEnter total no of elements : ";
    			if ((cin>>n))
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
				else
				{throw 1;
				}
			}
			catch(...)
			{
				cout<<"Enter number";
				cin.clear();
				cin.ignore(100000000,'\n');
				
			}
		}
			go=true;
    	cout<<"1)to sort integer elements";
    	cout<<"\n2)to sort float elements\n3).Exit\n";
    	cin>>ch;
    	switch(ch)
    	{
    		case 1 : 
   					 
    				for(i=0;i<n;i++)
    				{
						bool goo=true;
						while (goo)
						{
							try
							{
								cout<<"\nEnter "<<i<<"th element : \n";
							if((cin>>a[i]))
							{
								cin.get(c);
								if(c!='\n')
								{
								throw a[i];
								cin.clear();
								}
								else
								{goo=false;}
							}
							else{
								throw 1;
							}
							}
							catch(...)
							{
								cout<<"Input should be an integer";
								cin.clear();
								cin.ignore(100000000,'\n');
							}
						}
					}
    				selsort<int>(a);
    				
    				break;
    		case 2 :
			for(int i=0;i<n;i++)
			{
							cout<<"\nEnter "<<i<<"th element : \n";
							cin>>b[i];
			}
    				selsort<float>(b);
    				break;
    			
    		case 3: exit(0);
    		default : cout<<"\nIncorrect choice \n";
    	}
    	cout<<"\nWant to continue ? \n";
    	cin>>ans;
	}while(ans=='y');
return 0;
}