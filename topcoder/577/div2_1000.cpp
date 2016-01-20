#include <bits/stdc++.h>
using namespace std;
class EllysCoprimesDiv2{
	public:
	int getCount(vector<int> v){
		int i,j,n=v.size(),ans=0;
		sort(v.begin(),v.end());
		for(i=1;i<n;i++){
			if(__gcd(v[i],v[i-1])==1)continue;
			for(j=v[i-1]+1;j<v[i];j++)if(__gcd(j,v[i])==1 && __gcd(j,v[i-1])==1)break;
			if(j<v[i])ans++;
			else ans+=2;
		}
		return ans;
	}
};