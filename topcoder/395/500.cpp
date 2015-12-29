#include <bits/stdc++.h>
using namespace std;
class Skyscrapers{
	public:
	int buildingCount(int n,int le,int ri){
		static long long i,j,k,dp[101][101][101],mod=1000000007;
		for(i=0;i<101;i++)
			for(j=0;j<101;j++)
				for(k=0;k<101;k++)dp[i][j][k]=0;
		dp[1][1][1]=1;
		for(i=1;i<100;i++){
			for(j=0;j<=i;j++){
				for(k=0;k<=i;k++){
					if(dp[i][j][k]==0)continue;
					dp[i+1][j+1][k]=(dp[i+1][j+1][k]+dp[i][j][k])%mod;
					dp[i+1][j][k+1]=(dp[i+1][j][k+1]+dp[i][j][k])%mod;
					dp[i+1][j][k]=(dp[i+1][j][k]+((i-1)*dp[i][j][k]))%mod;
				}
			}
		}
		return dp[n][le][ri];
	}
};