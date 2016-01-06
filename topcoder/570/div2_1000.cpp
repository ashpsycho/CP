#include <bits/stdc++.h>
using namespace std;
vector<int> adj[51],child[51];
int vis[51];
long long ans[51][2];
void rec(int x){
	long long i;
	vis[x]=1;
	ans[x][1]=1;
	ans[x][0]=0;
	for(i=0;i<adj[x].size();i++){
		if(vis[adj[x][i]]==0){
			rec(adj[x][i]);
			child[x].push_back(adj[x][i]);
		}
	}
	for(i=0;i<child[x].size();i++){
		ans[x][0]+=(ans[child[x][i]][0]+ans[child[x][i]][1]);
		ans[x][1]*=(1+ans[child[x][i]][1]);
	}
}
class CentaurCompanyDiv2{
	public:
	long long count(vector<int> a,vector<int> b){
		int i,n=1+a.size();
		for(i=0;i<(n-1);i++){
			a[i]--;
			b[i]--;
			adj[a[i]].push_back(b[i]);
			adj[b[i]].push_back(a[i]);
		}
		rec(0);
		return (1+ans[0][0]+ans[0][1]);
	}
};