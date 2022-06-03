/*
Prompt: Read a given string, change the character at a given index and then print the modified string.
*/
def mutate_string(string, position, character):
    li = list(string)
    li[position] = character
    string = ''.join(li)
    
    return string
    
/*
Prompt: You are given a string. Split the string on a " " (space) delimiter and join using a - hyphen.
*/

def split_and_join(line):
    # write your code here
    line = line.split(" ")
    line = "-".join(line)
    
    return line
