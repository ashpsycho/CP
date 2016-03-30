#include <bits/stdc++.h>
using namespace std;
class LISNumber{
	public:
	int count(vector<int> v,int K){
		static long long i,j,k,n=v.size(),ans[37][1300],ncr[1300][1300],mod=1000000007,sum=0;
		for(i=0;i<1300;i++)
			for(j=0;j<1300;j++)ncr[i][j]=0;
		for(i=0;i<1300;i++)ncr[i][0]=1;
		for(i=1;i<1300;i++)
			for(j=1;j<1300;j++)ncr[i][j]=(ncr[i-1][j]+ncr[i-1][j-1])%mod;
		for(i=0;i<37;i++)
			for(j=0;j<1300;j++)ans[i][j]=0;
		ans[0][0]=1;
		for(i=0;i<n;i++){
			for(j=0;j<1300;j++){
				if(ans[i][j]==0)continue;
				for(k=0;k<=j && k<=v[i];k++){
					ans[i+1][j+v[i]-k]=(ans[i+1][j+v[i]-k]+(((ans[i][j]*ncr[j][k])%mod)*(ncr[v[i]+sum-j][sum+k-j]))%mod)%mod;
				}
			}
			sum+=v[i];
		}
		return ans[n][K];
	}
};