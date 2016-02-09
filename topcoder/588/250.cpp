#include <bits/stdc++.h>
using namespace std;
#define T pair<long long,long long>
#define x first
#define y second
class GUMIAndSongsDiv1{	
	public:
	int maxSongs(vector<int>dur,vector<int> t,int K){
		long long i,j,k,n=t.size(),dp[51][51];
		T arr[n];
		for(i=0;i<n;i++)
			arr[i]=T(t[i],dur[i]);
		sort(arr,arr+n);
		for(i=0;i<51;i++)
			for(j=0;j<51;j++)dp[i][j]=1000LL*K;
		for(i=0;i<n;i++)dp[i][1]=arr[i].y;
		for(i=1;i<n;i++){
			for(j=2;j<=(1+i);j++){
				for(k=j-2;k<i;k++)dp[i][j]=min(dp[i][j],dp[k][j-1]+arr[i].y+arr[i].x-arr[k].x);
			}
		}
		for(i=0,k=0;i<n;i++)
			for(j=1;j<=n;j++)
				if(dp[i][j]<=K)k=max(k,j);
		return k;
	}
};