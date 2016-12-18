import java.io.*;
class CoinsInput{
	public static void main(String args[])throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter number of coin denominations");
		int i,n=Integer.parseInt(br.readLine()),arr[]=new int[n];
		System.out.println("Enter denominations");
		for(i=0;i<n;i++){
			arr[i]=Integer.parseInt(br.readLine());
		}
		Coins coins = new Coins(arr);
		while(true){
			System.out.println("Enter value");
			i=Integer.parseInt(br.readLine());
			coins.printAllSums(i);
			coins.printTotalSums(i);
		}
	}
}