public class Node{
	int value;
	public Node left;
	public Node right;
	public Node parent;
	public Node(int value){
		this.value=value;
		left=right=parent=null;
	}
};