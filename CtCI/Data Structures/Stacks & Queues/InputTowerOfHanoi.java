import java.io.*;
class InputTowerOfHanoi{
	
	public static void main(String args[])throws IOException{
		TowerOfHanoi obj = new TowerOfHanoi();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(br.readLine());
		obj.printAllSteps(n);
	}
}