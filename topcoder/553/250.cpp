#include <bits/stdc++.h>
using namespace std;
long long fn(vector<int> v){
	stack<long long>s;
	long long i,n=v.size(),j,k;
	for(i=0;i<n;i++){
		if(v[i]==0){
			if(s.size()>1){
				j=s.top();
				s.pop();
				k=s.top();
				s.pop();
				s.push(j+k);
			}
		}
		else s.push(v[i]);
	}
	if(s.size()==0)return 0;
	return s.top();
}
class Suminator{
	public:
	int findMissing(vector<int> v,int res){
		long long i,j,k=0,n=v.size();
		for(i=0;i<n;i++)if(v[i]==-1)k=i;
		v[k]=0;
		if(fn(v)==res)return 0;
		v[k]=1;
		j=fn(v);
		v[k]=2;
		k=fn(v);
		if(j==res)return 1;
		if(j==k|| j>res)return -1;
		i=(res+1-j);
		return i;
	}
};