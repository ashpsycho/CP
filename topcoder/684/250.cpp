#include <bits/stdc++.h>
using namespace std;
class CliqueParty{
	public:
	int maxsize(vector<int>v,int K){
		sort(v.begin(),v.end());
		int i,k,j,n=v.size(),ans=2,mind,x,dp[n];
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				mind=(v[j]-v[i]);
				mind=(mind+K-1)/K;
				for(k=0;k<n;k++)dp[k]=0;
				dp[i]=1;
				for(k=i+1;k<=j;k++){
					for(x=i;x<k;x++){
						if((v[k]-v[x])>=mind)dp[k]=max(dp[k],dp[x]+1);
					}
				}
				ans=max(ans,dp[j]);
			}
		}
		return ans;
	}
};