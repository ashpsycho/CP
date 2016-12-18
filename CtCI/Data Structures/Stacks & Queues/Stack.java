import java.io.*;
public class Stack{
	int cap=100000,arr[]=new int[cap];
	int len;
	public Stack(){
		len=0;
	}
	public void push(int n){
		arr[len]=n;
		if(len<cap)len++;
		else System.err.println("Size exceeded");
	}
	public int size(){
		return len;
	}
	public int pop(){
		if(len!=0)len--;
		return arr[len];
	}
	public boolean isEmpty(){
		return (len==0);
	}
	public int peek(){
		return arr[len-1];
	}

};