#include <bits/stdc++.h>
using namespace std;
class CasketOfStar{
	public:
	int maxEnergy(vector<int>v){
		int i,j,k,n=v.size(),dp[n][n];
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)dp[i][j]=0;
		for(i=1;i<n;i++){
			for(j=0;j<=(n-i);j++){
				if(i==1){
					dp[j][i+j]=0;
					continue;
				}
				for(k=1;k<i;k++)
					dp[j][j+i]=max(dp[j][i+j],(v[j]*v[j+i])+dp[j][j+k]+dp[j+k][j+i]);
			}
		}
		return dp[0][n-1];
	}
};