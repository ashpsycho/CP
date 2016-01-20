#include <bits/stdc++.h>
using namespace std;
long long fn(int n){
	long long i,j,k,ans=0,curr,mult,dp[10][10];
	for(i=0;i<10;i++)
		for(j=0;j<10;j++)dp[i][j]=0;
	for(i=0;i<10;i++)dp[0][i]=(i*(i+1))/2;
	for(i=1,mult=1;i<10;i++,mult*=10){
		dp[i][1]=(45*mult)+(dp[i-1][1]-1)*10+1;
	}
	for(i=1,mult=10;i<10;i++,mult*=10){
		for(j=2;j<10;j++){
			dp[i][j]=dp[i][j-1]+dp[i][1] + (j-1)*mult;
		}
	}
	for(curr=0,j=0,k=n,mult=1;k>0;k/=10,j++){
		ans+=dp[j][k%10];
		ans+=(curr*(k%10));
		curr+=((k%10)*mult);
		mult*=10;
	}
	return ans;
}
class SumThemAll{
	public:
	long long getSum(int lower,int upper){
		for(int i=0;i<11;i++){
			for(int j=0;j<11;j++)cout<<fn(i*11+j)<<" ";
			cout<<"\n";
		}
		if(lower==0)return fn(upper);
		return (fn(upper)-fn(lower-1));
	}
};