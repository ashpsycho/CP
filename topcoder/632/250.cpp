#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
#define MAX 100001
using namespace std;
int isp(vector<int> v){
	int i,n=v.size();
	vector<int> v1;
	if(n==1)return 1;
	for(i=0;i<n;i+=2){
		if(v[i]!=0)break;
	}
	if(i>=n){
		for(i=1;i<n;i+=2){
			if(v[i]<=0)return 0;
			v1.push_back(v[i]-1);
		}
		return isp(v1);
	}
	for(i=1;i<n;i+=2){
		if(v[i]!=0)break;
	}
	if(i>=n){
		for(i=0;i<n;i+=2){
			if(v[i]<=0)return 0;
			v1.push_back(v[i]-1);
		}
		return isp(v1);
	}
	return 0;
}
class PotentialArithmeticSequence{
	public:
	int numberOfSubsequences(vector<int> d){
		int i,j,k,n=d.size(),ans=0;
		vector<int> v;
		for(i=0;i<n;i++){
			for(j=i;j<n;j++){
				v.clear();
				for(k=i;k<=j;k++)v.push_back(d[k]);
				if(isp(v))ans++;
			}
		}
		return ans;
	}	
};