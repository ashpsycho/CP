/*
ID: a1lavan1
LANG: C++
TASK: butter
*/
#include <bits/stdc++.h> 
#define T pair<long long,long long>
#define x first
#define y second
#define MAX 801
using namespace std;
class compare{
public:
	bool operator()(T &a, T &b){
		return (a.y>b.y);
	}
};
int main(){
	ifstream fin("butter.in");
	ofstream fout("butter.out");
	static long long i,ans,j,k,n,m,inp[MAX],p,e,vis[MAX],dist[MAX];
	fin>>n>>p>>e;
	vector<T> adj[MAX];
	for(i=0;i<n;i++)fin>>inp[i],inp[i]--;
	for(i=0;i<e;i++){
		fin>>j>>k>>m;
		adj[j-1].push_back(T(k-1,m));
		adj[k-1].push_back(T(j-1,m));
	}
	//Dijkstra time
	priority_queue<T,vector<T>,compare>q;
	T a,b;
	for(i=0,ans=100000000;i<p;i++){
		for(j=0;j<p;j++)vis[j]=0,dist[j]=100000000;
		q.push(T(i,0));
		while(!q.empty()){
			a=q.top();
			q.pop();
			if(vis[a.x]==1)continue;
			dist[a.x]=a.y;
			vis[a.x]=1;
			for(k=0;k<adj[a.x].size();k++){
				if(vis[adj[a.x][k].x]==1)continue;
				q.push(T(adj[a.x][k].x,a.y+adj[a.x][k].y));
			}
		}
		for(j=k=0;j<n;j++){
			if(dist[inp[j]]==100000000)break;
			k+=dist[inp[j]];
		}
		if(j<n)continue;
		ans=min(ans,k);
	}
	fout<<ans<<"\n";
	return 0;
}