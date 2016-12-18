public class Node{
	int value;
	Node next;
	/* Default constructor */
	public Node(){
		value=0;
		this.next=null;
	}
	// Constructor with value
	public Node(int value){
		this.value = value;
		this.next = null;
	}
}