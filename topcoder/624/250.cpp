#include <bits/stdc++.h>
using namespace std;
class BuildingHeights{
	public:
	int minimum(vector<int>v){
		static int i,j,k,n=v.size(),arr[4000][4001],ans[4001];
		for(i=0;i<n;i++){
			for(j=0;j<=n;j++)arr[i][j]=0,ans[j]=16000001;
		}
		sort(v.begin(),v.end());
		for(i=0;i<n;i++){
			for(j=1,k=i;j<=(i+1);k--,j++){
				arr[i][j]=arr[i][j-1]+(v[i]-v[k]);
				ans[j]=min(ans[j],arr[i][j]);
			}
		}
		for(i=1,j=0;i<=n;i++)j=j^ans[i];
		return j;
	}
};