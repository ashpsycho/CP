#include <bits/stdc++.h>
using namespace std;
class ColorfulCoins{
	public:
	int minQueries(vector<long long> v){
		long long i,j,k,n=v.size(),ans=1,tot=0;
		if(n==1)return 1;
		map<long long, long long> calc;
		map<long long,long long>::iterator it;
		sort(v.begin(),v.end());
		for(i=1;i<n;i++){
			if(calc.find(v[i]/v[i-1])==calc.end())calc[v[i]/v[i-1]]=1;
			else calc[v[i]/v[i-1]]+=1;
		}
		for(it=calc.begin();it!=calc.end();++it){
			calc[it->first]+=tot;
			tot=(it->second);
			for(k=1,j=0;k<=(it->second);j++)k=k*(it->first);
			ans=max(ans,j);
		}
		return ans;
	}
};