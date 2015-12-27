#include <bits/stdc++.h>
using namespace std;
int abs(int n){
	if(n<0)return -n;
	return n;
}
int calc(vector<int> v){
	int n=v.size(),i,j,k,curr,ans=940000001;
	for(i=0;i<n;i++){
		curr=0;
		for(j=0;j<n;j++){
			k=v[i]+(j-i);
			curr+=abs(k-v[j]);
		}
		ans=min(curr,ans);
	}
	return ans;
}
class TheConsecutiveIntegersDivOne{
	public:
	int find(vector<int>v,int K){
		sort(v.begin(),v.end());
		int i,j,k=940000000,n=v.size();
		vector<int> now;
		for(i=0;i<=(n-K);i++){
			now.clear();
			for(j=0;j<K;j++)
				now.push_back(v[i+j]);
			k=min(k,calc(now));
		}
		return k;
	}
};