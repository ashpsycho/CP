#include <bits/stdc++.h>
using namespace std;
class AmebaDiv1{
	public:
	int count(vector<int> v){
		int i,j,k,n=v.size();
		set<int>s;
		for(i=0;i<n;i++)s.insert(v[i]);
		for(i=0;i<n;i++){
			for(j=v[i],k=0;k<n;k++)if(j==v[k])j=j*2;
			s.erase(j);
		}
		return s.size();
	}
};