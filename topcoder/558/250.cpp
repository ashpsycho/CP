#include <bits/stdc++.h>
using namespace std;
class Stamp{
	public:
	int getMinimumCost(string s,int st,int pc){
		int i,j,k,n=s.size(),ans=st+n*pc,dp[n+1],x;
		for(i=2;i<=n;i++){
			for(j=0;j<=n;j++)dp[j]=1000000001;
			dp[0]=0;
			for(j=i-1;j<n;j++){
				for(x=0,k=j;k>=0;k--){
					if(s[k]=='R')x=x|1;
					if(s[k]=='G')x=x|2;
					if(s[k]=='B')x=x|4;
					if(x!=0 &&x!=1 &&x!=2 &&x!=4)break;
					if((j+1-k)>=i)dp[j+1]=min(dp[j+1],dp[k]+((j+i-k)/i));
				}
			}
			ans=min(1LL*ans,1LL*st*i+1LL*pc*dp[n]);
		}
		return ans;
	}
};