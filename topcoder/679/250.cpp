#include <bits/stdc++.h>
using namespace std;
vector<int> adj[2501],good,bad;
int N,vis[2501],ans[2501];
void rec(int n){
	int i;
	vis[n]=1;
	if(n>0)ans[n]=good[n-1]-bad[n-1];
	for(i=0;i<adj[n].size();i++){
		rec(adj[n][i]);
		if(ans[adj[n][i]]>=0)ans[n]+=ans[adj[n][i]];
	}
}
class FiringEmployees{
	public:
	int fire(vector<int> p,vector<int>b,vector<int>g){
		int i,n=1+p.size();
		N=n;
		for(i=0;i<(n-1);i++){
			adj[p[i]].push_back(i+1);
		}
		good=g;
		bad=b;
		for(i=0;i<n;i++)vis[i]=ans[i]=0;
		rec(0);
		return ans[0];
	}
};