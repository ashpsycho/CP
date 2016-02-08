#include <bits/stdc++.h>
using namespace std;
class BallsSeparating{
	public:
	int minOperations(vector<int>r,vector<int>g,vector<int> b){
		if(r.size()<3)return -1;
		int i,j,k,n=r.size(),ans=0,mi=31000000;
		for(i=0;i<n;i++){
			ans+=(r[i]+g[i]+b[i]-max(r[i],max(g[i],b[i])));
		}
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				for(k=0;k<n;k++){
					if(i==j || i==k || j==k)continue;
					mi=min(mi,(max(r[i],max(g[i],b[i]))-r[i])+(max(r[j],max(g[j],b[j]))-g[j])+(max(r[k],max(g[k],b[k]))-b[k]));
				}
			}
		}
		ans+=(mi);
		return ans;
	}
};