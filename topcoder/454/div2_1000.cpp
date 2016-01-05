#include <bits/stdc++.h>
using namespace std;
class NumbersAndMatches{
	public:
	long long differentNumbers(long long N,int K){
		static long long x,i,n,j,k,dp[19][127][127],ans=0,len=0,num[10]={119,100,93,109,46,107,123,37,127,111},tot=0,calc[10];
		for(i=0;i<19;i++)
			for(j=0;j<127;j++)
				for(k=0;k<127;k++){	
					dp[i][j][k]=0;
				}
		for(i=0;i<10;i++)calc[i]=__builtin_popcount(num[i]);
		dp[0][0][0]=1;
		for(len=0,i=1;(i-1)<N;i*=10,len++);
		for(n=N;n>0;n/=10)tot+=__builtin_popcount(num[n%10]);
		for(i=0,n=N;i<len;i++,n/=10){	
			for(j=0;j<126;j++){
				for(k=0;k<126;k++){
					if(dp[i][j][k]==0)continue;
					for(x=0;x<10;x++){
						dp[i+1][j+calc[x]][k+calc[n%10]-__builtin_popcount(num[x]&num[n%10])]+=dp[i][j][k];
					}
				}
			}
		}
		for(i=0;i<=(K);i++){
			ans+=dp[len][tot][i];
		}
		return ans;
	}
};