#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
#define MAX 101
using namespace std;
int main(){
	int t,te,i,j,k,n,m,ans,arr[MAX],dp[101][101],sum[101][101];
	cin>>n;
	for(i=0;i<n;i++)cin>>arr[i];
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)sum[i][j]=0;
	}
	for(i=0;i<n;i++){
		for(j=1;(i+j)<=n;j++){
			for(k=0;k<j;k++)sum[i][j]+=arr[i+k];
		}
	}
	for(j=1;j<=n;j++){
		for(i=0;(i+j)<=n;i++){
			if(j==1)dp[i][j]=arr[i];
			else
				dp[i][j]=max(arr[i]+sum[i+1][j-1]-dp[i+1][j-1],arr[i+j-1]+sum[i][j-1]-dp[i][j-1]);
		}
	}
	cout<<dp[0][n]<<" "<<(sum[0][n]-dp[0][n])<<"\n";
	return 0;
}