# Stack Implementation in Python
# A stack is a Last In First Out (LIFO) data structure
# it is linear and can be used for things like the back
# button in browsers, sending the user to the last page
# they were on which was placed on top of the stack

#Basic Operations: push(item), pop(), empty(), top(), size()
#   Time Complexity for each operation: O(1)

# This program was written in the Spyder IDE

#creat a stack first
def create_a_stack():
    stack = []
    return stack

#check if stack is empty
def is_stack_empty(stack):
    return len(stack) == 0

#add an item to the stack
def push_on_to_stack(stack, item):
    stack.append(item)
    print("pushed item: ", item)

#remove an item from the stack 
def remove_from_stack(stack):
    if(is_stack_empty(stack)):
        print("this stack is empty, nothing to remove")
    return stack.pop()

def main():
    stack = create_a_stack()
    push_on_to_stack(stack, 6)
    push_on_to_stack(stack, 7)
    print("testing sentence")    
    remove_from_stack(stack)
    print("this is the stack after a pop" + str(stack))
    
#call main to invoke it's functionality    
main()
