import java.io.*;
import java.util.*;

public class SegmentTree{
	private int size;
	public List<Long> tree;
	private int segTreeSize;	

	public SegmentTree(int size){
		if(size>1e8){
			throw OutOfMemoryException(Cannot initialize a SegmentTree with size = " + size);
		}
		this.size = size;
		segTreeSize = getSegTreeSize(size); 
		tree = new ArrayList<Long>(segTreeSize);
	}
	
	/**
	 * Returns the size of a segment tree to support 
	 */
	private int getSegTreeSize(int size){
		
	}

	/**
	 * To return the max size for this segmentTree
	*/
	public int size(){
		return size;
	}
	
	public int update(int index, int value){
		
	}

}
