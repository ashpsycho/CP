#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
#define T pair<int,int>
#define x first
#define y second
int main(){
	static long long dp[5001][5001],mod=1000000007LL t,te,i,j,k,n,m,fin=0;
	string s;
	cin>>n>>s;
	for(i=0;i<5001;i++){
		for(j=0;j<5001;j++)dp[i][j]=0;
	}
	dp[0][0]=1;
	for(i=0;i<n;i++){
		for(j=1;j<=(i+1);j++){
			if(s[i-(j-1)]=='0')dp[i][j]=0;
			else if(j==(i+1))dp[i][j]=1;
			else{
				dp[i][j]=(dp[i][j]+dp[i-1][j-1])%mod;
				if(j<=i){
					
				}
				//add here for i-1,j
			}
			if(j>1)dp[i][j]=(dp[i][j]+dp[i][j-1])%mod;
		}
	}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)fin=(fin+dp[i][j])%mod;
	cout<<fin<<"\n";
	return 0;
}