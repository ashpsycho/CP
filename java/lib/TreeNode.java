import java.util.*;

public class TreeNode{
	int value;
	public TreeNode parent;
	public List<TreeNode> children;

	public TreeNode(int value){
		this.value=value;
		parent=null;
		children = new ArrayList<>();
	}
	
	public int getValue(){
		return value;	
	}

	public void setValue(int value){
		this.value = value;
	}

	public TreeNode getParent(){
		return parent;
	}

	public List<TreeNode> getChildren(){
		return children;
	}

	public void setParent(TreeNode parent){
		this.parent = parent;
	}
};
