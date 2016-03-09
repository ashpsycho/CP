#include <bits/stdc++.h>
using namespace std;
long long fn(int n,int k){
	long long dp[20][20],i,j,x;
	for(i=0;i<20;i++)
		for(j=0;j<20;j++)dp[i][j]=0;
	for(i=1;i<=k;i++)dp[1][i]=1;
	for(i=2;i<=n;i++){
		for(j=1;j<=k;j++){
			for(x=1;x<=k;x++){
				if(x>=j || (j%x)>0)dp[i][x]+=dp[i-1][j];
			}
		}
	}
	for(i=1,x=0;i<=k;i++)x+=dp[n][i];
	return x;
}
int main(){
	int i,j,k,n;
	for(k=1;k<11;k++){
		for(n=1;n<11;n++){
			cout<<fn(n,k)<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
