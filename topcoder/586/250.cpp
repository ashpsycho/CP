#include <bits/stdc++.h>
using namespace std;
long double eps=1e-6;
class T{
public:
	long double a,b;
	int ans;
	T(){};
	T(long double a1,long double b1,int a2){
		a=a1;
		b=b1;
		ans=a2;
	}
};
class PiecewiseLinearFunction{
	public:
	int maximumSolutions(vector<int> v){
		int i,j,k,n=v.size();
		vector<T> arr[2];
		arr[0].push_back(T(-1000000001LL,(long double)v[0]-eps,0));
		arr[0].push_back(T(v[0],v[0],1));
		arr[0].push_back(T((long double)v[0]+eps,1000000001LL,0));
		for(i=1;i<n;i++)if(v[i]==v[i-1])return -1;
		long double a1,a2;
		for(i=0;i<(n-1);i++){
			if(v[i]<v[i+1])a1=v[i]+eps;
			else a1=v[i]-eps;
			a2=v[i+1];
			if(a1>a2)swap(a1,a2);
			arr[1].clear();
			for(j=0;j<arr[0].size();j++){
				if(arr[0][j].a>a2 || arr[0][j].b<a1){
					arr[1].push_back(arr[0][j]);
					continue;
				}
				if(arr[0][j].a<a1)arr[1].push_back(T(arr[0][j].a,a1-eps,arr[0][j].ans));
				arr[1].push_back(T(max(a1,arr[0][j].a),min(a2,arr[0][j].b),1+arr[0][j].ans));
				if(arr[0][j].b>a2)arr[1].push_back(T(a2+eps,arr[0][j].b,arr[0][j].ans));
			}
			arr[0].clear();
			for(k=0;k<arr[1].size();k++)arr[0].push_back(arr[1][k]);
		}
		for(i=j=0;i<arr[0].size();i++)j=max(j,arr[0][i].ans);
		return j;
	}
};