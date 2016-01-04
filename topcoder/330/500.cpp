#include <bits/stdc++.h>
using namespace std;
class PrefixFreeSubsets{
	public:
	long long cantPrefFreeSubsets(vector <string> v){
		sort(v.begin(),v.end());
		long long i,j,k,n=v.size(),dp[n][2];
		for(i=0;i<n;i++)dp[i][0]=dp[i][1]=0;
		dp[0][1]=dp[0][0]=1;
		for(i=1;i<n;i++){
			dp[i][1]=1;
			for(j=0;j<i;j++){
				if(v[i].size()>=v[j].size() && v[j]==(v[i].substr(0,v[j].size())))continue;
				dp[i][1]+=dp[j][1];
			}
			dp[i][0]=dp[i-1][1]+dp[i-1][0];
			cout<<dp[i][0]<<" "<<dp[i][1]<<"\n";
		}
		return dp[n-1][0]+dp[n-1][1];
	}
};