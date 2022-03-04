"""Write a python programme to store the roll numbers of all the students in an array who attended tthe training programme in a random order.
a)Write function for searching whether particular student attended the training programme or not using
linear search(Done)
sentinal search(Done)
b)Write function for searching whether particular student attended the training programme or not using
binary search
fibonnaci search
"""
def createarr(list, length):                                            #Function to create a list of roll numbers and check if roll number is already present
    i = 0
    while (i < length):
        while (True):
            try:                                                        # Exception Handling
                x = int(input("Enter Roll Number present : "))
                break
            except ValueError:
                print("Value can only be a number")
        if (x in list):                                                 # To check whether the Roll Number is repeated
            print("Roll Number already present.")
        else:
            list.append(x)
            i += 1
    return list

def linearSearch(arr1, n):                                           # Linear search function
    y = int(input("Enter roll number to be found: "))
    for i in range(0, n):                                               # Going through array sequencially
        if (arr1[i] == y):
            return i
    return -1

def sentinelSearch(arr1, n):                                          # Sentinel search function
    y = int(input("Enter roll number to be found: "))
    last = arr1[n-1]
    arr1[n-1] = y                                                        # Put the element to be found at last position 
    i = 0
    while (arr1[i] != y):
        i += 1

    arr1[n - 1] = last                                                    # Put the last element back

    if ((i < n - 1) or (arr1[n - 1] == y)):                               
        print(y, " is present at index ", i)          
    else:
        print("Roll number not present")

def binsearch(arr1, bottom, top,y):                                       # Binary search function
    
    arr1.sort()
    if top >= bottom:
        mid = (top+bottom)//2
        if arr1[mid] == y:
            return mid
        elif arr1[mid] > y:
            return binsearch(arr1, bottom, mid-1,y)
        else:
            return binsearch(arr1, mid+1, top, y)
    else:
        return -1

def FibonacciGenerator(n):
    if n < 1:
        return 0
    elif n == 1:
        return 1
    else:
        return FibonacciGenerator(n - 1) + FibonacciGenerator(n - 2)

# return the index at which x exists inside arr
# return -1 otherwise

def FibonacciSearch(arr1,y):
    m = 0 
    while FibonacciGenerator(m) < len(arr1): # 
        m = m + 1 

    offset = -1
    while (FibonacciGenerator(m) > 1):

        i = min( offset + FibonacciGenerator(m - 2) , len(arr1) - 1)


        if (y > arr1[i]):

            m = m - 1
            offset = i

        elif (y < arr1[i]):

            m = m - 2

        else:

            return i
    if(FibonacciGenerator(m - 1) and arr1[offset + 1] == y):
        return offset + 1

    # return -1 if the element doesn't exist in the array
    return -1

# Main block
print("Input of list")
A = []
n = int(input("enter number of students: "))
print('\n')
arr1 = createarr(A, n)
print("The list of roll number is: ", arr1)


while(True):
    print("*"*20+"Menu"+"*"*20)
    print(""" 1. Linear Search
 2. Sentinel Linear seach
 3. Binary search
 4. Fibonnaci search
-1. EXIT """)
    choice = int(input("Enter number for the operation to be performed: "))
    if choice == 1:
        lsearchresult = linearSearch(arr1, n)
        if(lsearchresult == -1):
            print("Roll number not present")
        else:
            print("Roll number present at: ", lsearchresult)
            print('\n')
    elif choice == 2:
        sentinelSearch(arr1, n)
        print("\n")
        print("*"*40+"\n")

    elif choice == 3:
        y = int(input("Enter roll number to be found: "))
        ans = binsearch(arr1, 0, len(arr1)-1,y)
        print("Sorted list", sorted(arr1))
        print("*"*40+"\n")
        if ans != -1:
            print("Roll number present at index ", str(ans))
        else:
            print("Roll number not present")

    elif choice == 4:
        y = int(input("Enter roll number to be found: "))
        u = FibonacciSearch(arr1,y)
        print("Sorted list", sorted(arr1))
        print("*"*40+"\n")
        if u != -1:
            print("Roll number present at index ", str(u))
        else:
            print("Roll number not present")

    elif choice == -1:

        break
    else:
        print("Please enter valid choice")
