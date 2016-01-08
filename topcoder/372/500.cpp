#include <bits/stdc++.h>
#include <sstream>
using namespace std;
long long dp[501][46][46][2];

long long calc(int n){
	int i,j,k;
	long long ans=0;
	for(i=0;i<46;i++){
		for(j=0;j<46;j++){
			if((abs(i-j)%11)!=0)continue;
			for(k=0;k<n;k++)
				ans+=(dp[k][i][j][0]*(n-k));
		}
	}
	return ans;
}

string toStr(int n){
	stringstream fin;
	fin<<n;
	string ans;
	fin>>ans;
	return ans;
}

class RoundOfEleven{
	public:
	long long maxIncome(int N,int money){
		string s=toStr(N);
		int i,j,k,x,y,n=s.size();
		for(i=0;i<501;i++)
			for(j=0;j<46;j++)
				for(k=0;k<46;k++)dp[i][j][k][0]=dp[i][j][k][1]=0;
		for(i=j=k=0;i<n;i++){
			if(i&1)k+=(s[i]-'0');
			else j+=(s[i]-'0');
		}
		dp[0][j][k][0]=1;
		for(i=0;i<n;i++){
			for(j=0;j<46;j++){
				for(k=0;k<46;k++){
					for(y=0;y<500;y++){
						if(dp[y][j][k][0]==0)continue;
						for(x=0;x<10;x++){
							if(i&1)
								dp[y+abs((s[i]-'0')-x)][j][k+x-(s[i]-'0')][1]+=dp[y][j][k][0];
							else
								dp[y+abs((s[i]-'0')-x)][j+x-(s[i]-'0')][k][1]+=dp[y][j][k][0];
						}
					}
				}
			}
			for(y=0;y<500;y++){
				for(j=0;j<46;j++){
					for(k=0;k<46;k++){
						dp[y][j][k][0]=dp[y][j][k][1];
						dp[y][j][k][1]=0;
					}
				}
			}
		}
		return calc(money);
	}
};