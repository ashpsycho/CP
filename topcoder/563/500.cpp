#include <bits/stdc++.h>
using namespace std;
class SpellCards{
	public:
	int maxDamage(vector<int> L,vector<int> D){
		int i,j,k,n=L.size(),dp[51][51];
		for(i=0;i<=n;i++)
			for(j=0;j<51;j++)dp[i][j]=0;
		for(i=0;i<n;i++){
			for(j=0;j<=n;j++)dp[i+1][j]=dp[i][j];
			for(j=0;j<=(n-L[i]);j++)dp[i+1][j+L[i]]=max(dp[i+1][j+L[i]],dp[i][j]+D[i]);
		}
		for(k=i=0;i<=n;i++)k=max(k,dp[n][i]);
		return k;
	}
};