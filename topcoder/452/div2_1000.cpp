#include <bits/stdc++.h>
using namespace std;
int calc(int x,int y){
	long long i,ans=1,mod=1000000007L;
	for(i=0;i<x;i++)ans=(ans*2)%mod;
	for(i=1;i<=(x+y);i++)ans=(ans*i)%mod;
	return ans;
}
class HamiltonPath{
	public:
	int countPaths(vector<string> v){
		int i,j,k,n=v.size(),Count[n],vis[n],co=0,po=0;
		for(i=0;i<n;i++){
			for(j=k=0;j<n;j++)if(v[i][j]=='Y')k++;
			if(k>2)return 0;
			Count[i]=k;
		}
		for(i=0;i<n;i++)vis[i]=0;
		queue<int>q;
		for(i=0;i<n;i++){
			if(Count[i]==2||vis[i]==1)continue;
			vis[i]=1;
			if(Count[i]==0){
				po++;
				continue;
			}
			co++;
			q.push(i);
			while(!q.empty()){
				j=q.front();
				q.pop();
				for(k=0;k<n;k++)if(v[j][k]=='Y' && vis[k]==0){
					vis[k]=1;
					q.push(k);
				}
			}
		}
		for(i=0;i<n;i++)if(vis[i]==0)return 0;
		return calc(co,po);
	}
};