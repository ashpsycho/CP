#include <bits/stdc++.h>
using namespace std;
int adj[51][51];
class PenguinSledding{
	public:
	long long countDesigns(int n,vector<int>a,vector<int> b){
		long long ans=1+a.size(),i,j,k,po[60];
		po[0]=1;
		for(i=1;i<60;i++)po[i]=po[i-1]*2;
		for(i=0;i<a.size();i++){
			a[i]--;
			b[i]--;
			adj[a[i]][b[i]]=adj[b[i]][a[i]]=1;
		}
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				for(k=j+1;k<n;k++){
					if(adj[i][j]==0||adj[j][k]==0 || adj[i][k]==0)continue;
					ans++;
				}
			}
		}
		for(i=0;i<n;i++){
			for(j=k=0;j<n;j++)if(adj[i][j]==1)k++;
			if(k<2)continue;
			ans+=(po[k]-(k+1));
		}
		return ans;
	}
};