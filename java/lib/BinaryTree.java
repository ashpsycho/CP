import java.lang.*;
import java.io.*;
class BinaryTree{
	
    int value = -1;
    BinaryTree left, right;

    public BinaryTree(int value){
	this.value = value;
	left = right = null;
    }

    private int checkBalance(BinaryTree head){
	if(head == null)return 0;
	int leftHeight = checkBalance(head.getLeft());
	int rightHeight = checkBalance(head.getRight());
        if(leftHeight == -1 || rightHeight == -1 || Math.abs(leftHeight - rightHeight) > 1 ){
		return -1;
	}
	return (1+Math.max(leftHeight, rightHeight));
    }

    public BinaryTree getLeft(){
	return left;
    }

    public BinaryTree getRight(){
	return right;
    }

    public int getValue(){
	return value;
    }

    public boolean isBalanced(){
	return (checkBalance(this) != -1);
    }

    class BSTTuple{
	public boolean isBST;
        public int min,max;

	public BSTTuple(){
	    isBST = true;
	}

        public BSTTuple(boolean isBST, int min, int max){
	    this.isBST = isBST;
	    this.min = min;
	    this.max = max;
	}
    }

    private BSTTuple getBSTTuple(BinaryTree root){
    	BSTTuple notBST = new BSTTuple(false, -1, -1);
	if(value == -1){
	    return new BSTTuple(true, -1, -1);
	}
	BSTTuple tuple = new BSTTuple();
	if(left == null){
	    tuple.min = value;
	}
	else{
	    BSTTuple leftTuple = getBSTTuple(root.getLeft());
            if(!leftTuple.isBST || root.getValue() < root.getLeft().getValue()){
		return notBST;
	    }  
	    tuple.min = leftTuple.min;
	}
 	if(right == null){
            tuple.max = value;
        }
        else{
            BSTTuple rightTuple = getBSTTuple(root.getRight());
            if(!rightTuple.isBST || root.getValue() < root.getRight().getValue()){
                return notBST;
            }
            tuple.max = rightTuple.max;
        }
	return tuple;
    }

    public boolean isBST(){
	BSTTuple tuple = getBSTTuple(this);
	return tuple.isBST;
    }

    public int findLCARecursively(BinaryTree root, int A, int B, BinaryTree ans){
    	if(root == null) return 0;
        int leftSum = 0, rightSum = 0;
        if(root.getLeft() != null)leftSum = findLCARecursively(root.getLeft(), A, B, ans);
	if(root.getRight() != null)rightSum = findLCARecursively(root.getRight(), A, B, ans);
        if(leftSum == 1 && rightSum == 1){
	    ans = root;
	    return 2;
	}
	if(root.getValue() == A || root.getValue() == B){ 
            if((leftSum + rightSum) == 1) ans = root;
	    return (1 + leftSum + rightSum);
        }
	return (leftSum + rightSum);
    }

    // Assume unique values for A & B
    public BinaryTree LCA(int A,int B){
	BinaryTree placeholder = new BinaryTree(-1);
	findLCARecursively(this, A, B, placeholder);
        return placeholder;
    }
}
