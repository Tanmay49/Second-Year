"""
In second year ,computer engineering class, group A students play cricket,group B students play badminton, group C students play football.
Write a  Python  program using functions to compute the following:
1.The list of students who play both cricket and badminton.(DONE)
2.The list of students who play either cricket or badminton but not both.
3.The list of students who play only football.
4.The list of students who play cricket and football but not badminton.
"""


class Student:
    def __init__(self):
        self.allist = []
        self.cricket = []
        self.badminton = []
        self.football=[]
    def Create(self):
        i = j = k = l = 1
        go=True
        n = int(input("Enter number of students in class"))
        while i <= n:
            try:
                x = int(input("Enter element"))
                if x not in self.allist:
                    self.allist.append(x)
                    i=i+1
                else:
                    print("Roll number already exists")
            except ValueError:
                print("Enter integer values only!")
        while go:
                a = int(input("Enter number of students who play cricket"))
                if(a<=n):
                    go=False
                else:
                    print("The number of students playing cricket cannot be more tha students in class")
        while j <= a:
            try:
                x = int(input("Enter element"))
                if x in self.allist:
                    if x not in self.cricket:
                        self.cricket.append(x)
                        j = j + 1
                    else:
                        print("Roll number already exists")
                else:
                    print("Roll number not present in class")
            except ValueError:
                print("Enter integer values only!")
        go=True
        while go:
            v = int(input("Enter number of students who play badminton"))
            if (v <= n):
                go = False
            else:
                print("The number of students playing cricket cannot be more tha students in class")
        while k <= v:
            try:
                x = int(input("Enter element"))
                if x in self.allist:
                    if x not in self.badminton:
                        self.badminton.append(x)
                        k = k + 1
                    else:
                        print("Roll number already exists")
                else:
                    print("Roll number not present in class")
            except ValueError:
                print("Enter integer value only!")
        go = True
        while go:
            s = int(input("Enter number of students who play badminton"))
            if l <= n:
                go = False
            else:
                print("The number of students playing cricket cannot be more tha students in class")
        while l <= s:
            try:
                x = int(input("Enter element"))
                if x in self.allist:
                    if x not in self.football:
                        self.football.append(x)
                        l = l + 1
                    else:
                        print("Roll number already exists")
                else:
                    print("Roll number not present in class")
            except ValueError:
                print("Enter integer value only!")

    def common(self):
        #TIme complexity is o(n)
        crick_bad = []
        for i in self.cricket:
            if i in self.badminton:
                crick_bad.append(i)
        return crick_bad
    def intersection(self):#TIme complexity is o(n)
        crick_or_bad = []
        for i in self.cricket:
            if i not in self.badminton:
                crick_or_bad.append(i)
        for i in self.badminton:
            if i not in self.cricket:
                crick_or_bad.append(i)
        return crick_or_bad

    def onlyfootball(self):#TIme complexity is o(n)
        only_football=[]
        for i in self.football:
            if i not in self.cricket:
                if i not in self.badminton:
                    only_football.append(i)
        return only_football

    def nobadminton(self):#TIme complexity is o(n)
        no_badminton=[]
        for i in self.cricket +self.football:
            if i not in self.badminton:
                if i not in no_badminton:
                    no_badminton.append(i)
        return no_badminton

s1=Student()
s1.Create()

goo=True
while goo:
    print("*" * 20 + "Menu" + "*" * 20)
    print("""1. To find the common students in cricket and badminton.
    2. To find students who play either cricket and badminton.
    3. To find  students who play only football.
    4. To find students who play cricket and football but not badminton.
          """)
    ch=int(input("Enter operation to be performed"))
    if ch == 1 :
        print(s1.allist)
        print(s1.cricket)
        print(s1.badminton)
        a=s1.common()
        print(a)
    if ch==2:
        print(s1.allist)
        print(s1.cricket)
        print(s1.badminton)
        a=s1.intersection()
        print(a)
    if ch==3:
        print(s1.allist)
        print(s1.cricket)
        print(s1.badminton)
        print(s1.football)
        a=s1.onlyfootball()
        print(a)
    if ch ==4:
        print(s1.allist)
        print(s1.cricket)
        print(s1.badminton)
        print(s1.football)
        a=s1.nobadminton()
        print(a)
    if ch==5:
        print("Thank you")
        goo=False
