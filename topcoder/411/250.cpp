#include <bits/stdc++.h>
using namespace std;
class SentenceDecomposition{
	public:
	int decompose(string s,vector<string>v){
		int i,j,k,m=s.size(),n=v.size(),dp[51],x,add;
		for(i=0;i<=m;i++)dp[i]=100;
		dp[0]=0;
		string s1,s2;
		for(i=1;i<=m;i++){
			for(j=0;j<i;j++){
				if(dp[j]==100)continue;
				for(k=0;k<n;k++){
					if(v[k].size()!=(i-j))continue;
					s1=v[k];
					s2=s.substr(j,i-j);
					for(x=add=0;x<(s1.size());x++)if(s1[x]!=s2[x])add++;
					sort(s1.begin(),s1.end());
					sort(s2.begin(),s2.end());
					if(s1!=s2)continue;
					dp[i]=min(dp[i],dp[j]+add);
				}
			}
		}
		if(dp[m]==100)return -1;
		return dp[m];
	}
};