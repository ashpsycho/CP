#include <bits/stdc++.h>
using namespace std;
int siz[50],ans[50][101],vis[50];
vector<int>adj[50];
void rec(int n){
	vis[n]=1;
	int i,j,k,x;
	siz[n]=1;
	vector<int> child;
	for(i=0;i<adj[n].size();i++){
		j=adj[n][i];
		if(vis[j]==1)continue;
		child.push_back(j);
		rec(j);
		siz[n]+=siz[j];
	}
	for(j=1;j<101;j++){
		if(j>=(2*siz[n])){
			ans[n][j]=siz[n];
			continue;
		}
		for(i=0;i<child.size();i++){
			for(k=0;k<j;k++){
				x=min(siz[n]-(1+siz[child[i]]),(j-(k+1))/2);
				ans[n][j]=max(ans[n][j],1+x+ans[child[i]][k]);
			}
		}
	}	
}
class WalkOverATree{
	public:
	int maxNodesVisited(vector<int>v,int L){
		int i,j,n=1+v.size();
		if(L>=(2*n))return n;
		for(i=0;i<n;i++)siz[i]=vis[i]=0;
		for(i=0;i<n;i++){
			for(j=0;j<101;j++)ans[i][j]=1;
		}
		for(i=0;i<(n-1);i++){
			adj[i+1].push_back(v[i]);
			adj[v[i]].push_back(1+i);
		}
		rec(0);
		return ans[0][L];
	}
};