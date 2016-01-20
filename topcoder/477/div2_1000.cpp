#include <bits/stdc++.h>
using namespace std;
class CarelessSecretary{
	public:
	int howMany(int N,int K){
		static long long i,j,k,mod=1000000007,ncr[1001][1001],wrong[1001],ans=0;
		for(i=0;i<1001;i++)
			for(j=0;j<1001;j++)ncr[i][j]=0;
		for(i=0;i<1001;i++)ncr[i][0]=1;
		for(i=1;i<1001;i++)
			for(j=1;j<=i;j++)ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j])%mod;
		wrong[0]=wrong[1]=0;
		for(i=2;i<1001;i++){
			wrong[i]=(i*wrong[i-1]);
			if(i&1)wrong[i]+=(mod-1);
			else wrong[i]++;
			wrong[i]=wrong[i]%mod;
		}
		for(i=0;i<=(N-K);i++){
			k=N-i;
			ans=(ans+(wrong[k]*ncr[N-K][i]))%mod;
		}
		return ans;
	}
};