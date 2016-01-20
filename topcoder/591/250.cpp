#include <bits/stdc++.h>
using namespace std;
class TheTree{
	public:
	int maximumDiameter(vector<int> v){
		v.insert(v.begin(),0);
		int i,j,k,n=v.size(),ans=n-1;
		for(j=0;j<n;j++){
			for(k=j+1;k<n && v[k]>=2;k++);
			k--;
			ans=max(ans,(n+k)-(1+2*j));
		}
		return ans;
	}
};