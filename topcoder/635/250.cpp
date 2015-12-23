#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
#define MAX 100001
using namespace std;
class SimilarRatingGraph{
	public:
	double maxLength(vector<int>d,vector<int>r){
		int i,j,k,n=d.size();
		double ans1=0.0,ans2=0.0,ans=0.0;
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				ans1=ans2=0.0;
				for(k=0;(j+k+1)<n;k++){
					if((1LL*(d[i+k]-d[i+k+1])*(d[j]-d[j+1]))!=(1LL*(d[j+k]-d[j+k+1])*(d[i]-d[i+1])))break;
					if((1LL*(r[i+k]-r[i+k+1])*(d[j]-d[j+1]))!=(1LL*(r[j+k]-r[j+k+1])*(d[i]-d[i+1])))break;
					if((1LL*(d[i+k]-d[i+k+1])*(r[j+k]-r[j+k+1]))!=(1LL*(d[j+k]-d[j+k+1])*(r[i+k]-r[i+k+1])))break;
					ans1+=sqrtl((1LL*(d[i+k]-d[i+k+1])*(d[i+k]-d[i+k+1]))+(1LL*(r[i+k]-r[i+k+1])*(r[i+k]-r[i+k+1])));
					ans2+=sqrtl((1LL*(d[j+k]-d[j+k+1])*(d[j+k]-d[j+k+1]))+(1LL*(r[j+k]-r[j+k+1])*(r[j+k]-r[j+k+1])));
				}
				ans=max(ans,max(ans1,ans2));
			}
		}
		return ans;
	}	
};
/*
d(i)-d(i+1), r(i)-r(i+1)
             
d(j)-d(j+1), r(j)-r(j+1)

*/