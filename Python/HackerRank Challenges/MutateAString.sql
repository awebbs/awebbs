/*
Prompt: Read a given string, change the character at a given index and then print the modified string.
*/
def mutate_string(string, position, character):
    li = list(string)
    li[position] = character
    string = ''.join(li)
    
    return string
