#include <bits/stdc++.h>
using namespace std;
class TheDevice{
	public:
	int minimumAdditional(vector<string> g){
		int ans=0,z,o,i,j,n=g.size(),m=g[0].size();
		for(i=0;i<m;i++){
			for(j=z=o=0;j<n;j++){
				if(g[j][i]=='0')z++;
				else o++;
			}
			ans=max(ans,(1-min(1,z))+(2-min(2,o)));
		}
		return ans;
	}
};