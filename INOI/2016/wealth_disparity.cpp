#include <bits/stdc++.h>
#define MAX 100001
using namespace std;
vector<int> adj[MAX];
int ans=0,par[MAX],arr[MAX];

int rec(int m){
	int k=arr[m];
	for(int j,i=0;i<adj[m].size();i++){
		j=rec(adj[m][i]);
		k=min(k,j);
	}
	ans=max(ans,arr[m]-k);
	return k;
}

int main(){
	int i,j,k,n,m;
	cin>>n;
	for(i=0;i<n;i++)cin>>arr[i];
	for(i=0;i<n;i++){
		cin>>par[i];
		if(par[i]==-1)m=i;
		else adj[par[i]-1].push_back(i);
	}
	rec(m);
	cout<<ans<<'\n';
	return 0;
}