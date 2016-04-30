#include <bits/stdc++.h>
using namespace std;
class SumFullSet{
	public:
	string isSumFullSet(vector<int> v){
		int i,j,k,n=v.size();
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				for(k=0;k<n;k++)if(v[k]==(v[i]+v[j]))break;
				if(k==n)return "not closed";
			}
		}
		return "closed";
	}
};