import java.io.*;
import java.util.*;
class TowerOfHanoi{
//ERROR: ARRAY INITIALIZATION OF C++ CONTINUES
	Stack tower[]=new Stack[3];

	public void moveNumbersFromAToB(int n,int start,int end){
		if(n!=1)moveNumbersFromAToB(n-1,start,3-(start+end));
		int curr=tower[start].pop();
		System.out.println("Move "+curr+" from "+(1+start)+" to "+(1+end)+".");
		tower[end].push(curr);
		if(n!=1)moveNumbersFromAToB(n-1,3-(start+end),end);
	}

	public void printAllSteps(int n){
		for(int i=0;i<3;i++)tower[i]=new Stack();
		for(int i=n;i>=1;i--)tower[0].push(i);
		moveNumbersFromAToB(n,0,2);
	}

}