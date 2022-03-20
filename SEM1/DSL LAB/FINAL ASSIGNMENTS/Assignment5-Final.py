"""Write a python program to take input of percentage of students. Sort the percentages using
1. Insertion sort
2. Shell sort
"""


class Sorting:
    def __init__(self):
        self.array=[]
        self.array_copy=[]

    def create(self):
        i=1
        go=True
        while go:
            n=int(input("Enter number of students"))
            if n<5:
                print("Students cannot be less than 5")
            else:
                go=False
        while i<=n:
            try:
                x=int(input("Enter element"))
                if 0<=x<=100:
                    self.array.append(x)
                    self.array_copy.append(x)
                    i+=1
                else:
                    print("Not a valid percentage")
            except ValueError:
                print("Enter integers only!")

    def Insertion_sort(self):
        for i in range(1, len(self.array)):  # Loop to traverse from second element to last
            curr = self.array[i]  # Creating a variable to store the original value at ith location
            j = i - 1  # creating another variable with value i-1
            while (j >= 0 and self.array[j] > curr):
                self.array[j + 1] = self.array[j]  # If element before is greater than swap it with the next position
                j = j - 1  # Decrement the value of variable pos by 1
            self.array[j + 1] = curr  # Change the value at location before to the original value
            print("The list after iteration {} is\n".format(i), self.array)
    def Shell_Sort(self):
        p = 0  # Set p=0 Counter value
        gap = len(self.array) // 2  # Set gap equal to floor division of length of list
        while (gap > 0):
            for i in range(gap, len(self.array)):
                for j in range(i - gap, -1, -gap):
                    if self.array[j + gap] > self.array[j]:
                        break
                    else:
                        self.array[j + gap], self.array[j] = self.array[j], self.array[j + gap]
            gap = gap // 2
            p = p + 1  # increment counter
            print("The list after pass", p, "is\n", self.array)


s1=Sorting()
s1.create()
go=True
while go:
    print("*****MENU******")
    print("1.Insertion Sort")
    print("2.Shell Sort")
    print("3.Exit")
    ch=int(input("Enter operation to be performed"))

    if ch==1:
        print(s1.array)
        s1.Insertion_sort()
        print("The sorted list is",s1.array)
        s1.array=s1.array_copy[:]
        print("Original list",s1.array)
    if ch==2:
        print(s1.array)
        s1.Shell_Sort()
        print("The sorted list is",s1.array)
        s1.array=s1.array_copy[:]
        print("Original list",s1.array)
    if ch==3:
        print("Thank You")
        break
