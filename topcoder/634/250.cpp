#include <bits/stdc++.h>
using namespace std;
int check(int n,int K,vector<int> v){
	int i,j,arr[n];
	for(i=0;i<n;i++)arr[i]=0;
	sort(v.begin(),v.end());
	for(i=0;i<v.size();i++){
		sort(arr,arr+n);
		for(j=0;j<v[i];j++)arr[j]++;
	}
	sort(arr,arr+n);
	if(arr[n-1]>=K)return 0;
	return 1;
}
class ShoppingSurveyDiv1{
	public:
	int minValue(int n,int K,vector<int> v){
		int i,j;
		vector<int> v1;
		for(i=0;i<=n;i++){
			v1.clear();
			for(j=0;j<v.size();j++){
				if(v[j]>i)v1.push_back(v[j]-i);
			}
			if(i==n)return n;
			if(check(n-i,K,v1))break;
		}
		return i;
	}
};