#include <bits/stdc++.h>
#include <sstream>
using namespace std;
int lev[201],par[201],cycles=0,n,curr;
vector<int> adj[201];
void rec(int x){
	int i,j,k;
	for(i=0;i<adj[x].size();i++){
		if(adj[x][i]==par[x])continue;
		if(lev[adj[x][i]]==-1){
			par[adj[x][i]]=x;
			lev[adj[x][i]]=lev[x]+1;
			rec(adj[x][i]);
			continue;
		}
		j=x;
		k=adj[x][i];
		while(j!=k){
			if(lev[j]>lev[k])j=par[j];
			else if(lev[j]<lev[k]) k=par[k];
			else{
				j=par[j];
				k=par[k];
			}
		}
		if(j==curr)cycles++;
	}
}
void fill_adj(string s){
	stringstream fin;
	fin<<s;
	int j,k;
	char c;
	while(fin>>j>>k){
		fin>>c;
		j--;
		k--;
		adj[j].push_back(k);
		adj[k].push_back(j);
	}
	return;
}
class CactusCount{
	public:
	int countCacti(int N,vector<string> inp){
		string edges="";
		int i,j,k,co=0,vis[201],x;
		for(i=0;i<inp.size();i++)edges+=inp[i];
		fill_adj(edges);
		n=N;
		for(i=0;i<n;i++)vis[i]=0;
		for(i=0;i<n;i++){
			if(vis[i]!=0)continue;
			co++;
			queue<int>q;
			q.push(i);
			vis[i]=co;
			while(!q.empty()){
				j=q.front();
				q.pop();
				for(k=0;k<adj[j].size();k++){
					if(vis[adj[j][k]]==0){
						vis[adj[j][k]]=co;
						q.push(adj[j][k]);
					}
				}
			}
		}
		for(i=1,k=0;i<=co;i++){
			for(j=0;j<n;j++){
				if(vis[j]==i){
					for(x=0;x<n;x++)par[x]=lev[x]=-1;
					lev[j]=cycles=0;
					curr=j;
					rec(j);
					if(cycles>2)break;
				}
			}
			if(j==n)k++;
		}
		return k;
	}
};