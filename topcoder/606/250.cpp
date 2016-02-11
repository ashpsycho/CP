#include <bits/stdc++.h>
using namespace std;
class EllysNumberGuessing{
	public:
	int getNumber(vector<int> g,vector<int> a){
		int i,j,k,n=g.size();
		vector<int>v,v1;
		k=g[0]+a[0];
		if(k>0 && k<1000000001)v.push_back(k);
		k=g[0]-a[0];
		if(k>0 && k<1000000001)v.push_back(k);
		for(i=1;i<n;i++){
			v1.clear();
			k=g[i]+a[i];
			if(k>0 && k<1000000001)v1.push_back(k);
			k=g[i]-a[i];
			if(k>0 && k<1000000001)v1.push_back(k);
			for(j=v.size()-1;j>=0;j--){
				for(k=0;k<v1.size();k++)if(v[j]==v1[k])break;
				if(k==v1.size())v.erase(v.begin()+j);
			}
		}
		if(v.size()==1)return v[0];
		if(v.size()==0)return -2;
		return -1;
	}
};