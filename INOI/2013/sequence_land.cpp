#include <bits/stdc++.h>
#define MAX 301
using namespace std;
int main(){
	int i,j,k,n,K,m,ans,g[MAX][MAX],visited[MAX];
	vector<int>arr[MAX];
	cin>>n>>K;
	for(i=0;i<n;i++){
		cin>>k;
		for(j=0;j<k;j++){
			cin>>m;
			arr[i].push_back(m);
		}
		sort(arr[i].begin(), arr[i].end());
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			g[i][j]=0;
			if(i==j)continue;
			for(k=0,m=0,ans=0;k<arr[i].size() && m<arr[j].size();){
				if(arr[i][k]==arr[j][m]){
					k++;
					m++;
					ans++;
				}
				else if(arr[i][k]>arr[j][m]){
					m++;
				}
				else{
					k++;
				}
			}
			if(ans>=K)g[i][j]=1;
		}
	}

	queue<int>q;
	for(i=0;i<n;i++)visited[i]=0;

	q.push(0);
	visited[0]=1;
	ans=0;
	while(!q.empty()){
		j=q.front();
		q.pop();
		ans++;
		for(i=0;i<n;i++)if(g[i][j]==1 && visited[i]==0){
			visited[i]=1;
			q.push(i);
		}
	}
	cout<<ans<<"\n";
	return 0;
}