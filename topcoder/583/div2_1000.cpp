#include <bits/stdc++.h>
using namespace std;
#define T pair<int,int>
#define TT pair<T,int>
#define x first
#define y second
class compare{
	public:
	bool operator()(TT &a, TT &b){
		return (a.y>b.y);
	}
};
class GameOnABoard{
	public:
	int optimalChoice(vector<string> g){
		static int i,j,k,x,y,dis[40][40][40][40], n= g.size(),m=g[0].size(),vis[40][40],ans[40][40];
		T dir[4]={T(0,1),T(0,-1),T(1,0),T(-1,0)};
		priority_queue<TT,vector<TT>,compare>q;
		TT a,b;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				for(x=0;x<n;x++)
					for(y=0;y<m;y++)vis[x][y]=0;
				dis[i][j][i][j]=g[i][j]-'0';
				q.push(TT(T(i,j),g[i][j]-'0'));
				while(!q.empty()){
					a=q.top();
					q.pop();
					if(vis[a.x.x][a.x.y]==1)continue;
					vis[a.x.x][a.x.y]=1;
					dis[i][j][a.x.x][a.x.y]=a.y;
					for(k=0;k<4;k++){
						TT b=TT(T(a.x.x+dir[k].x,a.x.y+dir[k].y),a.y);
						if( b.x.x<0 || b.x.x>=n || b.x.y<0 || b.x.y>=m )continue;
						if(vis[b.x.x][b.x.y] == 1)continue;
						b.y+=(g[b.x.x][b.x.y]-'0');
						q.push(b);
					}
				}
			}
		}
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				ans[i][j]=0;
				for(x=0;x<n;x++)
					for(y=0;y<m;y++)ans[i][j]=max(ans[i][j],dis[i][j][x][y]);
			}
		}
		for(k=1600,i=0;i<n;i++)
			for(j=0;j<m;j++)k=min(k,ans[i][j]);
		return k;
	}
};