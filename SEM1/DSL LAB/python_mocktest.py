"""
In second year ,computer engineering class, group A students play cricket,group B students play badminton, group C students play football.Write a 
Python program using functions to compute the following:
1.The list of students who play both cricket and badminton.
2.The list of students who play either cricket or badminton but not both.
3.The list of students who play only football.
4.The list of students who play cricket and football but not badminton.
5. who play all the sports and who play none.
"""

def lst(list,length):                                                   #Function to take input
    i = 0
    while (i < length):
        while (True):
            try:                                                        #Exception Handling
                x = int(input("Enter Roll Number present : "))          #Take input of roll number
                break
            except ValueError:                                          #If entered value is not a roll number throw an error
                print("Value can only be a number")   
        if (x in list):                                                 #To check whether the Roll Number is repeated
            print("Roll Number already present.")           
        else:                                                           #Append roll number to list
            list.append(x)
            i += 1
    return list  

def common(a,b):                                                        #function to find common roll numbers who play criket and football
    print("\n\n")
    print("List of students who play cricket:",a)                 #print list of students who play cricket.
    print("List of students who play badminton:",b)             #print list of students who play badminton
    
    lst1=[]                                                             #Initializing an empty list.
    for i in a:                                                   #For loop to traverse through the cricket list
        if i in b:                                              #If condition to check of roll number is present in badminton
            lst1.append(i)                                              #Append if roll number present.
    print("\n\n")
    print("List of students who play both cricket and badminton",lst1)  #Print list of students who play both cricket and badminton
 
def either(a,b):                                                        #Function to print students who play either cricket or badminton but not both.
    print("\n\n")
    print("List of students who play cricket:",a)                 #print list of students who play cricket.
    print("List of students who play badminton:",b)             #print list of students who play badminton.
    lst2=[]                                                             #Initializing an empty list.
    for i in a:                                                   #For loop to traverse through the cricket list
        if i not in b:                                          #If condition to check of roll number is not present in badminton
            lst2.append(i)                                              #Append if roll number not present.
    for i in b:                                                 #For loop to traverse through the badminton list
        if i not in a:                                            #If condition to check of roll number is not present in cricket
            lst2.append(i)                                              #Append if roll number not present.
    print("\n\n")
    print("List of students who play either",lst2)                      #Print list of students who play either cricket or badminton but not both.
def only(a,b,c):                                                        #Function to print the list of students who play only football.
    print("List of students who play cricket:",a)                 #print list of students who play cricket.
    print("List of students who play badminton:",c)             #print list of students who play badminton
    print("List of students who play football:",football)               #print list of students who play football.
    lst3=[]                                                             #Initializing an empty list.
    for i in football:                                                  #For loop to traverse through the football list.      
        if i not in cricket:                                            #If condition to check of roll number is not present in cricket
            if i not in badminton:                                      #If condition to check of roll number is not present in badminton
                lst3.append(i)                                          #Append roll number.
    print("\n\n")
    print("List of students who play football:",lst3)                   #Print the list of students who play only football.
def crik_foot(a,b,c):                                                   #Function to print the list of students who play cricket and football but not badminton.
    print("List of students who play cricket:",a)                 #print list of students who play cricket.
    print("List of students who play badminton:",c)             #print list of students who play badminton
    print("List of students who play football:",b)               #print list of students who play football.
    lst4=[]                                                             #Initializing an empty list.
    for i in a+b:                                          
        if i not in c:
            lst4.append(i)
    lst5=[]                                                             #Initializing an empty list.
    for i in lst4:                                                      #Loop to remove repeating elements from the list.
        if i not in lst5:
            lst5.append(i)
    print("\n\n")
    print("list of students who play criket and football but not badminton",lst5) # Print the list of students who play cricket and football but not badminton.
cricket=[]                                                              #Initializing an empty list.                                   
football=[]                                                             #Initializing an empty list.
badminton=[]                                                            #Initializing an empty list.
allstds=[]
n=int(input("Enter number of students who play cricket: "))      
arr1=lst(cricket,n)  
print("The list of roll number  who play cricket is: ", arr1)
b=int(input("Enter number of students who play football: ")) 
arr2=lst(football,b)
print("The list of roll number who play football is: ", arr2)
c=int(input("Enter number of students who play badminton: ")) 
arr3=lst(badminton,c)
print("The list of roll number who play badminton is: ", arr3)
p=int(input("Enter number of students present : ")) 
arr4=lst(allstds,p)
print("The list of roll number who play badminton is: ", arr4)



def all_sprts(a,b,c,d):
    print("List of students who play cricket:",a)                 #print list of students who play cricket.
    print("List of students who play badminton:",c)             #print list of students who play badminton
    print("List of students who play football:",b) 
    x=set(a)
    y=set(b)
    z=set(c)
    f=set(a)&set(b)&set(c)
    print("The number of students who play only one sport",list(f))

def nospts(a,b,c,d):
    print("List of students who play cricket:",a)                 #print list of students who play cricket.
    print("List of students who play badminton:",c)             #print list of students who play badminton
    print("List of students who play football:",b) 
    x=set(a)
    y=set(b)
    z=set(c)
    f=list(set(list(set(a)&set(b)&set(c))+d))


    print("The total number of students present in the class",f)
    lst7=[]
    for i in f:
        if i not in a+b+c:
            lst7.append(i)
    print("The list of roll number is : ",lst7 )



while True:
    print("*"*20+"Menu"+"*"*20)
    print("""1. To find the common students in cricket and badminton.
2. To find students who play either cricket and badminton.
3. To find  students who play only football.
4. To find students who play cricket and football but not badminton.
5.All sports.
6.no sports.
-1. Exit.
    """ )
    
    choice=int(input("Enter number for the operation to be performed:"))
    if choice==1:
        print("*"*20)
        common(cricket,badminton)
        print("*"*20)
    elif choice==2:
        print("*"*20)
        either(cricket,badminton)
        print("*"*20)
    elif choice==3:
        print("*"*20)
        only(cricket,football,badminton)
        print("*"*20)

    elif choice==4:
        print("*"*20)
        crik_foot(cricket,football,badminton)
        print("*"*20)
    elif choice==5:
        print("*"*20)
        all_sprts(cricket,football,badminton)
        print("*"*20)
    elif choice==6:
        print("*"*20)
        nospts(cricket,football,badminton,allstds)
        print("*"*20)
    elif choice==-1:
        print("Thank you")
        break
    else:
        print("Please enter a valid choice")