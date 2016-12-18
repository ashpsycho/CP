import java.util.*;
class Coins{
	int allCoins[];
	public Coins(int arr[]){
		Arrays.sort(arr);
		allCoins = arr;
	}
	public void printAllSums(int n){
		int ans[]=new int[n];
		recursiveCall(n,allCoins.length-1,ans,0);
	}

	public void recursiveCall(int n,int maxCoin,int ans[],int ansLength){
		if(n==0){
			for(int i=0;i<ansLength;i++){
				System.out.print(ans[i]);
				if((i==(ansLength-1)))System.out.println("");
				else System.out.print(" + ");
			}
			return;
		}
		ans[ansLength]=0;
		for(int i=maxCoin;i>=0 && allCoins[i]>0;i--){
			if(allCoins[i]>n)continue;
			ans[ansLength]=allCoins[i];
			recursiveCall(n-allCoins[i],i,ans,ansLength+1);
		}
	}

	public void printTotalSums(int n){
		int i,j,dp[]=new int[n+1],m=allCoins.length;
		for(i=0;i<=n;i++)dp[i]=0;
		dp[0]=1;
		for(i=0;i<m;i++){
			for(j=0;j<=(n-allCoins[i]);j++){
				dp[j+allCoins[i]]+=dp[j];
			}
		}
		System.out.println(dp[n]);
	}
}