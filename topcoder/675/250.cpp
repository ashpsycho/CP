#include <bits/stdc++.h>
using namespace std;
class TreeAndPathLength3{
	public:
	vector<int> construct(int s){
		int i,j,k=1,n,curr=4;
		vector<int> ans;
		ans.push_back(0);
		ans.push_back(1);
		ans.push_back(0);
		ans.push_back(2);
		ans.push_back(2);
		ans.push_back(3);
		if(s==1)return ans;
		for(i=s-1;i>=0;i--){
			for(j=1,k=1;(j*j)<=s;j++){
				if((i%j)==0)k=j;
			}
			n=s-i;
			n+=(k+((i-k)/k));
			if(n<=497)break;
		}
		for(j=0;j<(s-i);j++){
			ans.push_back(3);
			ans.push_back(curr++);
		}
		for(j=0;j<(k-1);j++){
			ans.push_back(0);
			ans.push_back(curr++);
		}
		for(j=0;j<((i-k)/k);j++){
			ans.push_back(1);
			ans.push_back(curr++);
		}
		for(i=0;i<ans.size();i++)cout<<ans[i]<<" ";

		return ans;
	}
};