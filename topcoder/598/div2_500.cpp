#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
#define MAX 100001
using namespace std;

long long mod=1000000007;
class BinPackingEasy{
	public:
	int minBins(vector<int> v){
		int i,j,k,n=v.size(),rem[51];
		sort(v.begin(),v.end());
		reverse(v.begin(),v.end());
		for(i=1;i<=n;i++){
			for(j=0;j<i;j++)rem[j]=300;
			for(j=0;j<n;j++){
				sort(rem,rem+i);
				for(k=0;k<i;k++)if(rem[k]>=v[j])break;
				if(k==i)break;
				rem[k]-=v[j];
			}
			if(j==n)break;
		}	
		return i;
	}	
};