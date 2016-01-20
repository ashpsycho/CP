#include <bits/stdc++.h>
using namespace std;
class RedIsGood{
	public:
	double getProfit(int R,int B){
		int i,j,k;
		long double dp[2][5001];
		for(i=0;i<2;i++)
			for(j=0;j<5001;j++)dp[i][j]=0.0;
		for(i=1;i<=R;i++){
			dp[1][0]=i;
			for(j=1;j<=B;j++){
				dp[1][j]=(i*(1+dp[0][j]) + j*(dp[1][j-1]-1))/((double)(i+j));
				dp[1][j]=max((long double)0.0,dp[1][j]);
			}
			for(j=0;j<5001;j++){
				dp[0][j]=dp[1][j];
				dp[1][j]=0;
			}
		}
		return dp[0][B];
	}
};