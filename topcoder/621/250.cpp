#include <bits/stdc++.h>
using namespace std;
#define T pair<long double,long double>
#define x first
#define y second
class RadioRange{
	public:
	double RadiusProbability(vector<int>x,vector<int>y,vector<int>r,int z){
		int i,j,n=x.size();
		T arr[n];
		long double a,ans=0.0;
		for(i=0;i<n;i++){
			a=sqrtl((1LL*x[i]*x[i])+(1LL*y[i]*y[i]));
			arr[i]=T(max((long double)0.0,a-r[i]),a+r[i]);
		}
		sort(arr,arr+n);
		for(i=0,a=0.0;i<n;){
			for(j=i;j<n && arr[j].x<=a;j++)a=max(a,arr[j].y);
			if(j<n){	
				ans+=max((long double)0.0,min(arr[j].x,(long double)z)-min(a,(long double)z));
				a=arr[j].y;
			}
			i=j;
		}
		ans+=max((long double)0.0,(long double)z-a);
		ans/=(long double)z;
		return ans;
	}
};