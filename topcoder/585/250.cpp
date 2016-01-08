#include <bits/stdc++.h>
using namespace std;
class TrafficCongestion{
	public:
	int theMinCars(int n){
		long long i,j,k,ans=1,mod=1000000007;
		for(i=0;i<n;i++){
			if(i&1)ans=(ans*2+1)%mod;
			else ans=(ans*2-1)%mod;
		}
		return ans;
	}
};