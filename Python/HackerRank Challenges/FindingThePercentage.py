'''The provided code stub will read in a dictionary containing key/value pairs of name:[marks] for a list of students. 
Print the average of the marks array for the student name provided, showing 2 places after the decimal. 
 Input Format
The first line contains the integer n, the number of students' records. The next lines contain the names and 
marks obtained by a student, each value separated by a space. The final line contains query_name, the name of a student to query.
Constraint:
length of the array: 3
'''

#Below was what was already programmed in HackerRank
if __name__ == '__main__':
    n = int(input())
    student_marks = {}
    for _ in range(n):
        name, *line = input().split()
        scores = list(map(float, line))
        student_marks[name] = scores
    query_name = input()
    
  # Below was what I added in order to complete the task
    sum = 0
    average = 0
    for i in student_marks[query_name]:
        sum = sum + i
    average = sum / 3
    average_format_float = "{:.2f}".format(average)
    print(average_format_float)
