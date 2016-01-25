#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
using namespace std;
class Egalitarianism3{
	public:
	int maxCities(int n,vector<int>a,vector<int> b,vector<int>len){
		int i,j,k,ans=2,vis[50];
		T dis[50];
		if(n==1)return 1;
		vector<T> adj[50];
		for(i=0;i<(n-1);i++){
			adj[a[i]-1].push_back(T(b[i]-1,len[i]));
			adj[b[i]-1].push_back(T(a[i]-1,len[i]));
		}
		queue<int>q;
		set<int>s;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++)vis[j]=0;
			q.push(i);
			vis[i]=1;
			dis[i]=T(0,-1);
			while(!q.empty()){
				j=q.front();
				q.pop();
				for(k=0;k<adj[j].size();k++){
					if(vis[adj[j][k].x]==1)continue;
					vis[adj[j][k].x]=1;
					q.push(adj[j][k].x);
					dis[adj[j][k].x].x=adj[j][k].y+dis[j].x;
					if(j==i)dis[adj[j][k].x].y=adj[j][k].x;
					else dis[adj[j][k].x].y=dis[j].y;
				}
			}
			sort(dis,dis+n);
			for(j=0;j<n;){
				s.clear();
				for(k=j;k<n && dis[j].x==dis[k].x;k++)s.insert(dis[k].y);
				ans=max(ans,(int)s.size());
				j=k;
			}
		}
		return ans;
	}
};