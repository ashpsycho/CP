#include <bits/stdc++.h>
using namespace std;
#define T pair<long long,long long>
#define x first
#define y second
long long H,W;
bool fn(T a,T b){
	if(a.x>H && b.x>H)return (a.y>b.y);
	if(a.x>H)return true;
	return false;
}
class RectangleCovering{
	public:
	int minimumNumber(int hH,int hW,vector<int>bH,vector<int>bW){
		H=hH;
		W=hW;
		long long i,j,k,n=bH.size(),ans=100;
		T arr[n];
		for(i=0;i<n;i++)arr[i]=T(bH[i],bW[i]);
		for(i=0;i<n;i++){	
			if(arr[i].x>H && arr[i].y>H){
				if(arr[i].x>arr[i].y)swap(arr[i].x,arr[i].y);
			}
			else if(arr[i].x<arr[i].y)swap(arr[i].x,arr[i].y);
		}
		sort(arr,arr+n,fn);
		for(i=0,j=0;i<n && arr[i].x>H && j<W;i++)j+=arr[i].y;
		if(j>=W)ans=min(ans,i);
		swap(H,W);
		for(i=0;i<n;i++){	
			if(arr[i].x>H && arr[i].y>H){
				if(arr[i].x>arr[i].y)swap(arr[i].x,arr[i].y);
			}
			else if(arr[i].x<arr[i].y)swap(arr[i].x,arr[i].y);
		}
		sort(arr,arr+n,fn);
		for(i=0,j=0;i<n && arr[i].x>H && j<W;i++)j+=arr[i].y;
		if(j>=W)ans=min(ans,i);
		if(ans==100)return -1;
		return ans;
	}
};