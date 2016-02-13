#include <bits/stdc++.h>
using namespace std;
class MinimumSquare{
	public:
	long long minArea(vector<int>x,vector<int> y,int K){
		long long i,j,k,y1,y2,n=x.size(),ans=5000000000000000001LL,curr;
		vector<long long>v;
		for(i=0;i<n;i++){
			for(j=i;j<n;j++){
				y1=min(y[i],y[j])-1;
				y2=max(y[i],y[j])+1;
				v.clear();
				for(k=0;k<n;k++){
					if(y[k]>y1 && y[k]<y2)v.push_back(x[k]);
				}
				if(v.size()<K)continue;
				sort(v.begin(),v.end());
				curr=30000000001LL;
				for(k=K-1;k<v.size();k++)curr=min(curr,v[k]+2-v[k-(K-1)]);
				curr=max(curr,y2-y1);
				ans=min(ans,curr*curr);
			}
		}
		return ans;
	}
};