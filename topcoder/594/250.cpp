#include <bits/stdc++.h>
using namespace std;
vector<long long>a,b;
int dp[51][51];
int lcs(){
	int i,j,k,n=a.size(),m=b.size();
	for(i=0;i<=n;i++)
		for(j=0;j<=m;j++)dp[i][j]=0;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			if(a[i-1]==b[j-1])dp[i][j]=max(dp[i][j],1+dp[i-1][j-1]);
		}
	}
	return dp[n][m];
}
class AstronomicalRecords{
	public:
	int minimalPlanets(vector<int>A,vector<int>B){
		int i,j,k,n=A.size(),m=B.size(),ans=n+m;
		for(i=0;i<n;i++)a.push_back(A[i]);
		for(i=0;i<m;i++)b.push_back(B[i]);
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				for(k=0;k<n;k++)a[k]=1LL*A[k]*B[j];
				for(k=0;k<m;k++)b[k]=1LL*B[k]*A[i];
				ans=min(ans,n+m-lcs());
			}
		}
		return ans;
	}
};