#include <bits/stdc++.h>
using namespace std;
class MonstersValley{
	public:
	int minimumPrice(vector<long long>v,vector<int> p){
		long long n=v.size(),i,j,dp[51][101],vis[51][101];
		for(i=0;i<=n;i++){
			for(j=0;j<101;j++)dp[i][j]=vis[i][j]=0;
		}
		vis[0][0]=1;
		for(i=0;i<n;i++){
			for(j=0;j<=(2*i);j++){
				if(vis[i][j]==0)continue;
				if(dp[i][j]>=v[i]){
					vis[i+1][j]=1;
					dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
				}
				vis[i+1][j+p[i]]=1;
				dp[i+1][j+p[i]]=max(dp[i+1][j+p[i]],v[i]+dp[i][j]);
			}
		}
		for(i=0;i<101;i++)if(vis[n][i]==1)break;
		return i;
	}
};