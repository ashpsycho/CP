#include <bits/stdc++.h>
using namespace std;
class ShorterSuperSum{
	public:
	int calculate(int K,int n){
		int i,j,k,dp[15][15];
		for(i=0;i<15;i++)
			for(j=0;j<15;j++)dp[i][j]=0;
		for(i=0;i<15;i++)dp[0][i]=i;
		for(i=1;i<15;i++){
			for(j=0;j<15;j++){
				for(k=0;k<=j;k++)dp[i][j]+=dp[i-1][k];
			}
		}
		return dp[K][n];
	}
};