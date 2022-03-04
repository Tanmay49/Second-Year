"""Write a python programme to store the roll numbers of all the students in an array who attended tthe training programme in a random order.
a)Write function for searching whether particular student attended the training programme or not using
linear search(Done)
sentinal search(Done)
b)Write function for searching whether particular student attended the training programme or not using
binary search
fibonnaci search
"""


class Searching():
    def __init__(self):
        self.array=[]
        self.array_sorted=[]
    def create(self):
        n=int(input("Enter number of students present"))
        i=1
        while i<=n:
            try:
                x=int(input("Enter %2d Roll number "%(i)))
                if x not in self.array:
                    self.array.append(x)
                    self.array_sorted.append(x)
                    i+=1
                else:
                    print("Roll number already present")
            except ValueError:
                print("Enter integer value only! ")

        for i in range(1,n):
            curr=self.array_sorted[i]
            j=i-1
            while j>=0 and self.array_sorted[j]>curr:
                self.array_sorted[j+1]=self.array_sorted[j]
                j=j-1
            self.array_sorted[j+1]=curr

    def Linear_search(self):
        """ Best case complexity is o(1) worst case is O(n) avg O(n/2)"""
        search = int(input("Enter element to be searched"))
        for i in range(0,len(self.array)):
            if self.array[i]==search:
                return i
        return -1

    def Sentinel_search(self):
        #Time complexity of O(n)
        search = int(input("Enter element to be searched"))
        last=self.array[len(self.array)-1]
        self.array[len(self.array)-1]=search
        i=0
        while self.array[i]!=search:
            i+=1
        self.array[len(self.array) - 1] = last
        if ((i < len(self.array) - 1) or (self.array[len(self.array) - 1] == search)):
             return  i
        else:
            return  -1
    def Binary_search(self,low,high,search):
        """Time complexity is O(logn)"""
        if high>=low:
            mid=(high+low)//2
            if self.array_sorted[mid]==search:
                return mid
            elif self.array_sorted[mid]>search:
               return s1.Binary_search(low,mid-1,search)
            else:
              return  s1.Binary_search(mid+1,high, search)
        else:
            return -1

    def Fib_search(self,search):
        fib2=0
        fib1=1
        fibadd=fib1+fib2

        while(fibadd<len(self.array_sorted)):
            fib2=fib1
            fib1=fibadd
            fibadd=fib1+fib2

        offset=-1

        while(fibadd>1):
            if fib2+offset>len(self.array_sorted)-1:
                i=len(self.array_sorted)-1
            else:
                i=fib2+offset

            if(self.array_sorted[i]<search):
                fibadd=fib1
                fib1=fib2
                fib2=fibadd-fib1
                offset=i
            elif self.array_sorted[i]>search:
                fibadd=fib2
                fib1=fib1-fib2
                fib2=fibadd-fib1
            else:
                return i

        if fib1 and self.array_sorted[len(self.array_sorted)-1]==search:
            return len(self.array_sorted)-1
        return  -1




s1=Searching()
s1.create()
go =True
while go:
    print("*******Menu******")
    print("1.Linear search")
    print("2.Sentinel Search")
    print("3.Binary search")
    print("4.Fibonacci Search")
    ch=int(input("Enter choice"))
    if ch==1:
        a=s1.Linear_search()
        print(s1.array)
        if a==-1:
            print("Element not found")
        else:
            print("Element found at : ",a)
    if ch == 2:

        a=s1.Sentinel_search()
        if a==-1:
            print("Element not found")
        else:
            print("Element found at",a)
    if ch == 3:
        print(s1.array)
        print(s1.array_sorted)
        search=int(input("Enter element to be searched"))
        a=s1.Binary_search(0,len(s1.array_sorted)-1,search)
        if a == -1:
            print("Element not found")
        else:
            print("Element found at",a)
    if ch == 4:
        print(s1.array)
        print(s1.array_sorted)
        search = int(input("Enter element to be searched"))
        a=s1.Fib_search(search)
        if a == -1:
            print("Element not found")
        else:
            print("Element found at",a)
    if ch==5:
        go=False