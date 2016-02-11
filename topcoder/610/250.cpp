#include <bits/stdc++.h>
using namespace std;
class TheMatrix{
	public:
	int MaxArea(vector<string> g){
		static int i,j,k,x,y,n=g.size(),m=g[0].size(),ans=0,dp[100][100][100];
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				for(k=0;k<j;k++)dp[i][j][k]=0;
				dp[i][j][j]=1;
				for(k=j+1;k<m;k++){
					if(g[i][k-1]==g[i][k])break;
					dp[i][j][k]=1;
				}
			}
		}
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				for(k=1;(j+k)<=m;k++){
					for(x=i;x<n;x++){	
						if(dp[x][j][j+k-1]==0)break;
						if(x!=i && g[x][j]==g[x-1][j])break;
					}
					ans=max(ans,k*(x-i));
				}
			}
		}
		return ans;
	}
};