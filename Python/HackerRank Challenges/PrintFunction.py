"""The included code stub will read an integer, n, from STDIN.
Without using any string methods, try to print the following: 123..."""

def printComment():
    n = int(input())
    numbers = 0
    placeholder = ""

    for i in range(1, n+1):
       placeholder = placeholder + str(i)
    print(placeholder)
