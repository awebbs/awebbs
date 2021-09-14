package NodeInitialization;

public class LinkedList {
    public Node head;
    //Node head; //head of the list

    public static class Node { //here you create attributes for a Node
       public int data;        //made Node class static so main() can access
        public Node next;

        public Node(int item) {  //Constructing a Node, next is automatically
            data = item;     //initialized as null, but chose to explicitly code it
            next = null;
        }
    }
}

