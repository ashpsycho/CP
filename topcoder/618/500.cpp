#include <bits/stdc++.h>
using namespace std;
class LongWordsDiv1{
	public:
	int count(int n){
		long long i,j,k,ans[5001],fact[5001],mod=1000000007;
		ans[1]=ans[2]=ans[0]=1;
		fact[0]=1;
		for(i=1;i<5001;i++)fact[i]=(fact[i-1]*i)%mod;
		for(i=3;i<5001;i++){
			for(j=1;j<i;j++)ans[i]=(ans[i]+(ans[j-1]*ans[i-j])%mod)%mod;
		}
		return (ans[n]*fact[n])%mod;
	}
};