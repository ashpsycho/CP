#include <bits/stdc++.h>
using namespace std;
class EmoticonsDiv1{	
	public:
	int printSmiles(int N){
		int i,j,k,dp[2000];
		for(i=0;i<2000;i++)dp[i]=2000;
		dp[1]=0;
		for(i=1;i<2000;i++){
			for(j=i+1;j<2000;j++)dp[i]=min(dp[i],dp[j]+j-i);
			for(j=2;(j*i)<2000;j++)dp[i*j]=min(dp[i*j],dp[i]+j);
		}
		return dp[N];
	}
};