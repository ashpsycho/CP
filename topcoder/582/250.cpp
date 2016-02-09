#include <bits/stdc++.h>
#define T pair<int,long long>
#define x first
#define y second
using namespace std;
class SpaceWarDiv1{
	public:
	long long minimalFatigue(vector<int> v,vector<int> es,vector<long long> ec){
		long long i,j,k,x,lo=0,hi=100000000LL*100000000LL,mid,n=v.size(),m=es.size();
		T arr[m];
		for(i=0;i<m;i++)arr[i]=T(es[i],ec[i]);
		sort(arr,arr+m);
		reverse(arr,arr+m);
		sort(v.begin(),v.end());
		reverse(v.begin(),v.end());
		if(v[0]<arr[0].x)return -1;
		while (lo < hi){
    		mid = lo + (hi-lo)/2LL;
    		for(i=j=0,k=mid,x=arr[0].y;i<n && j<m;){
    			if(v[i]<arr[j].x)break;
    			if(k<x){
    				x-=k;
    				k=mid;
    				i++;
    			}
    			else{
    				k-=x;
    				j++;
    				if(j<m)x=arr[j].y;
    			}
    		}
	      	if (j==m)
         		hi = mid;
      		else
        		lo = mid+1; 
        } 
  		return lo;	
	}
};