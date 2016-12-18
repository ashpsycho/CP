/*
Input : A string  (e.g : aabbbccccaa)
Output  Compressed String  (a2b3c4a2)
*/
/*
Error Log:
1. Forgot to write comments in the start
2. Wrote extra code to compute Length (Could be done better in 1 loop or with functional programming)
3. Can compute length by converting to String
*/
import java.io.*;
import java.util.*;
class StringCompressor{
	static String input;
	static String output;

	public static int log10(int n){
		int i,ans;
		for(i=1,ans=0;i<=n;i*=10, ans++);
		return ans;
	}

	public static int calculateNewLength(){
		int i,j,ans=0,length=input.length();
		for(i=0;i<length;){
			for(j=i+1;j<length && input.charAt(i) ==input.charAt(j);j++);
			ans++;
			ans+=log10(j-i);
			i=j;
		}
		return ans;
	}

	public static String compress(){
		int i,j,length=input.length(),newLength = calculateNewLength();
		if(newLength >length){
			return input; 
		}
		StringBuffer ans=new StringBuffer();
		for(i=0;i<length;){
			for(j=i+1;j<length && input.charAt(i)==input.charAt(j);j++);
			ans.append(input.charAt(i));
			ans.append((j-i));
			i=j;
		}
		return ans.toString();
	}

	public static void main(String args[])throws Exception{
		//take input
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		input=br.readLine();
		output=compress();
		System.out.println(output);
	}
}