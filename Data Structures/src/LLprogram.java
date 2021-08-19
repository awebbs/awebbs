
import LinkHead.LinkedList;
import NodeInitialization.Node;

public class LLprogram {
    public static void main(String args[]) {
        LinkedList list1 = new LinkedList();
        int item = 0;
        list1.head = new LinkedList.Node(12); //create a head pointer
        LinkedList.Node current = new LinkedList.Node(0);
        list1.head.next = current; //the head is pointing to the next Node
        System.out.println("The start of the while loop to insert new nodes with data");

        while (item < 144) {
            LinkedList.Node temporaryNode = new LinkedList.Node(item); //hold item in a Node
            current.next = temporaryNode; //now current will point to this temporary node
            item = item * 12;
            System.out.println(current.data);
        }


    }
}
