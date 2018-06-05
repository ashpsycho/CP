import java.io.*;
import java.util.*;
public class Mixer{
	public int arr[],n;
	public Mixer(int nn){
		n=nn;
		arr = new int[n];
	}
	void accept(){
		Scanner scanner = new Scanner(System.in);
		for(int i=0;i<n;i++){
			arr[i]=scanner.nextInt();
		}
	}

	Mixer mix(Mixer A){
		Mixer ans = new Mixer(n+A.n);
		int i,j;
		for(i=0,j=0;i<n || j<A.n; ){
			if(i==n){
				ans.arr[i+j] = A.arr[j];
				j++;
			}
			else if(j==A.n){
				ans.arr[i+j]=arr[i];
				i++;
			}
			else if(arr[i]<A.arr[j]){
				ans.arr[i+j]=arr[i];
				i++;
			}
			else{
				ans.arr[i+j]=A.arr[j];
				j++;
			}
		}
		return ans;
	}

	void display(){
		for(int i=0;i<n;i++)
			System.out.print(arr[i]+" ");
		System.out.println();
	}

	public static void main(String args[])throws Exception{
		Mixer A,B,C;
		Scanner scanner = new Scanner(System.in);
		int nA = scanner.nextInt();
		A = new Mixer(nA);
		A.accept();
		int nB = scanner.nextInt();
                B = new Mixer(nB);
                B.accept();
		C = A.mix(B);
		C.display();
	}
}
