class DoublyLinkedList{

	Node2 head;
	Node2 tail;
		
	public DoublyLinkedList(){
		this.head=this.tail=null;
	}
	
	public DoublyLinkedList(Node2 head){
		this.head=this.tail=head;
	}
	
	public void addToHead(Node2 newHead){
		if(newHead == null) return;
		newHead.next = this.head;
		this.head = newHead;
		// Handling special cases
		if(this.head.next == null){
			this.tail = this.head;
		}
		return;
	}
	public void addToTail(Node2 newTail){
		if(newTail ==  null)return;
		if(tail == null){
			head = tail = newTail;
			return;
		}
		//2 special cases above
		newTail.prev = tail;
		tail.next = newTail;
	}
	//if next is not null, give this node the value of next node & point its next to next's next
	public void deleteInPlace(Node2 node)
	{	
		if(node==null)return;
		if(node.next == null){
			node=null;
			return;
		}
		node.value= node.next.value;
		node.next = node.next.next;
		return;
	}

	public void removeDuplicates(){
		if(head == null)return;
		Node2 runnerA=head,runnerB;
		// Implement with 2 runners 1 for the entire list
		// The other would run from head till the first one checking for duplicates
		//If duplicates found delete first one in place
		while(runnerA!=null){
			runnerB = head;
			while(runnerB!=runnerA){
				if(runnerB.value == runnerA.value)break;
				runnerB = runnerB.next;
			}
			if(runnerB != runnerA){
				deleteInPlace(runnerA);
			}
			else {
				runnerA = runnerA.next;
			}
		}
	}

//Error: NEVER INITIALIZE VARIABLES INSIDE LOOPS
	public Node2 findKthToLast(int K){
		//Initialize 2 nodes to head
		Node2 runnerA=head,runnerB=head;
		//Move 1 node to K spaces ahead
		int i;
		for( i=0;i<K && runnerA!=null;i++){
			runnerA = runnerA.next;
		}
		if(i<K){		
			System.err.println("Less than "+K+" elements!");
			return head;
		}
		//Move both nodes simultaneously
		while(runnerA!= null){
			runnerA= runnerA.next;
			runnerB= runnerB.next;
		}
		//Return answer
		return runnerB;
	}

//ERROR: FORGOT ARRAY INITIALIZATION IN JAVA
//NOTE: BOOK HAD BETTER SOLUTION
	public Node findFirstElementOfLoop(Node head){
		//take 2 runners run them through the list untill they meet twice
		Node runnerA=head, runnerB=head;
		int i=0,n=0,meetPositions[]=new int[2],numberOfMeets=0;
		while(numberOfMeets!=2){
			while(runnerA!=null){
				runnerA=runnerA.next;
				if(runnerA==null)break;
				runnerA=runnerA.next;
				runnerB=runnerB.next;
				i++;
				if(runnerA == runnerB)break;
			}
			if(runnerA == null){
				System.err.println("This List does not have a cycle");
				return head;
			}
			meetPositions[numberOfMeets]=i;
			numberOfMeets++;
		}
		//the number of loops between the two meetings in the number of nodes in the loop
		//run the 2 runners but with a difference of n= number of elements in loop
		//as soon as they both point to the same element, that is the start of the loop
		n=meetPositions[1]-meetPositions[0];
		runnerA=head;
		for(i=0;i<n;i++){
			runnerA=runnerA.next;
		}
		while(runnerA!= runnerB){
			runnerA= runnerA.next;
			runnerB= runnerB.next;
		}
		return runnerA;
	}

	public Node reverseList(Node head){
		Node curr=head,mid;
		while(curr.next!=null){
			mid=curr.next;
			curr.next = mid.next;
			mid.next = head;
			head = mid;
		}
		return head;
	}
}
