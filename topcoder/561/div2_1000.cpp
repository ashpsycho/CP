#include <bits/stdc++.h>
using namespace std;
vector<int> adj[52];
int calc[52],vis[52];
void rec(int n){
	vis[n]=1;
	vector<int>v;
	int i,ans=1;
	for(i=0;i<adj[n].size();i++){
		if(vis[adj[n][i]]==1)continue;
		v.push_back(adj[n][i]);
		rec(adj[n][i]);
		ans+=calc[adj[n][i]];
	}
	calc[n]=ans;
}
class FoxAndTouristFamilies{
	public:
	double expectedLength(vector<int>a, vector<int>b,vector<int>f){
		int i,j,k,n=1+a.size();
		double arr[52],ans=0;
		for(i=0;i<(n-1);i++)arr[i]=1.0;
		for(i=0;i<(n-1);i++){
			adj[a[i]].push_back(b[i]);
			adj[b[i]].push_back(a[i]);
		}
		for(i=0;i<f.size();i++){
			for(j=0;j<n;j++)calc[j]=vis[j]=0;
			rec(f[i]);
			for(k=0;k<(n-1);k++){
				arr[k]*=(((double)min(calc[a[k]],calc[b[k]]))/((double)(n-1)));
			}
		}
		for(i=0;i<(n-1);i++){
			ans+=arr[i];
		}
		return ans;
	}
};