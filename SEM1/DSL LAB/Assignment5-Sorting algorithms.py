"""Write a python program to take input of percentage of students. Sort the percentages using
1. Insertion sort
2. Shell sort
"""

class sort:                        #Defining a class Sort which has all the sorting functions. 
    def insertion_sort(self, l):   #Function for insertion sort
        for i in range(1, len(l)): #Loop to traverse from second element to last
            curr=l[i]              #Creating a variable to store the original value at ith location
            j=i-1                  #creating another variable with value i-1
            while(j>=0 and l[j]>curr):
                l[j+1]=l[j]        #If element before is greater than swap it with the next position
                j=j-1              #Decrement the value of variable pos by 1
            l[j+1]=curr            #Change the value at location before to the original value
            print("The list after iteration {} is\n".format(i), l)
        return l                   #Return list

    def shell_sort(self, l):       #Function for shell sort
        p = 0                      #Set p=0 Counter value
        gap=len(l)//2              #Set gap equal to floor division of length of list
        while(gap>0):           
            for i in range(gap, len(l)):
                for j in range(i-gap, -1, -gap):
                    if l[j+gap]>l[j]:
                        break
                    else:
                        l[j+gap],l[j]=l[j],l[j+gap]
            gap=gap//2
            p=p+1                  #increment counter
            print("The list after pass", p, "is\n", l) #Print the updated list after each pass
        return l

obj=sort()                         #Creating an objext of class sort
while True:                        #Using while loop to take input of students
    a = int(input("Enter the number of students:"))
    if a>5:                        #If condition to check whether the number of students entered are greater than 5
        break
    else:
        print("Students should be greater than 5")

l=[]                               #Initializing an empty list
l1=[]                              #Initializing an empty list
for i in range(a): 
    while True:                    #While loop for exception handling
        try:                       #Loop to check condition for percentage
            x=float(input("Enter percentage: "))
            if x<=100 and x>=0:
                l.append(x)
                l1.append(x)
                break
            else:
                print("Not a valid percentage\n")    
        except ValueError:          #Try and except to check whether input is number
            print("Enter a number\n")
        continue


    
while True:                        #Menu driven program 
    print("**Main Menu**")
    print("1.Insertion sort")
    print("2.Shell sort")
    print("-1.Exit")
    choice = int(input("Enter the sorting method that you want to perform to find the top 5 scores:"))
    if choice == 1:
        a=obj.insertion_sort(l)
        li=a[::-1]
        print("The scores in sorted order are:", a)
        print("The top 5 scores are:")
        for i in range(5):
            print("{})".format(i+1), li[i], end='\n')
    elif choice == 2:
        a=obj.shell_sort(l1)
        li=a[::-1]
        print("The scores in sorted order are:", a)
        print("The top 5 scores are:")
        for i in range(5):
            print("{})".format(i+1), li[i], end='\n')
    elif choice == -1:
        print("Thank You!!!")
        break
    else:
        print("Enter Valid Choice!!")