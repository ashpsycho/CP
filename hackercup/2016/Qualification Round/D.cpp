#include <bits/stdc++.h>
#include <fstream>
#include <stdio.h>
#define T pair<int,int>
#define x first
#define y second
using namespace std;
int main(){
	long long t,te,K,i,j,k,n,m,ans,dp[301][301],comm[301][301];
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin>>t;
	string inp[301];
	for(te=0;te<t;te++){
		fin>>n>>K;
		for(i=0;i<n;i++)fin>>inp[i];
		inp[n]="~";
		n++;
		K++;
		sort(inp,inp+n);
		for(i=0;i<n;i++){
			for(j=0;j<i;j++){
				for(k=0;k<inp[i].size() && k<inp[j].size() && inp[i][k]==inp[j][k];k++);
				comm[i][j]=comm[j][i]=k;
			}
			comm[i][i]=inp[i].size();
		}
		for(i=0;i<K;i++){
			for(j=0;j<n;j++)dp[i][j]=10000000;
		}
		for(i=0;i<n;i++)
			dp[0][i]=inp[i].size();
		for(i=1;i<K;i++){
			for(j=i;j<n;j++){
				for(k=i-1;k<j;k++){
					dp[i][j]=min(dp[i][j],dp[i-1][k]+(long long)(inp[j].size()+inp[k].size())-(2LL*comm[j][k]));
				}
			}
		}
		ans=dp[K-1][n-1]+K-2;
		fout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
		cout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
	}
	return 0;
}
