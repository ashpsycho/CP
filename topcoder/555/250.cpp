#include <bits/stdc++.h>
using namespace std;
string getBinary(long long n){
	string ans="";
	for(long long i=0;i<52 && n>0;i++){
		if((n%2)==1)ans=ans+"1";
		else ans=ans+"0";
		n/=2;
	}
	return ans;
}
class CuttingBitString{
	public:
	int getmin(string s){
		long long i,j,k=(1LL<<53),n=s.size(),vis[n+1],dp[n+1];
		reverse(s.begin(),s.end());
		vector<string> pos;
		for(i=1;i<k;i=i*5)pos.push_back(getBinary(i));
		for(i=0;i<=n;i++)vis[i]=0,dp[i]=0;
		vis[0]=1;
		string s1;
		for(i=0;i<n;i++){
			if(s[i]=='0')continue;
			for(j=0;j<=i;j++){
				if(vis[j]==0)continue;
				s1=s.substr(j,(i+1-j));
				for(k=0;k<pos.size();k++)if(s1==pos[k])break;
				if(k<pos.size()){
					if(vis[i+1]==0)dp[i+1]=1+dp[j];
					else dp[i+1]=min(dp[i+1],1+dp[j]);
					vis[i+1]=1;
				}
			}
		}
		if(vis[n]==0)return -1;
		return dp[n];
	}
};
