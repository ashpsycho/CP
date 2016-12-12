#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
#define MAX 200001
using namespace std;

bool fn(T a, T b){
	return (max(a.x+a.y,b.x+a.y+b.y)<max(a.x+a.y+b.y, b.x+b.y));
}

int main(){
	int i,j,k,n,m,ans=0;
	T arr[MAX];
	cin>>n;
	for(i=0;i<n;i++){
		cin>>j>>k>>m;
		arr[i]=T(k+m,j);
	}
	sort(arr,arr+n,fn);
	for(i=j=0;i<n;i++){
		j+=arr[i].y;
		ans=max(ans,j+arr[i].x);
	}
	cout<<ans<<"\n";
	return 0;
}