#include <bits/stdc++.h>
using namespace std;
class GoodSubset{
	public:
	int numberOfSubsets(int N,vector<int>d){
		long long i,j,n=d.size(),mod=1000000007;
		for(i=n-1;i>=0;i--){
			if((N%d[i])==0)continue;
			d.erase(d.begin()+i);
			n--;
		}
		map<long long,long long>m;
		map<long long,long long>::reverse_iterator it;
		for(i=1;(i*i)<=N;i++){
			if((N%i)!=0)continue;
			m[i]=0;
			m[N/i]=0;
		}
		m[1]=1;
		for(i=0;i<n;i++){
			for(it=m.rbegin();it!=m.rend();++it){
				j=(it->first)*d[i];
				if(j>N)continue;
				if((N%j)!=0)continue;
				m[j]=(m[j]+it->second)%mod;
			}
		}
		if(N==1)m[N]--;
		return m[N];
	}
};