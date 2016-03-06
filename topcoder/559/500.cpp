#include <bits/stdc++.h>
using namespace std;
vector<int>adj[51];
int par[51],siz[51];
long long rec(int x){
	long long ans=1,i,j,k=0;
	siz[x]=1;
	vector<int>v;
	for(i=0;i<adj[x].size();i++){
		if(adj[x][i]==par[x])continue;
		par[adj[x][i]]=x;
		ans=ans*rec(adj[x][i]);
		v.push_back(siz[adj[x][i]]);
		for(j=siz[adj[x][i]]+1;(j%2)==0;j/=2);
		if(j!=1)k++;
		siz[x]+=siz[adj[x][i]];
	}
	if(k>1)return 0;
	if(v.size()==2 && v[0]==v[1])ans=ans*2;
	return ans;
}
class HatRack{
	public:
	long long countWays(vector<int>a,vector<int>b){
		long long i,j,k,n=a.size()+1,vis[n+1],lev,x,ans=0,y,z;
		for(i=0;i<(n-1);i++){
			adj[a[i]].push_back(b[i]);
			adj[b[i]].push_back(a[i]);
		}
		for(i=1;i<=n;i++){
			vector<int>v;
			queue<int>q;
			q.push(i);
			for(j=0;j<=n;j++)vis[j]=par[j]=0;
			vis[i]=1;
			for(lev=0;!q.empty();lev++){
				v.push_back(q.size());
				for(x=q.size();x>0;x--){
					j=q.front();
					q.pop();
					for(k=0;k<adj[j].size();k++){
						if(vis[adj[j][k]]==1)continue;
						par[j]++;
						vis[adj[j][k]]=1;
						q.push(adj[j][k]);
					}
				}
			}
			for(j=1;j<(v.size()-1);j++)if(v[j]!=(2*v[j-1]))break;
			if(j<(v.size()-1)||(v.size()>1 && v[v.size()-1]>(2*v[v.size()-2])))continue;
			for(j=1,x=y=z=0;j<=n;j++){
				if(par[j]==0)x++;
				if(par[j]==1)y++;
				if(par[j]==2)z++;
			}
			if((x+y+z)!=n || y>1)continue;
			for(j=0;j<=n;j++)par[j]=siz[j]=-1;
			k=rec(i);
			ans+=k;
		}
		return ans;
	}
};