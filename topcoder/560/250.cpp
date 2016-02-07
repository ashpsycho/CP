#include <bits/stdc++.h>
using namespace std;
#define T pair<int,int>
#define x first
#define y second
class TomekPhone{
	public:
	int minKeystrokes(vector<int> f,vector<int> v){
		int ans=0,i,j,n=f.size();
		sort(f.begin(),f.end());
		reverse(f.begin(),f.end());
		vector<int> v1;
		for(i=0;i<v.size();i++){
			for(j=1;j<=v[i];j++)v1.push_back(j);
		}
		sort(v1.begin(),v1.end());
		if(v1.size()<n)return -1;
		for(i=0;i<n;i++)ans=ans+f[i]*v1[i];
		return ans;
	}
};