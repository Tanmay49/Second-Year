"""
Write a python program to compute following operations on string:
1.To display the word with longest length (DONE)
2.To determine the frequency of of occurrence if a particular character in a string (DONE)
3.To check whether given string is palindrome or not  (DONE)
4.To display index of the fist apprearance of substring (DONE)
5.To count the occurrences of each word in the string()
"""
inp = input("Enter sentence:")  # Take input of string.
out = inp[::-1]
print("The entered string is: ", inp)

inp = inp.replace(",", " ")  # Replace all the commas with whitespaces.

lst = list(inp.strip().split(" "))# Removes all the whitespaces present in the string and constructs a list of words.
while True:
    try:
       
        a = input("Enter character: ")   # Take input of character that is to be searched in the string.
       
        if len(a) == 1 and a.isalpha() == True and a in inp:  # Condition to check whether input is character and alphabet.
            break
        print("The character is not present in the string\nPlease enter valid character")
    except Exception as e:
        print(e)


# Conditon to check whether the substring is present in the string.
while True:
    try:
        b = input("Enter substring: ")
        if b in inp:
            break
        print("The substring is not present in the string\nPlease enter valid substring")
    except Exception as e:
        print(e)


# Function to find the maximum length of word present in string.
def max_length(lst):
    lst.sort(key=len)
    print(lst)
    a = (max(lst, key=len))
    print("The longest word present in the string is: ", a,"\n")
    print("The length of longest word in the given string is:", len(a),"\n")


# Function to find all the occurrences of the given character in the string.
def occurrences(inp):
    n = 0
    for i in inp:
        if i == a:
            n = n+1
    print("The number of occurrences of the character", a, "is: ", n,"\n")


# Function to check whether the string is a palindrome or not.
def palindrome(inp):  
    if inp == out:
        print("The string is a palindrome","\n")
    else:
        print("The string is not a palindrome","\n")


# Function to print index of substring in string.
def first_app(inp): 
    sub_str = b
    for i in range(len(inp)):
        if inp[i] == sub_str[0]:
            index = i
            flag = ""
            for j in range(index, index+len(sub_str)):
                flag = flag + inp[j]
            if flag == sub_str:

                print('The index of first appearance of substring is: ', index,"\n")
                break
            else:
                pass


def no_of_app(lst): #Function to print frequency of each word in the string.
    count={}
    for i in lst:
        if not i in count:
           count[i] = 1
        else:
         count[i] +=1

    print(count)




max_length(lst)
occurrences(inp)
palindrome(inp)
first_app(inp)
no_of_app(lst)
