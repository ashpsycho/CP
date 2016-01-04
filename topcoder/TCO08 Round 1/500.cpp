#include <bits/stdc++.h>
using namespace std;
class Chomp{
	public:
	int moves(int n){
		static int i,j,k,x,y,dp[101][101][101],ans[101][101][101];
		for(i=0;i<101;i++)
			for(j=0;j<101;j++)
				for(k=0;k<101;k++)dp[i][j][k]=ans[i][j][k]=0;
		dp[0][0][0]=1;
		for(i=0;i<101;i++)
			for(j=i;j<101;j++){
				for(k=j;k<101;k++){
					if(k==0)continue;
					for(x=0;x<i;x++)if(dp[x][j][k]==0)break;
					if(x<i)dp[i][j][k]=1;
					for(x=0;x<j;x++)if(dp[min(x,i)][x][k]==0)break;
					if(x<j)dp[i][j][k]=1;
					for(x=0;x<k;x++)if(dp[min(x,i)][min(x,j)][x]==0)break;
					if(x<k)dp[i][j][k]=1;
					if(dp[i][j][k]==0){
						for(x=0;x<i;x++)ans[i][j][k]=max(ans[i][j][k],1+ans[x][j][k]);
						for(x=0;x<j;x++)ans[i][j][k]=max(ans[i][j][k],1+ans[min(x,i)][x][k]);
						for(x=0;x<k;x++)ans[i][j][k]=max(ans[i][j][k],1+ans[min(x,i)][min(j,x)][x]);
					}
					else{
						y=4000;
						for(x=0;x<i;x++)if(dp[x][j][k]==0)y=min(y,ans[x][j][k]);
						for(x=0;x<j;x++)if(dp[min(x,i)][x][k]==0)y=min(y,ans[min(x,i)][x][k]);
						for(x=0;x<k;x++)if(dp[min(x,i)][min(j,x)][x]==0)y=min(y,ans[min(x,i)][min(j,x)][x]);
						ans[i][j][k]=1+y;
					}
				}
			}
		return dp[n][n][n]?(ans[n][n][n]):(-ans[n][n][n]);
	}
};