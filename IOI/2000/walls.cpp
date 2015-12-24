#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
#define MAX 100001
using namespace std;
int main(){
	int t,te,i,j,k,n,m,c,ans,arr[MAX],fin=-1,m1,m2;
	cin>>m>>n>>c;
	vector<int>adj[251*125];
	static int inp[40],a[251],name[251][251];
	for(i=1,k=0;i<=n;i++){
		for(j=i+1;j<=n;j++,k++)
			name[i][j]=name[j][i]=k;
	}
	for(i=0;i<c;i++)cin>>inp[i];
	for(i=0;i<m;i++){
		cin>>k;
		for(j=0;j<k;j++)
			cin>>a[j];
		for(j=0;j<k;j++)
			adj[name[a[j]][a[(j+1)%k]]].push_back(i);
	}

	vector<int> neigh[201];
	int neigh1[201][201];
	for(i=0;i<m;i++)
		for(j=0;j<m;j++)neigh1[i][j]=0;
	for(i=1;i<=((n*(n-1))/2);i++){
		for(j=0;j<adj[i].size();j++)
			for(k=0;k<adj[i].size();k++){
				if(j==k)continue;
				neigh1[adj[i][j]][adj[i][k]]=1;
			}
	}
	for(i=0;i<m;i++){
		for(j=0;j<m;j++){
			if(neigh1[i][j]==1)neigh[i].push_back(j);
		}
	}

	int dist[40][201],vis[40][201];
	for(i=0;i<c;i++)
		for(j=0;j<m;j++)dist[i][j]=401,vis[i][j]=0;

	queue<int>q;

	for(i=0;i<c;i++){
		for(j=0;j<adj[inp[i]].size();j++){
			q.push(adj[inp[i]][j]);
			dist[i][adj[inp[i]][j]]=0;
			vis[i][adj[inp[i]][j]]=1;
		}
		for(j=1;q.size()>0;j++){
			for(k=q.size();k>0;k--){
				m2=q.front();
				q.pop();
				for(m1=0;m1<neigh[m2].size();m1++){
					if(vis[i][neigh[m2][m1]]==0){
						vis[i][neigh[m2][m1]]=1;
						q.push(neigh[m2][m1]);
						dist[i][neigh[m2][m1]]=j;
					}
				}
			}
		}
		cout<<i<<" "<<inp[i]<<"\n";
		for(j=0;j<m;j++){
			cout<<dist[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"here\n";
	ans=20000;
	for(j=0;j<m;j++){
		for(i=k=0;i<c;i++){
			k+=dist[i][j];
		}
		if(k<ans){
			ans=k;
			fin=j+1;
		}
	}
	cout<<ans<<"\n"<<fin<<"\n";
	return 0;
}
