#include <bits/stdc++.h>
using namespace std;
class AlternateColors2{
	public:
	long long countWays(int n,int K){
		long long i,j,k,dp[100001][4];
		for(i=0;i<100001;i++)
			for(j=0;j<4;j++)dp[i][j]=0;
		dp[0][3]=1;
		for(i=3;i>0;i--){
			for(j=1;j<K;j++){	
				if(j<i)continue;
				for(k=i;k<4;k++){
					dp[j][i]=(dp[j][i]+dp[j-i][k]);
					if(k==2 && i==1)dp[j][i]=(dp[j][i]+dp[j-i][k]);
				}
			}
		}
		k=dp[K-1][1]+(dp[K-1][3]*((1LL*(n+2-K)*(n+1-K))/2LL)) + (2LL*dp[K-1][2] * (n+1-K));
		return k;
	}
};