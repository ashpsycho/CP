#include <bits/stdc++.h>
#include <fstream>
#define MAX 1000000000
using namespace std;
long long sp[101][101],n;

void apsp(){
	for(int i,j,k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(sp[i][j]>(sp[i][k]+sp[k][j])){
					sp[i][j]=sp[i][k]+sp[k][j];
				}
			}
		}
	}
}

int main(){
	long long t,te,i,j,k,m,ans,M,K,dp[10002][2],s[50001],d[50001];
	ofstream fout("output.txt");
	cin>>t;
	for(te=0;te<t;te++){
		cin>>n>>M>>K;
		for(i=0;i<=n;i++){
			for(j=0;j<=n;j++)sp[i][j]=MAX;
			sp[i][i]=0;
		}
		for(i=0;i<M;i++){
			cin>>j>>k>>m;
			sp[k][j]=sp[j][k]=min(sp[j][k],m);
		}
		apsp();
		for(i=0;i<K;i++)cin>>s[i]>>d[i];
		for(i=0;i<K;i++){
			if(sp[1][s[i]]==MAX || sp[1][d[i]]==MAX)break;
		}
		if(i<K){
			fout<<"Case #"<<(te+1)<<": -1\n";
			cout<<"Case #"<<(te+1)<<": -1\n";
			continue;
		}
		cout<<"Heher";
		dp[0][0]=sp[1][s[0]]+sp[s[0]][d[0]];
		dp[0][1]=sp[1][s[0]]+sp[s[0]][s[1]]+sp[s[1]][d[0]];
		for(i=1;i<K;i++){
			dp[i][0]=min(dp[i-1][0]+sp[d[i-1]][s[i]]+sp[s[i]][d[i]], dp[i-1][1]+sp[d[i-1]][d[i]]);
			dp[i][1]=min(dp[i-1][0]+sp[d[i-1]][s[i]]+sp[s[i]][s[i+1]]+sp[s[i+1]][d[i]], 
				dp[i-1][1]+sp[d[i-1]][s[i+1]]+sp[s[i+1]][d[i]]);
		}
		ans=dp[K-1][0];
		fout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
		cout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
	}
	return 0;
}