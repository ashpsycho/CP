#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
#define MAX 100001
using namespace std;
bool fn(T a, T b){
	return (a.x<b.x);
}
class JanuszTheBusinessman{
	public:
	int makeGuestsReturn(vector<int>a , vector<int> d){
		int i,j,k,n=a.size();
		T arr[n];
		int dp[n][2];
		for(i=0;i<n;i++)arr[i]=T(a[i],d[i]);
		sort(arr,arr+n,fn);
		for(i=0;i<n;i++)dp[i][0]=dp[i][1]=100000;
		for(i=0;i<n;i++){
			for(j=i-1;j>=0 && arr[i].x<=arr[j].y;j--);
			if(j==-1)dp[i][1]=1;
			else dp[i][1]=1+dp[j][0];
			for(j=i,k=arr[i].x;j>=0;j--){
				if(arr[j].y>=k){
					dp[i][0]=min(dp[i][0],dp[j][1]);
				}
				k=max(k,arr[j].x);
			}
		}
		return dp[n-1][0];
	}	
};