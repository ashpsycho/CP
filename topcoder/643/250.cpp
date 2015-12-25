#include <bits/stdc++.h>
using namespace std;
int isprime(long long n){
	if(n<2)return 0;
	long long i=2;
	for(i=2;(i*i)<=n;i++)if((n%i)==0)return 0;
	return 1;
}
class TheKingsFactorization{
	public:
	vector<long long>getVector(long long N,vector<long long>primes){
		long long i,j,n=N;
		for(i=0;i<primes.size();i++)n/=primes[i];
		if(n==1)return primes;
		if(primes.size()==1 && n>primes[0]){
			primes.push_back(n);
			return primes;
		}
		if(primes.size()==2 && n<primes[1]){
			primes.push_back(n);
			sort(primes.begin(),primes.end());
			return primes;
		}
		if(n<10000000000000 && isprime(n)){
			primes.push_back(n);
			sort(primes.begin(),primes.end());
			return primes;
		}
		vector<long long> ans;
		for(i=0;i<(primes.size()-1);i++){
			for(j=primes[i];j<=primes[i+1];j++){
				if((n%j)==0)break;
			}
			n/=j;
			ans.push_back(j);
		}
		if(n!=1)ans.push_back(n);
		for(i=0;i<primes.size();i++)ans.push_back(primes[i]);
		sort(ans.begin(),ans.end());
		return ans;
	}
};