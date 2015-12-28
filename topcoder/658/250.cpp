#include <bits/stdc++.h>
using namespace std;
class OddEvenTree{
	public:
	vector<int> getTree(vector<string> g){
		int i,j,k,n=g.size(),vis[n];
		for(i=0;i<n;i++)vis[i]=0;
		vector<int> ans,fail;
		fail.push_back(-1);
		for(i=0;i<n;i++)if(g[0][0]=='O')break;
		char a,b;
		if(i<n)return fail;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				for(k=0;k<n;k++){
					a=g[i][k];
					b=g[j][k];
					if(a==b && g[i][j]=='O')return fail;
					if(a!=b && g[i][j]=='E')return fail;
				}
			}
		}
		for(i=0;i<n && ans.size()<(2*(n-1));i++){
			for(j=0;j<n && ans.size()<(2*(n-1));j++){
				if(g[i][j]=='O' && (vis[i]==0||vis[j]==0)){
					vis[i]=vis[j]=1;
					ans.push_back(i);
					ans.push_back(j);
				}
			}
		}
		if(ans.size()<(2*(n-1)))return fail;
		return ans;
	}
};