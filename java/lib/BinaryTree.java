import java.lang.*;
import java.io.*;
class BinaryTree{
	
	Node head;
	
	public BinaryTree(int value){
		head= new Node(value);
	}
	
	public BinaryTree(Node head){
		this.head = head;
	}

	boolean ans;
	public int checkBalance(Node head,boolean ans){
		if(head==null || ans==false)return 0;
		int left=checkBalance(head.left),right=checkBalance(head.right);
		if(Math.abs(right-left)>1)ans=false;
		return (left+right);	
	}

	public boolean isBalanced(){
		if(head == null)return true;
		ans = true;
		checkBalance(head);
		return ans;
	}

	public void addToBST(Node newNode){
		Node current = head;
		if(head == null){
			head = newNode;
			return;
		}
		while(true){
			if(newNode.value>=current.value){
				if(newNode.right == null){
					current.right = newNode;
					newNode.parent = current;
					break;
				}
				else current=newNode.right;
			}
			else{
				if(newNode.left == null){
					current.left = newNode;
					newNode.parent = current;
					break;
				}
				else current=newNode.left;	
			}
		}
	}

	public Node createFromSortedArray(int arr[],int startIndex,int endIndex){
		if(startIndex>endIndex)return null;
		int mid = (startIndex+1+endIndex)/2;
		Node head = new Node(arr[mid]);
		Node left = createFromSortedArray(arr,startIndex,mid-1);
		if(left != null){
			head.left = left;
			left.parent = head;
		}
		Node right = createFromSortedArray(arr,mid+1,endIndex);
		if(right != null){
			head.right = right;
			right.parent = head;
		}
		return head;
	}

	public void addSortedArrayToBST(int arr[]){
		head = createFromSortedArray(arr,0,arr.length-1);
	}
//ERROR: SHIT! DIDN'T CHECK LOGIC
	public boolean isBSTWrongWrongWrong(Node head){
		if(head == null) return true;
		if(!isBST(head.left) || !isBST(head.right))return false;
		if(head.left!=null && head.value<=head.left.value)return false;
		if(head.right!=null && head.value>head.right.value)return false;
		return true;
	}
	int prev =-1;
	public boolean isBST(Node head){
		boolean ans=true;
		if(head== null)return true;
		if(head.left!=null && !isBST(head.left))ans=false;
		if(prev>head.value)return false;
		prev = head.value;
		if(head.right!=null && !isBST(head.right))ans=false;
		return ans;
	}

	public int LCA(Node curr,Node A,Node B,Node ans){
		if(curr==null)return 0;
		int orValue=0;
		if(curr==A)orValue|=1;
		if(curr==B)orValue|=2;
		orValue|=LCA(curr.left,A,B,ans);
		orValue|=LCA(curr.right,A,B,ans);
		if(orValue==3 && ans==null)ans=curr;
		return orValue;
	}

	public Node findLCA(Node head, Node A,Node B){
		Node ans=null;
		LCA(head,A,B,ans);
		return ans;
	}
}