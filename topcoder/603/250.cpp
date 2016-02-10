#include <bits/stdc++.h>
using namespace std;
class MaxMinTreeGame{
	public:
	int findend(vector<int> p,vector<int>v){
		int i,k,n=v.size(),arr[n];
		for(i=0;i<n;i++)arr[i]= (i==0)?0:1;
		for(i=0;i<(n-1);i++)arr[p[i]]++;
		for(i=k=0;i<n;i++)if(arr[i]==1)k=max(k,v[i]);
		return k;
	}
};