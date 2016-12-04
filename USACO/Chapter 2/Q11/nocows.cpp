/*
ID: a1lavan1
LANG: C++
TASK: nocows
*/
#include <bits/stdc++.h> 
using namespace std;
long long dp[101][202],mod =9901;
int rec(int n,int k){
	if(dp[k][n]!=-1)return dp[k][n];
	if(n==(2*k-1) && k<3)return (dp[k][n]=1);
	if((n&1)==0 || (n<(2*k-1)))return (dp[k][n]=0);
	if(n<3)return (dp[k][n]=0);
	dp[k][n]=0;
	for(int i=1;i<n;i+=2){
		for(int j=1;j<(k-1);j++){
			dp[k][n]=(dp[k][n]+(2*rec(i,k-1)*rec(n-(i+1),j)))%mod;
		}
		dp[k][n]=(dp[k][n]+(rec(i,k-1)*rec(n-(i+1),k-1)))%mod;
	}
	return (dp[k][n])%mod;
}
int main(){
	ifstream fin("nocows.in");
	ofstream fout("nocows.out");
	long long i,ans,j,k,n,m;
	for(i=0;i<101;i++)
		for(j=0;j<202;j++)dp[i][j]=-1;
	fin>>n>>k;
	fout<<rec(n,k)<<"\n";
	return 0;
}