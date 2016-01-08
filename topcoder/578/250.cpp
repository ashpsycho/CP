#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
using namespace std;
class GooseInZooDivOne{
	public:
	int count(vector<string>g,int dis){
		int i,j,x,y,n=g.size(),m=g[0].size(),vis[n][m],curr,odd=0,even=0;
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)vis[i][j]=0;
		queue<T>q;
		T a;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(g[i][j]=='.' || vis[i][j]==1)continue;
				q.push(T(i,j));
				vis[i][j]=1;
				curr=0;
				while(!q.empty()){
					a=q.front();
					q.pop();
					curr++;
					for(x=0;x<n;x++){
						for(y=0;y<m;y++){
							if(vis[x][y]==1 || g[x][y]=='.')continue;
							if((abs(x-a.x)+abs(y-a.y))>dis)continue;
							q.push(T(x,y));
							vis[x][y]=1;
						}
					}
				}
				if(curr&1)odd++;
				else even++;
			}
		}
		long long ans=1,mod=1000000007;
		for(i=0;i<even;i++)ans=(ans*2)%mod;
		for(i=0;i<(odd-1);i++)ans=(ans*2)%mod;
		ans--;
		return ans;	
	}
};