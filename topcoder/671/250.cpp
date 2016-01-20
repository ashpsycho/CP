#include <bits/stdc++.h>
using namespace std;
class BearCries{
	public:
	int count(string s){
		static long long i,j,k,x,n=s.size(),dp[202][202][102][2],ans=0,mod=1000000007;
		if(s[0]=='_' || s[n-1]=='_')return 0;
		for(i=0;i<202;i++)
			for(j=0;j<202;j++)
				for(x=0;x<102;x++)dp[i][j][x][0]=dp[i][j][x][1]=0;
		dp[0][0][0][0]=1;
		for(i=0;i<n;i++){
			if(s[i]==';'){
				for(j=0;j<=i;j++){
					for(k=0;k<=j;k++){
						for(x=0;x<=(j-k);x++){
							if(dp[j][k][x][0]==0)continue;
							dp[j+1][k][x+1][1]=(dp[j+1][k][x+1][1]+dp[j][k][x][0])%mod;
							dp[j][k+1][x][1]=(dp[j][k+1][x][1] + (j-(k+x))*dp[j][k][x][0])%mod;
						}
					}
				}
			}
			else{
				for(j=0;j<=i;j++){
					for(k=0;k<j;k++){
						for(x=0;x<=(j-k);x++){
							if(dp[j][k][x][0]==0)continue;
							dp[j][k][x][1]=(dp[j][k][x][1]+(j-(k+x))*dp[j][k][x][0])%mod;
							if(x>0)dp[j][k][x-1][1]=(dp[j][k][x-1][1]+x*dp[j][k][x][0])%mod;
						}
					}
				}
			}
			for(j=0;j<=(i+1);j++){
				for(k=0;k<=j;k++){
					for(x=0;x<=(j-k);x++){
						dp[j][k][x][0]=dp[j][k][x][1];
						dp[j][k][x][1]=0;
					}
				}
			}
		}
		for(i=0;i<201;i++)ans=(ans+dp[i][i][0][0])%mod;
		return ans;
	}
};