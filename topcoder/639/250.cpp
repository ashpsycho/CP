#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
#define MAX 100001
using namespace std;
class AliceGame{
	public:
	long long findMinimumValue(long long x, long long y){
		long long i,j,k,n,ans;
		for(i=0;i<2000001;i++)if((i*i)==(x+y))break;
		if(i==2000001)return -1;
		if(x<2)return x;
		if(x==2||y==2)return -1;
		k=2*i-1;
		for(j=k,i=x,ans=0;j>0;j-=2,ans++){
			if(i<j)break;
			i-=j;
		}
		if(i==0)return ans;
		if(i&1)return ans+1;
		return ans+2;
	}	
};