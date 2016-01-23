#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
using namespace std;
bool fn(T a, T b){
	return (a.x+a.y)<(b.x+b.y);
}
class WinterAndPresents{
	public:
	long long getNumber(vector<int> v1,vector<int> v2){
		int i,j,k,curr,n=v1.size();
		T arr[n];
		long long ans=0;
		for(i=0;i<n;i++)arr[i]=T(v1[i],v2[i]);
		sort(arr,arr+n,fn);
		for(i=1,k=arr[0].x+arr[0].y;i<=k;i++){
			for(j=0,curr=1;j<n;j++){
				curr+=min(i,arr[j].x);
				curr-=max(0,i-arr[j].y);
			}
			ans+=curr;
		}
		return ans;
	}
};