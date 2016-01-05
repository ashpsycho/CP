#include <bits/stdc++.h>
using namespace std;
class EventOrder{
	public:
	int getCount(int longE,int inst){
		long long i,j,k=0,mod=1000000009L, dp[2][3004];
		for(i=0;i<2;i++)
			for(j=0;j<3002;j++)dp[i][j]=0;
		dp[0][0]=1;
		for(i=0;i<longE;i++){
			for(j=0;j<3002;j++){
				dp[1][j]=(dp[1][j]+((j*(j-1))/2)*dp[0][j])%mod;
				dp[1][j+1]=(dp[1][j+1]+j*(j+1)*dp[0][j])%mod;
				dp[1][j+2]=(dp[1][j+2]+(((j+2)*(j+1))/2)*dp[0][j])%mod;	
			}
			for(j=0;j<3002;j++){
				dp[0][j]=dp[1][j];
				dp[1][j]=0;
			}
		}
		for(i=0;i<inst;i++){
			for(j=0;j<3002;j++){
				dp[1][j]=(dp[1][j]+j*dp[0][j])%mod;
				dp[1][j+1]=(dp[1][j+1]+(j+1)*dp[0][j])%mod;
			}
			for(j=0;j<3002;j++){
				dp[0][j]=dp[1][j];
				dp[1][j]=0;
			}
		}
		for(i=0;i<=(2*(longE+inst));i++)cout<<dp[0][i]<<" ";
		cout<<"\n";
		for(i=k=0;i<3002;i++)k=(k+dp[0][i])%mod;
		return k;
	}
};