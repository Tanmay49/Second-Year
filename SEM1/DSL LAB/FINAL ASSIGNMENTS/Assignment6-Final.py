"""Write a python program to take input of percentage of students. Sort the percentages using
1. Quick sort
2. Top 5 scores
"""

class Sorting:
    def __init__(self):
        self.array = []
        self.array_copy = []

    def create(self):
        i = 1
        goo=True
        while goo:
            n = int(input("Enter number of elements"))
            if n<5:
                print("The number cannot be less than 5")
            else:
                goo=False

        while i <= n:
            try:
                x = int(input("Enter element"))
                self.array.append(x)
                self.array_copy.append(x)
                i += 1
            except ValueError:
                print("Enter integers only!")

    def partition(self, low, high):
        i = (low - 1)  # index of smaller element
        pivot = self.array[high]  # pivot

        for j in range(low, high):

            # If current element is smaller than or
            # equal to pivot
            if self.array[j] <= pivot:
                # increment index of smaller element
                i = i + 1
                self.array[i], self.array[j] = self.array[j], self.array[i]

        self.array[i + 1], self.array[high] = self.array[high], self.array[i + 1]
        return i + 1

    # The main function that implements QuickSort
    # arr[] --> Array to be sorted,
    # low  --> Starting index,
    # high  --> Ending index

    # Function to do Quick sort

    def quickSort(self, low, high):
        if len(self.array) == 1:
            return self.array
        if low < high:
            # pi is partitioning index, arr[p] is now
            # at right place
            pi = s1.partition(low, high)
            print(self.array)
            # Separately sort elements before
            # partition and after partition
            s1.quickSort(low, pi - 1)

            s1.quickSort(pi + 1, high)

s1 = Sorting()
s1.create()
go = True
while go:
    print("\n*****MENU******")
    print("1.Quick Sort")
    print("2.Top 5")
    print("2.Exit")
    ch = int(input("Enter operation to be performed"))

    if ch == 1:
        s1.quickSort(0,len(s1.array)-1)
        print("The sorted array is : ",s1.array)
        s1.array=s1.array_copy[:]
    if ch==2:
        s1.quickSort(0, len(s1.array) - 1)
        for i in range(len(s1.array)-1,len(s1.array)-6,-1):
            print(s1.array[i])
        s1.array = s1.array_copy[:]
    if ch == 3:
        print("Thank You")
        break
