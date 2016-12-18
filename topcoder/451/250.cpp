#include <bits/stdc++.h>
using namespace std;
class MagicalSource{
	public:
	long long calculate(long long n){
		long long ans=n,i=1;
		while(i<=n){
			if((n%i)==0)ans=(n/i);
			i=i*10L+1L;
		}
		return ans;
	}
};