#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
using namespace std;
class HexagonalBoard{
	public:
	int minColors(vector<string> g){
		int i,j,k,n=g.size(),ans=1,col[n][n],vis[n][n];
		T dir[6]={
			T(0,1),
			T(1,0),
			T(1,-1),
			T(0,-1),
			T(-1,0),
			T(-1,1)
		};
		T a,b;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(g[i][j]=='X')break;
			}
			if(j<n)break;
		}
		if(i==n)return 0;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)col[i][j]=vis[i][j]=0;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(g[i][j]=='-' || vis[i][j]==1)continue;
				queue<T> q;
				q.push(T(i,j));
				col[i][j]=vis[i][j]=1;
				while(!q.empty()){
					a=q.front();
					q.pop();
					for(k=0;k<6;k++){
						b=T(a.x+dir[k].x,a.y+dir[k].y);
						if(b.x<0 || b.y<0 || b.x>=n || b.y>=n||g[b.x][b.y]=='-')continue;
						if(col[b.x][b.y]==col[a.x][a.y])return 3;
						if(vis[b.x][b.y]==1)continue;
						vis[b.x][b.y]=1;
						q.push(b);
						col[b.x][b.y]=3-col[a.x][a.y];
						ans=2;
					}
				}
			}
		}
		return ans;
	}
};