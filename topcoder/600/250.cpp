#include <bits/stdc++.h>
using namespace std;
class ORSolitaire{
	public:
	int getMinimum(vector<int> v,int K){
		int i,j,k,n=v.size(),arr[32];
		for(i=n-1;i>=0;i--)
			if((v[i]-(v[i]&K))>0)v.erase(v.begin()+i);
		for(i=0;i<32;i++)arr[i]=0;
		for(i=0,n=v.size();i<n;i++){
			for(j=0,k=1;j<31;j++,k*=2)if(k&v[i])arr[j]++;
		}
		for(i=0,k=n,j=1;i<31;i++,j*=2){
			if((j&K)>0)k=min(k,arr[i]);
		}
		return k;
	}
};