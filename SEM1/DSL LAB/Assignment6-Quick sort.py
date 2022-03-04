def partition(start,end,arr,curArr):
    pivot=arr[end]
    pivot_index=start
    for i in range(start,end):
        if arr[i]<=pivot:
            arr[pivot_index],arr[i]=arr[i],arr[pivot_index]
            pivot_index+=1
        if curArr:
            print(f"for:{i},list:{list(arr)}\n")
        
    arr[pivot_index],arr[end]=arr[end],arr[pivot_index]

    if curArr:
        print(f"pivot:{pivot},list:{list(arr)}\n")
        print("="*100)

    return pivot_index

def QuickSort(start,end,array,curArr):
    if(start<end):
        pi=partition(start,end,array,curArr)

        QuickSort(start,pi-1,array,curArr)
        QuickSort(pi+1,end,array,curArr)

def T5(arr):
    n=len(arr)
    QuickSort(0,len(arr)-1,arr,False)
    print("The top 5 percentages are : ")
    for i in range(1,6):
        print("Rank {0} :".format(i),arr[n-i])

def cArr(arr):
    if(len(arr)<5):
        print("Number of elements <5")
    for i in arr:
        if not(0<=i<=100):
            print("Invalid percentage")
            return False
    return True

arr=[]
ogArr=list(arr)
while(True):
    print("\n--------MAIN MENU-------\n")
    print("1.Enter new list\n2.Quick Sort \n3.Top 5\n4.Exit")

    ch=int(input("Enter choice"))
    if ch==1:
        tArr=list(map(float,input("Enter a list (SPACE SEPARATED) :").split(" ")))
        if cArr(tArr):
            arr=list(tArr)
            ogArr=list(tArr)
    elif ch==2:
        print("You entered : ",ogArr)
        QuickSort(0,len(arr)-1,arr,True)
        print("Sorted array : ",arr)
        arr=list(ogArr)
    elif ch==3:
        T5(arr)
    elif ch==4:
        print("Thank you")
        break
    else:
        print("Enter a valid choice")