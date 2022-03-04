"""
Write a Python program to compute following computation on matrix:
a) Addition of two matrices
b) Subtraction of two matrices
c) Multiplication of two matrices
d) Transpose of a matrix
"""


class matrix:
    def __init__(self):
        self.matrix = []
        self.rows = int(input("Enter number of Rows: "))
        self.columns = int(input("Enter number of Columns: "))
    def acceptMatrix(self):
        for i in range(self.rows):
            matrix = []
            for j in range(self.columns):
                matrix.append(int(input("Enter element")))
            self.matrix.append(matrix)

# defining function to print a matrix by default
def printMatrix(matrix):
    rows = len(matrix)
    columns = len(matrix[0])
    for i in range(rows):
        print('|', end=" ")
        for j in range(columns):
            print(matrix[i][j], end=" ")
        print('|')

    print()

# defining a function to add 2 matrices


def addMatrix(matrix1, matrix2):
    if matrix1.rows != matrix2.rows or matrix1.columns != matrix2.columns:  # Exception Handling for valid matrix
        print("Please enter valid matrices")
        return -1
    add = [] 
    for i in range(matrix1.rows):
        t = []
        for j in range(matrix1.columns):
                x = matrix1.matrix[i][j] + matrix2.matrix[i][j]
                t.append(x)
        add.append(t)


    return add

# defining a function to subtract two matrices

def subMatrix(matrix1, matrix2):
    
    if matrix1.rows != matrix2.rows or matrix1.columns != matrix2.columns:
        print("Please enter valid matrices")
        return -1

    sub = []
    for i in range(matrix1.rows):
        s = []
        for j in range(matrix1.columns):
            x = matrix1.matrix[i][j] - matrix2.matrix[i][j]
            s.append(x)
        sub.append(s)

    return sub

#Function for multiplication of two matrices

def multiplyMatrix(matrix1, matrix2):
 
    if matrix1.rows != matrix2.columns:
        print("Please enter valid matrices")
        return -1


    multi = []
    for i in range(matrix1.rows):
        r = []
        for j in range(matrix2.columns):
            r.append(0)
        multi.append(r)

    
    for i in range(matrix1.rows):
        for j in range(matrix2.columns):
            for k in range(matrix2.rows):
                multi[i][j] += matrix1.matrix[i][k] * matrix2.matrix[k][j]

    return multi

#Function for transpose of a matrix

def transposeMatrix(matrix):
    rows = len(matrix)
    columns = len(matrix[0])

    transMatrix = []
    for i in range(columns):
        a = []
        for j in range(rows):
            a.append(0)
        transMatrix.append(a)

    for i in range(columns):
        for j in range(rows):
            transMatrix[i][j] = matrix[j][i]

    return transMatrix



# Taking input for matrix 1
print("Input for Matrix 1")
m1 = matrix()
m1.acceptMatrix()
# Taking input for matrix 2
print("Input for Matrix 2")
m2 = matrix()
m2.acceptMatrix()

# Printing both matrices
print("*" * 10)
print("Matrix 1")
printMatrix(m1.matrix)
print('*' * 10)
print("Matrix 2")
printMatrix(m2.matrix)
print('*' * 10)


while (True):

    # printing the menu
    print("*"*10 + "Menu" + "*"*10)
    print("""1 . Matrix Addition
2. Matrix Subtraction
3. Matrix Multiplication
4. Matrix Transpose
-1. EXIT """)
    choice = int(input("Enter number for the operation to be performed: "))
    print()

    if choice == 1:
        print('-' * 20)
        print("Addition")
        if (addMatrix(m1, m2) != -1):
            print("Matrix 1")
            printMatrix(m1.matrix)
            print('-' * 20)
            print("Matrix 2")
            printMatrix(m2.matrix)
            print('-' * 20)
            print("Addition Matrix")
            print('-' * 20)
            printMatrix(addMatrix(m1, m2))

    elif choice == 2:
        print('-' * 20)
        print("Subtraction")
        if (subMatrix(m1, m2) != -1):
            print("Matrix 1")
            printMatrix(m1.matrix)
            print('-' * 20)
            print("Matrix 2")
            printMatrix(m2.matrix)
            print('-' * 20)
            print("Subtraction Matrix")
            print('-' * 20)
            printMatrix(subMatrix(m1, m2))

    elif choice == 3:
        print('-' * 20)
        print("multiplication")
        if (multiplyMatrix(m1, m2) != -1):
            print("Matrix 1")
            printMatrix(m1.matrix)
            print('-' * 20)
            print("Matrix 2")
            printMatrix(m2.matrix)
            print('-' * 20)
            print("Multiplication Matrix")
            print('-' * 20)
            printMatrix(multiplyMatrix(m1, m2))

    elif choice == 4:
        print('-' * 20)
        print('Matrix 1')
        printMatrix(m1.matrix)
        print('-' * 20)
        print("Transpose of Matrix 1")
        printMatrix(transposeMatrix(m1.matrix))
        print('-' * 20)
        print('Matrix 2')
        printMatrix(m2.matrix)
        print('-' * 20)
        print("Transpose of Matrix 2")
        printMatrix(transposeMatrix(m2.matrix))
        print('-' * 20)

    elif choice == -1:
        print("THANK YOU")
        break

    else:
        print("Please enter a valid choice from the MENU.")
