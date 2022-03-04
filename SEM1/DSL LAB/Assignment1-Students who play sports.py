"""
In second year ,computer engineering class, group A students play cricket,group B students play badminton, group C students play football.Write a 
Pythhin program using functions to compute the following:
1.The list of students who play both cricket and badminton.
2.The list of students who play either cricket or badminton but not both.
3.The list of students who play only football.
4.The list of students who play cricket and football but not badminton.
"""
cricket = []
football = []
badminton = []
lst3 = []
lst4 = []
lst5 = []
lst6 = []


for i in range(int(input("Enter number of students who play cricket"))): #For loop to take input for list of students who play criket.
    ele = int(input("enter roll number"))

    cricket.append(ele)
    
for i in range(int(input("Enter number of students who play badminton"))):#For loop to take input for list of students who play badminton.
    ele = int(input("enter roll number"))
                                               
    badminton.append(ele)
    
    

for i in range(int(input("Enter number of students who play football"))):#For loop to take input for list of students who play football.
    ele = int(input("enter roll number"))                               
                                                 
    football.append(ele)
    

def common(cricket, badminton):                                         #Function to find students who play both cricket and football.
    for i in cricket:
        if i in badminton:
            lst3.append(i)

    print("The list of students who play both cricket and badminton:", lst3)


def either(cricket, badminton):                     # Function to find the list of students who play either cricket or badminton but not both.
    for i in cricket:
        if i not in badminton:
            lst4.append(i)
    for i in badminton:
        if i not in cricket:
            lst4.append(i)
    print("The list of students who play either cricket or badminton but not both:", lst4)


def footbal(cricket, badminton, football):        # Function to find the list of students who play only football.
    for i in football:
        if i not in cricket:
            if i not in badminton:
                lst5.append(i)

    print("The list of students who play only football:", lst5)


def not_badminton(cricket, badminton, football):    # Function to find the list of students who play cricket and football but not badminton.
    for i in cricket+football:
        if i not in badminton:
            lst6.append(i)
    new = []
    for i in lst6:
        if i not in new:
            new.append(i)
    print("The list of students who play cricket and football but not badminton: ", new)


print("The list of students who play cricket:", cricket)     #Print
print("The list of students who play football", football)    #Print 
print("The list of students who play badminton:", badminton) #Print
common(cricket, badminton)                      #Calling function
either(cricket, badminton)                      #Calling function
footbal(cricket, badminton, football)           #Calling function
not_badminton(cricket, badminton, football)     #Calling function
