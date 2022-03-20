"""
Write a python program to compute following operations on string:
1.To display the word with longest length (DONE)
2.To determine the frequency of of occurrence of a particular character in a string (DONE)
3.To check whether given string is palindrome or not  (DONE)
4.To display index of the fist apprearance of substring (DONE)
5.To count the occurrences of each word in the string()
"""

class String:
    def __init__(self):

        self.string = input("Enter string : ")
        self.result=""
        self.lword=""
        self.count=0

    def longestword(self):
        longestword = ""
        longestLength = 0
        count = 0
        word = ""
        for i in range(len(self.string)):
            if self.string[i] == " ":
                if longestLength < count:
                    longestLength = count
                    longestword = word
                count = 0
                word = ""
            elif i == len(self.string) - 1:
                count += 1
                word += self.string[i]
                if longestLength < count:
                    longestLength = count
                    longestword = word
            else:
                count += 1
                word += self.string[i]
        self.lword=longestword

    def frequency_of_character(self):
        
        a = input("Enter character to be found")
        for i in self.string: #Time complexity of O(n)
            if i == a:
                self.count += 1

    def palindrome(self):
        palindrome = self.string[::-1]
        if palindrome == self.string:
            self.result += "Is a palindrome"
        else:
            self.result += "Not a palindrome"



    def frequency(self):
        count=0
        dct={}
        for i in self.string:
            if i not in dct:
                dct[i]=1
            else:
                dct[i]+=1
        return dct
    def frequency_of_each_word(self):
        occurenceofeachword={}
        lst=(self.string.strip().split(" "))
        print(lst)
        for i in lst:
            if  not i in occurenceofeachword:
                occurenceofeachword[i]=1
            else:
                occurenceofeachword[i]+=1
        return occurenceofeachword
    def first_appearance(self):
        ind=0
        go=True
        while go:
            substring=input("Enter substring : ")
            if substring in self.string:
                break
            else:
                print ("Substring not present in string")
                go=False
        for i in range(len(self.string)):
            if self.string[i]==substring[0]:
                index=i
                flag=""
                for j in range(index,index+len(substring)):
                    flag=flag+self.string[j]
                if flag==substring:
                    ind=ind+index
                    print("Found at index",ind)
                    break
                else:
                    pass


s1=String()

go=True
while go:
    print("********MENU********")
    print("1.To display the longest word")
    print("2.To determine the frequency of of occurrence of a particular character in a string")
    print("3.To check whether given string is palindrome or not")
    print("4.To count the occurrences of each word in the string")
    print("5.To count the occurrences of each character in the string")
    print("6.To display index of the fist apprearance of substring ")
    ch=int(input("Enter choice"))

    if ch==1:
        print(s1.string)
        s1.longestword()
        print(s1.lword)
    if ch==2:
        print(s1.string)
        s1.frequency_of_character()
        print(s1.count)
        s1.count=0
    if ch==3:
        print(s1.string)
        s1.palindrome()
        print(s1.result)
    if ch==4:
        a=s1.frequency_of_each_word()
        print(a)
    if ch==5:
        print(s1.string)
        a=s1.frequency()
        print(a)
    if ch==6:
        s1.first_appearance()
        

    if ch==7:
        go = False