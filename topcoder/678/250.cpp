#include <bits/stdc++.h>
using namespace std;
class ANewHope{
	public:
	int count(vector<int> one,vector<int>two,int D){
		int i,k=0,n=one.size(),rev1[n],rev2[n],j=n-D;
		for(i=0;i<n;i++)one[i]--,two[i]--;
		for(i=0;i<n;i++){
			rev1[one[i]]=i;
			rev2[two[i]]=i;
		}
		for(i=0;i<n;i++){
			if(rev1[i]<=rev2[i])continue;
			k=max(k,(rev1[i]+j-(1+rev2[i]))/j);
		}
		return 1+k;
	}
};