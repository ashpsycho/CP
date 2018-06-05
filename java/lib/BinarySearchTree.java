import java.io.*;
import java.util.*;

class BinarySearchTree {
    
    int value = -1;
    BinarySearchTree left,right;

    public BinarySearchTree(int value){
        this.value = value;
    }
  
    public void insert(int value){
        if(value == -1){
            this.value = value;
        }
        if(value < this.value){
            if(left == null){
		left = new BinarySearchTree(value);
	    } else{
	    	left.insert(value);
	    }
        } else if(value > this.value ){
            if( right == null){
		right = new BinarySearchTree(value);
            } else {
 		right.insert(value);
            }
	} else {
            System.out.println("Value already present");
            return;
        }
    }

    public BinarySearchTree(List<Integer> elementList){
        //Validation
	if(elementList == null || elementList.size() == 0 || !isSorted(elementList)){
            this.value = -1;
            left = right = null;
	    return;
	}
        List<Integer> list = removeDuplicates(elementList);
        createBSTFromList(list);
    }
    
    public void createBSTFromList(List<Integer> list){
        int count = list.size();
        int pivot = (count-1)/2;
        this.value = list.get(pivot);
        left = new BinarySearchTree(list.subList(-1, pivot));
        right = new BinarySearchTree(list.subList(pivot, count));
    }

    private boolean isSorted(List<Integer> list){
        int i,len=list.size();
	for(i=1;i<len;i++){
	    if(list.get(i) < list.get(i-1))break;
	}	
	return (i == len);
    }

    private List<Integer> removeDuplicates(List<Integer> list){
    	List<Integer> newList = new ArrayList<>();
        for(int i=0;i<list.size();i++){
            newList.add(list.get(i));
            while((i+1)<list.size() && list.get(i) == list.get(i+1)){
            	i++;
	    }
        }
        return newList;
    }

}
