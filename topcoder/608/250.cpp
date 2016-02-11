#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
using namespace std;
bool fn(T a, T b){
	return (a.y>b.y);
}
class MysticAndCandies{
	public:
	int minBoxes(int C,int X,vector<int>v1,vector<int> v2){
		int i,j,k,n=v1.size();
		T arr[n];
		for(i=0;i<n;i++)arr[i]=T(v2[i],v1[i]);
		sort(arr,arr+n);
		for(j=i=0;j<=(C-X)&&i<n;i++)j+=arr[i].x;
		sort(arr,arr+n,fn);
		for(j=k=0;j<X;j+=arr[k].y,k++);
		return min(n+1-i,k);
	}
};