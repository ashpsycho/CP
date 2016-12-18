#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
using namespace std;
bool fn(T a, T b){
	return (a.y<b.y);
}

int calcMin(int x,int y, int st){
	int z=(st*y)+(y*(y+1))/2;
	int k=x-z;
	if(k<0 || y==0)return -1;
	z = st + y + ((k+y-1)/y);
	return z;
}

class BaronsAndCoins{
	public:
	int getMaximum(vector<int> x,vector<int> y){
		
		int i,j,k,n=x.size(),ans=0,z;
		T arr[n];
		int dp[n][n+1];
		
		for(i=0;i<n;i++)arr[i]=T(x[i],y[i]);
		sort(arr,arr+n,fn);
		for(i=0;i<n;i++){
			for(j=0;j<=n;j++)dp[i][j]=0;
		}
		for(i=0;i<n;i++){
			dp[i][1]=calcMin(arr[i].x,arr[i].y,0);
			for(j=1;j<=i;j++){
				for(k=j-1;k<i;k++){
					if(dp[k][j]<=0)continue;
					z=calcMin(arr[i].x-arr[k].x,arr[i].y-arr[k].y,dp[k][j]);
					if(z<=0)continue;
					if(dp[i][j+1]<=0 || z<dp[i][j+1] ) dp[i][j+1]=z;
				}
			}
		}
		for(i=0;i<n;i++){
			for(j=1;j<=(i+1);j++)if(dp[i][j]>0)ans=max(ans,j);
		}
		return ans;
	}
};