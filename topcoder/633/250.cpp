//int & long long
#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
#define MAX 100001
using namespace std;
class PeriodicJumping{
	public:
	int minimalTime(int x,vector<int> jumps){
		long long i,j,k,n=jumps.size(),ans=0,ma=-1;
		if(x<0)x*=-1;
		if(x==0)return 0;
		for(i=k=0,j=x;i<100;i++){
			j-=jumps[i%n];
			k+=jumps[i%n];
			ma=max(ma,(long long)jumps[i%n]);
			if(j==0)break;
			if(j<0 && (ma-(k-ma))<=x)break;
		}
		if(i<100)return i+1;
		for(i=0,k=0;i<n;i++)k+=jumps[i];
		ans+=((x/k)*n);
		x=(x%k);
		for(i=0;x>0;i++,ans++){
			x-=jumps[i%n];
		}
		return ans;
	}	
};