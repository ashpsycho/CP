#include <bits/stdc++.h>
using namespace std;
long long mod=1000000007;
long long po(long long base,long long n){
	long long ans=1,mult=base;
	while(n>0){
		if(n&1LL)ans=(ans*mult)%mod;
		mult=(mult*mult)%mod;
		n/=2LL;
	}
	return ans;
}
class PairsOfStrings{
	public:
	int getNumber(int n,int K){
		long long i,k,ans=po(K,n);
		ans=(ans*n)%mod;
		vector<long long>div,podiv;
		for(i=1;(i*i)<=n;i++){
			if((n%i)!=0)continue;
			div.push_back(i);
			div.push_back(n/i);
		}
		sort(div.begin(),div.end());
		for(i=0;i<div.size();i++){
			podiv.push_back(po(K,div[i]));
			for(k=0;k<i;k++)
				if((div[i]%div[k])==0)podiv[i]=(podiv[i]+mod-podiv[k])%mod;
		}
		for(i=0;i<div.size();i++)
			ans=(ans+(mod-((podiv[i]*(n-div[i]))%mod)))%mod;
		return ans;
	}
};