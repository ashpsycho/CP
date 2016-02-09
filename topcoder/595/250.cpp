#include <bits/stdc++.h>
using namespace std;
class LittleElephantAndIntervalsDiv1{
	public:
	long long getNumber(int M,vector<int> L,vector<int> R){
		int i,j,k,n=L.size(),arr[M];
		for(i=0;i<M;i++)arr[i]=-1;
		for(i=0;i<n;i++){
			for(j=L[i]-1;j<R[i];j++)arr[j]=i;
		}
		set<int>s;
		for(k=0;k<M;k++)if(arr[k]!=-1)s.insert(arr[k]);
		return (1LL<<s.size());
	}
};