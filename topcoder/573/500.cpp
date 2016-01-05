#include<bits/stdc++.h>
#define T  pair<long long,long long>
#define TT  pair<T,long long>
#define x first
#define y second
using namespace std;
long long INF = 60000000000LL;
int abs(long long x){
	return max(x,-x);
}
class SkiResorts{
	public:
	long long minCost(vector<string> g,vector<int> h){
		long long i,j,k,n=g.size(),ans[n][n],vis[n][n];
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)ans[i][j]=INF,vis[i][j]=0;
		queue<TT> q;
		TT a,b;
		for(i=0;i<n;i++)
			q.push(TT(T(0,i),abs(h[0]-h[i])));			
		while(!q.empty()){
			a=q.front();
			q.pop();
			if(ans[a.x.x][a.x.y]<a.y)continue;
			ans[a.x.x][a.x.y]=a.y;
			for(i=0;i<n;i++){
				if(g[a.x.x][i]=='N')continue;
				for(j=0;j<n;j++){	
					if(h[j]>h[a.x.y])continue;
					b=TT(T(i,j),a.y+abs(h[i]-h[j]));
					if(ans[b.x.x][b.x.y]<=b.y)continue;
					q.push(b);
					ans[b.x.x][b.x.y]=b.y;
				}
			}
		}	
			
		for(i=0,k=INF;i<n;i++)k=min(k,ans[n-1][i]);
		if(k==INF)return -1;
		return k;
	}
};