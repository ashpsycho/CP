import java.io.*;
class PrintReversedList{
	public static void printList(Node head){
		Node x=head;
		while(x.next!=null){
			System.out.print(x.value +" -> ");
			x=x.next;
		}
		System.out.println(x.value);
	}
	public static void main(String args[])throws Exception{
		BufferedReader br= new BufferedReader (new InputStreamReader (System.in));
		System.out.println("Enter length");
		int n= Integer.parseInt(br.readLine());
		System.out.println("Enter values");
		int j,i=Integer.parseInt(br.readLine());
		Node head = new Node(i),tail= head;
		for(i=1;i<n;i++){
			j=Integer.parseInt(br.readLine());
			Node x =new Node(j);
			tail.next = x;
			tail = x;
		}
		System.out.println("Given list");
		printList(head);
		DoublyLinkedList obj = new DoublyLinkedList();
		head = obj.reverseList(head);
		System.out.println("Reversed List");
		printList(head);
	}
}