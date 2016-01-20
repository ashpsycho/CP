#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
#define MAX 100001
using namespace std;
long long mod=1000000007;
int abs(int n){
	return max(n,-n);
}
class ArcadeManao{
	public:
	int shortestLadder(vector<string> g,int cR,int cC){
		int i,j,k,n=g.size(),m=g[0].size(),ans,vis[n][m];
		cR--;
		cC--;
		queue<T>q;
		T a,b;
		for(i=0;i<=n;i++){
			for(j=0;j<n;j++){	
				for(k=0;k<m;k++)vis[j][k]=0;
			}
			for(k=0;k<m;k++){
				q.push(T(n-1,k));
				vis[n-1][k]=1;
			}
			while(!q.empty()){
				a=q.front();
				q.pop();
				for(j=0;j<n;j++){
					if(vis[j][a.y]==1||abs(j-a.x)>i|| g[j][a.y]!='X')continue;
					vis[j][a.y]=1;
					q.push(T(j,a.y));
				}
				b=T(a.x,a.y+1);
				if(b.y>=0 && b.y<m && vis[b.x][b.y]==0 && g[b.x][b.y]=='X'){
					vis[b.x][b.y]=1;
					q.push(b);
				}
				b=T(a.x,a.y-1);
				if(b.y>=0 && b.y<m && vis[b.x][b.y]==0 && g[b.x][b.y]=='X'){
					vis[b.x][b.y]=1;
					q.push(b);
				}
			}
			if(vis[cR][cC]==1)return i;
		}
		return i;
	}	
};