#include <bits/stdc++.h>
using namespace std;
int fn(vector<int>v){
	int n=v.size();	
	sort(v.begin(),v.end());
	return v[n-1]-v[0];
}
class TaroFriends{
	public:
	int getNumber(vector<int>v,int X){
		int i,n=v.size(),ans=fn(v);
		sort(v.begin(),v.end());
		for(i=0;i<n;i++){
			v[i]+=(2*X);
			ans=min(ans,fn(v));
		}
		return ans;
	}
};