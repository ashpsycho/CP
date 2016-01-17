#include <bits/stdc++.h>
#include <fstream>
#define T pair<int,int>
#define x first
#define y second
using namespace std;
int adj[20][20];
vector<int>a,b;
queue<int>q;
bool fn(){						// if there is a max matching from a to b of size=size(a), return true, else return false
	int ans=0,i,j,k,n=a.size(),ad[2*n+2][2*n+2],par[2*n+2],vis[2*n+2];
	for(i=0;i<(2+2*n);i++)
		for(j=0;j<(2+2*n);j++)ad[i][j]=0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(adj[a[i]][b[j]]==1)ad[i+1][j+n+1]=1;
			else ad[i+1][j+1+n]=0;
		}
	}
	for(i=1;i<=n;i++)ad[0][i]=1;
	for(i=1;i<=n;i++)ad[n+i][1+2*n]=1;
	while(true){
		for(i=0;i<(2*n+2);i++)vis[i]=0,par[i]=-1;
		vis[0]=1;
		q.push(0);
		while(!q.empty()){
			j=q.front();
			q.pop();
			for(k=0;k<(2+2*n);k++){
				if(vis[k]==0 && ad[j][k]==1){
					vis[k]=1;
					par[k]=j;
					q.push(k);
				}
			}
		}
		if(vis[1+2*n]==0)break;
		ans++;
		for(i=1+2*n;par[i]!=-1;i=par[i]){
			ad[i][par[i]]=1;
			ad[par[i]][i]=0;
		}
	}
	return (ans==n);
}
int main(){
	static long long t,te,i,j,k,n,m,ans,po[17],worst[16],best[16],lol,x,y;
	po[0]=1;
	set<int> lev[5];
	set<int>::iterator it;
	for(i=1;i<17;i++)po[i]=2*po[i-1];
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin>>t;
	for(te=0;te<t;te++){
		fin>>n;
		for(i=0;i<5;i++)lev[i].clear();
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)fin>>adj[i][j];
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(j!=i && adj[i][j]==0)break;
			}
			if(j==n)worst[i]=1;
			else worst[i]=1+(n/2);
			best[i]=worst[i];
		}
		lev[0].insert(po[n]-1);
		for(i=(n/2),k=1;i>0;i/=2,k++){
			for(j=1;j<po[n];j++){
				if(__builtin_popcount(j)!=i)continue;
				for(it=lev[k-1].begin();it!=lev[k-1].end();++it){
					m=*it;
					if((m&j)!=j)continue;
					a.clear();
					b.clear();
					for(x=0,y=1;x<n;x++,y*=2){
						if((j&y)>0)a.push_back(x);
					}
					for(x=0,y=1;x<n;x++,y*=2){
						if(((m-j)&y)>0)b.push_back(x);
					}
					if(fn()){
						lev[k].insert(j);
						break;
					}
				}
			}
		}
		for(i=0,lol=1+(n/2);i<5;i++,lol=(lol+1)/2){
			for(it=lev[i].begin();it!=lev[i].end();++it){
				j=*it;
				for(k=0,m=1;k<n;k++,m*=2){
					if((j&m)==m)best[k]=min(best[k],lol);
				}
			}
		}
		fout<<"Case #"<<(te+1)<<": \n";
		for(i=0;i<n;i++)fout<<best[i]<<" "<<worst[i]<<"\n";
		cout<<"Case #"<<(te+1)<<": \n";
		for(i=0;i<n;i++)cout<<best[i]<<" "<<worst[i]<<"\n";
	}
	return 0;
}
