#include <bits/stdc++.h>
using namespace std;
int dp[701][701], inp[701],n,K, val[701];

void eval(int i, int j){
	if(inp[i]==(inp[j]-K))dp[i][j]=max(0, val[i]+val[j]+dp[i+1][j-1]);

	dp[i][j]=max(dp[i][j],max(dp[i+1][j],dp[i][j-1]));
	
	for(int k=i+1;k<j;k++){
		if(inp[i]==(inp[k]-K)){
			dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
		}
	}
}

int main(){

	int i,j;
	cin>>n>>K;
	for(i=0;i<n;i++)cin>>val[i];
	for(i=0;i<n;i++)cin>>inp[i];

	for(i=0;i<701;i++)
		for(j=0;j<701;j++)dp[i][j]=0;

	for(i=1;i<701;i++){
		for(j=0;(i+j)<n;j++){
			eval(j,i+j);
		}
	}
	cout<<dp[0][n-1];
	return 0;
}