#include <bits/stdc++.h>
using namespace std;
class TeamContest{
	public:
	int worstRank(vector<int> v){
		int ans=1,i,j,k,n=v.size()/3,mine=max(v[0],max(v[1],v[2]))+min(v[0],min(v[1],v[2]));
		for(i=0;i<3;i++)v.erase(v.begin());	
		sort(v.begin(),v.end());
		reverse(v.begin(),v.end());
		for(i=0;i<(n-1);i++){
			k=v[0];
			v.erase(v.begin());
			for(j=1;j<(v.size()-1)&&(k+v[j+1])>mine;j++);
			if((k+v[j])<=mine){
				return ans;
			}
			else{
				ans++;
				v.erase(v.begin()+(j-1));
				v.erase(v.begin()+(j-1));
			}
		}	
		return ans;
	}
};