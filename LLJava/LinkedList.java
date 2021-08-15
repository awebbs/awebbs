// Linked List implemented in Java
// Removing the head of the linked list is O(1)
// Removing an element in the middle of the list is O(n), however you do not need to do any shifting
// just rearrange a couple of pointers to a new node that is being inserted
// Note: you do not need to free up nodes, Java is a garbage collecting language

// This Program was written using the IntelliJ IDE

import NodeInitialization.LinkedList;

public class LLprogram {
    public static void main(String args[]) {
        LinkedList list1 = new LinkedList(); //creating a linkedlist object
        int item = 0;
        list1.head = new LinkedList.Node(12); //create a head pointer
        LinkedList.Node current = new LinkedList.Node(-1);
        list1.head.next = current; //the head is pointing to the next Node
        System.out.println(list1.head.data); //checking to see if head node holds the right data
        System.out.println(list1.head.next.data); //ensuring that next node holds the right data


        System.out.println("The start of the while loop to insert new nodes with data");
        while (item < 156) { //stop the loop when it hits 144
            LinkedList.Node temp = new LinkedList.Node(item); //hold item in a temp Node
           // System.out.print(temp.data + ", "); //testing to see check that temp Node holds the right data
            current.data = temp.data; //now current will point to this temporary node
            current.next = temp.next; //current's next will be what temps next is
            item = item + 12; //incrementing by 12
            System.out.print(current.data + ", "); //Ensuring the linked list forms accurately
        }


    }
}
