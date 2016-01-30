#include <bits/stdc++.h>
#define T pair<int,int>
#define TT pair<T,T>
#define x first
#define y second
using namespace std;
class compare{
	public:
	bool operator()(TT &a, TT &b){
		return (a.y.y>b.y.y);
	}
};
class DoNotTurn{
	public:
	int minimumTurns(int n,int x0,int A,int B,int y0,int C,int D,int p,int m){	
		static int i,j,k,dist[501][501][4],grid[501][501];
		static bool vis[501][501][4];
		T dir[4]={{-1,0},{0,1},{1,0},{0,-1}};
		for(i=0;i<n;i++)
			for(j=0;j<n;j++){
				grid[i][j]=1;	
				for(k=0;k<4;k++){
					vis[i][j][k]=0;
					dist[i][j][k]=10000001;
				}
			}
		for(i=0;i<m;i++){
			x0=x0%p;
			y0=y0%p;
			grid[x0%n][y0%n]=0;
			x0=(1LL*x0*A + B) %(1LL*p);
			y0=(1LL*y0*C + D) %(1LL*p);
		}
		grid[0][0]=grid[n-1][n-1]=1;
		priority_queue<TT,vector<TT>,compare> q;
		TT a,b;
		for(i=0;i<4;i++){
			a=TT(T(0,0),T(i,0));
			q.push(a);
		}
		while(!q.empty()){
			a=q.top();
			q.pop();
			if(vis[a.x.x][a.x.y][a.y.x]==1)continue;
			vis[a.x.x][a.x.y][a.y.x]=1;
			dist[a.x.x][a.x.y][a.y.x]=a.y.y;
			b=a;
			b.y=T((a.y.x+1)%4,a.y.y+1);
			if(vis[b.x.x][b.x.y][b.y.x]==0)q.push(b);
			b.y=T((a.y.x+3)%4,a.y.y+1);
			if(vis[b.x.x][b.x.y][b.y.x]==0)q.push(b);
			b=TT(T(a.x.x+dir[a.y.x].x,a.x.y+dir[a.y.x].y),a.y);
			if(b.x.x<0 || b.x.y<0 || b.x.x>=n || b.x.y>=n || vis[b.x.x][b.x.y][b.y.x]==1||grid[b.x.x][b.x.y]==0)continue;
			q.push(b);
		}
		for(i=0,k=1000001;i<4;i++)
			k=min(k,dist[n-1][n-1][i]);
		if(k>1000000)return -1;
		return k;
	}
};