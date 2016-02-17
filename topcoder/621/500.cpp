#include <bits/stdc++.h>
#define T pair<long long,long long>
#define x first
#define y second
using namespace std;
long long n,color[4001],par[4001],ans[4001],vis[4001],c1,c2;
vector<int> adj1[4001],adj2[4001];
T dfs(int x){
	int i;
	T b,a=T(1,color[x]);
	for(i=0;i<adj2[x].size();i++){
		if(par[x]==adj2[x][i])continue;
		par[adj2[x][i]]=x;
		b=dfs(adj2[x][i]);
		a=T(a.x+b.x,a.y+b.y);
	}
	if(x)ans[max(max(c1-a.y,c2-(a.x-a.y)),max(a.y,a.x-a.y))]++;
	return a;
}
class TreesAnalysis{
	public:
	long long treeSimilarity(vector<int> t1,vector<int> t2){
		long long i,j,k,fin=0;
		long long n=1+t1.size();
		for(i=0;i<(n-1);i++){
			adj1[t1[i]].push_back(i);
			adj1[i].push_back(t1[i]);
			adj2[t2[i]].push_back(i);
			adj2[i].push_back(t2[i]);
		}
		queue<int>q;
		for(i=0;i<(n-1);i++){
			for(j=0;j<n;j++)color[j]=vis[j]=ans[j]=0,par[j]=-1;
			q.push(i);
			vis[i]=1;
			c1=c2=0;
			while(!q.empty()){
				c1++;
				j=q.front();
				q.pop();
				color[j]=1;
				for(k=0;k<adj1[j].size();k++)if(adj1[j][k]!=t1[i] && vis[adj1[j][k]]==0){
					vis[adj1[j][k]]=1;
					q.push(adj1[j][k]);
				} 
			}
			c2=n-c1;
			dfs(0);
			for(j=1;j<n;j++)fin+=(ans[j]*j*j);
		}
		return fin;
	}
};