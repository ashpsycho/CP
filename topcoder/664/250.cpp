#include <bits/stdc++.h>
using namespace std;
long long pow(long long n,long long mod){
	long long ans=1,mult=2LL;
	while(n>0){
		if(n&1)ans=(ans*mult)%mod;
		n/=2;
		mult=(mult*mult)%mod;
	}
	return ans;
}
class BearPlays{
	public:
	int pileSize(int A,int B,int K){
		long long a=A,b=B,k=K,i,j;
		i=pow(k,a+b);
		j=(a+b);
		a=(a*i)%(a+b);
		return min(a,j-a);
	}
};