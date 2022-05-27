'''Prompt:
You are given a string S and width w. Your task is to wrap the string into a paragraph of width w. 
Function Description: 
Wrap has the following:
 Parameters: 
  string string: a long string
  int max_width: the width to wrap to
 Returns
   string: a single string with newline characters ('\n') where the breaks should be.
'''

def wrap(string, max_width):
    newString = ""
    count = 0
    
    for i in string:
        newString = newString + str(i)
        count = count + 1
        if count % max_width == 0:
           newString = newString + ('\n')
    return newString
