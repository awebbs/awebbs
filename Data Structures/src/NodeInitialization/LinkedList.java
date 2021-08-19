package NodeInitialization;

public class Node { //here you create attributes for a Node
        int data;        //made Node class static so main() can access
        Node next;

        Node(int item) {  //Constructing a Node, next is automatically
            data = item;     //initialized as null, but chose to explicitly code it
            next = null;
        }
}

