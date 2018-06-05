#include <bits/stdc++.h>
using namespace std;
int dp[51][51][51][51];
int main(){
	int t,te,r,b,i,j,k,m,ans;
	for(i=0;i<51;i++){
		for(j=0;j<51;j++){
			for(k=0;k<51;k++){
				for(m=0;m<51;m++)dp[i][j][k][m]=0;
			}
		}
	}
	for(i=0;i<51;i++){
		for(j=0;j<51;j++){
			if(i==0 && j==0)continue;
			for(k=0;k<51;k++){
				for(m=0;m<51;m++){
					if(k==0 && m==0)continue;
					if(k!=0){
						dp[i][j][k][m]=max(dp[i][j][k][m], dp[i][j][k-1][m]);
						if(i>=k && j>=m)dp[i][j][k][m]=max(dp[i][j][k][m], 1+dp[i-k][j-m][k-1][50]);
					}
					if(m!=0){
						dp[i][j][k][m]=max(dp[i][j][k][m], dp[i][j][k][m-1]);
						if(i>=k && j>=m)dp[i][j][k][m]=max(dp[i][j][k][m], 1+dp[i-k][j-m][k][m-1]);
					}
				}
			}
		}
	}
	cin>>t;
	for(te=0;te<t;te++){
		cin>>r>>b;
		cout<<"Case #"<<(te+1)<<": "<<dp[r][b][50][50]<<"\n";
	}
	return 0;
}