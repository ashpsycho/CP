public class Node2{
	int value;
	public Node2 next;			//next node
	public Node2 prev;			//previous node
	//basic value constructor
	public Node2 (int value){
		this.value = value;
		next=prev=null;
	}
}