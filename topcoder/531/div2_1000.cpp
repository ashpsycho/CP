#include <bits/stdc++.h>
#define T pair<int,int>
#define TT pair<T,int>
#define x first
#define y second
using namespace std;
vector<T> adj[50];
vector<string> build,destroy;
int edges[50][50],co=0;
bool fn1(TT a, TT b){
	return (a.y<b.y);
}
bool fn2(TT a, TT b){
	return (a.y>b.y);
}
int costMaxST(vector<int>v){
	vector<TT> edge;
	int i,j,k,tot=0,ans,vis[50];
	for(i=0;i<v.size();i++){
		for(j=0;j<adj[v[i]].size();j++){
			tot+=adj[v[i]][j].y;
			edge.push_back(TT(T(v[i],adj[v[i]][j].x),adj[v[i]][j].y));
		}
	}
	ans=tot/2;
	sort(edge.begin(),edge.end(),fn2);
	for(i=0;i<50;i++)vis[i]=i;
	for(i=0;i<edge.size();i++){
		if(vis[edge[i].x.x]==vis[edge[i].x.y])continue;
		k=vis[edge[i].x.y];
		for(j=0;j<50;j++)if(vis[j]==k)vis[j]=vis[edge[i].x.x];
		ans-=edge[i].y;
	}
	return ans;
}
int costMinST(){
	vector<TT> edge;
	int i,j,k,ans=0,vis[co];
	for(i=0;i<co;i++)vis[i]=i;
	for(i=0;i<co;i++){
		for(j=0;j<co;j++){
			edge.push_back(TT(T(i,j),edges[i][j]));
		}
	}
	sort(edge.begin(),edge.end(),fn1);
	for(i=0;i<edge.size();i++){
		if(vis[edge[i].x.x]==vis[edge[i].x.y])continue;
		k=vis[edge[i].x.y];
		for(j=0;j<co;j++)if(vis[j]==k)vis[j]=vis[edge[i].x.x];
		ans+=edge[i].y;
	}
	return ans;
}
int calc(char c){
	if(c<='Z')return (c-'A');
	return 26+(c-'a');
}
class KingdomReorganization{
	public:
	int getCost(vector<string> g,vector<string> b,vector<string> d){
		build=b;
		destroy=d;
		int i,j,k,n=g.size(),vis[n],ans=0;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(g[i][j]=='0')continue;
				adj[i].push_back(T(j,calc(destroy[i][j])));
			}
		}
		for(i=0;i<n;i++)vis[i]=0;
		for(i=0;i<n;i++){
			if(vis[i]>0)continue;
			queue<int>q;
			q.push(i);
			co++;
			vis[i]=co;
			while(!q.empty()){
				j=q.front();
				q.pop();
				for(k=0;k<adj[j].size();k++){
					if(vis[adj[j][k].x]>0)continue;
					vis[adj[j][k].x]=co;
					q.push(adj[j][k].x);
				}
			}
		}
		vector<int> v;
		for(i=1;i<=co;i++){
			v.clear();
			for(j=0;j<n;j++)
				if(vis[j]==i)v.push_back(j);
			k=costMaxST(v);
			ans+=k;
		}
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)edges[i][j]=1001;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(vis[i]==vis[j])continue;
				edges[vis[i]-1][vis[j]-1]=min(edges[vis[i]-1][vis[j]-1],calc(build[i][j]));
			}
		}
		ans+=costMinST();
		return ans;
	}
};