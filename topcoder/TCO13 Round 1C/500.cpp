#include <bits/stdc++.h>
using namespace std;
class TheOlympiadInInformatics{
	public:
	int find(vector<int>v,int k){
		long long i,j,n=v.size(),beg=1,mid,end=1000000001;
		sort(v.begin(),v.end());
		while(beg<end){
			mid=(beg+end)/2;
			for(i=j=0;i<n;i++)j+=((1LL*v[i])/(1LL*mid));
			if(j>k)beg=mid+1;
			else end=mid;
		}
		while(j<=k && mid>0){
			for(i=j=0;i<n;i++)j+=(v[i]/mid);
			mid--;
		}
		while(j>k){
			for(i=j=0;i<n;i++)j+=(v[i]/max(1LL,mid));
			if(j<=k)break;
			mid++;	
		}
		if(mid!=0)mid--;
		return mid;
	}
};