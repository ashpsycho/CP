#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
using namespace std;
int vis[51],dis[51];
T farthest(vector<string> g,int x){
	queue<int> q;
	int i,j,n=g.size();
	T ans;
	for(i=0;i<n;i++)vis[i]=0;
	q.push(x);
	vis[x]=1;
	dis[x]=0;
	while(!q.empty()){
		j=q.front();
		q.pop();
		for(i=0;i<n;i++){
			if(g[i][j]=='N'||vis[i]==1)continue;
			vis[i]=1;
			q.push(i);
			dis[i]=dis[j]+1;
			ans=T(i,dis[i]);
		}
	}
	return ans;
	
}
class Egalitarianism{
	public:
	int maxDifference(vector<string> g,int d){
		int ans=0;
		for(int i=0;i<g.size();i++)ans = max(ans,farthest(g,i).y);
		for(int i=0;i<g.size();i++)if(vis[i]==0)return -1;
		return ((ans)*d);
	}
};