/* overflow in first loop , lol */
#include <bits/stdc++.h>
using namespace std;
int main(){
	long long i,j,k,n,r,l;
	cin>>l>>r>>k;
	for(i=1;i<l;i=i*k);
	vector<long long >ans;
	for(;i<=r;i=i*k){
		ans.push_back(i);
		if(k>9&&i>(4000000000000000000LL/k))break;
	}
	if(ans.size()==0){
		cout<<"-1\n";
		return 0;
	}
	for(i=0;i<ans.size();i++)cout<<ans[i]<<" ";
	cout<<"\n";
	return 0;
}
