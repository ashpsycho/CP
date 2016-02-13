#include <bits/stdc++.h>
using namespace std;
#define T pair<int,int>
#define x first
#define y second
class compare{
	public:
	bool operator()(T &a,T &b){
		return (a.y>b.y);
	}
};
class BuildingRoutes{
	public:
	int build(vector<string> G,int K){
		int i,j,k,x,y,n=G.size(),arr[n][n],g[n][n],vis[n][n],ans=0;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++)vis[i][j]=0,arr[i][j]=10000,g[i][j]=G[i][j]-'0';
		}
		T a,b;
		priority_queue<T,vector<T>,compare>q;
		for(i=0;i<n;i++){
			q.push(T(i,0));
			while(!q.empty()){
				a=q.top();
				q.pop();
				if(vis[i][a.x]==1)continue;
				vis[i][a.x]=1;
				arr[i][a.x]=a.y;
				for(j=0;j<n;j++)if(vis[i][j]==0)q.push(T(j,a.y+g[a.x][j]));
			}
		}
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(i==j)continue;
				for(x=k=0;x<n;x++)
					for(y=0;y<n;y++){
						if(arr[x][y]==(arr[x][i]+g[i][j]+arr[j][y]))k++;
					}
				if(k>=K)ans+=g[i][j];
			}
		}
		return ans;
	}
};