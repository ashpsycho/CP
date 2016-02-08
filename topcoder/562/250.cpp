#include <bits/stdc++.h>
using namespace std;
vector<char>v;
vector<long long>ans;
void fn(long long T){
	char arr[3001];
	long long i,j,k,x=min(T,51LL);
	for(i=0;i<v.size() && v[i]=='.';i++);
	if(i==v.size())return;
	if(v[i]=='R')ans[0]+=T;
	if(v[i]=='G')ans[1]+=T;
	if(v[i]=='B')ans[2]+=T;
	for(k=0;k<3001;k++)arr[k]='.';
	for(k=0;k<x;k++){
		for(j=0;j<v.size();j++){
			if(v[j]=='.')continue;
			arr[k+j]=v[j];
		}
	}
	for(i=i+x;i<(x+v.size()-1);i++){
		if(arr[i]=='R')ans[0]++;
		if(arr[i]=='G')ans[1]++;
		if(arr[i]=='B')ans[2]++;
	}
}
class PastingPaintingDivOne{
	public:
	vector<long long> countColors(vector<string> g,int T){
		long long i,j,k,n=g.size(),m=g[0].size();
		ans.push_back(0);
		ans.push_back(0);
		ans.push_back(0);
		for(i=0;i<n;i++){
			v.clear();
			for(k=i,j=0;j<m && k<n ;j++,k++)
				v.push_back(g[k][j]);
			fn(T);
		}
		for(j=1;j<m;j++){
			v.clear();
			for(k=j,i=0;k<m && i<n ;i++,k++)
				v.push_back(g[i][k]);
			fn(T);
		}
		return ans;
	}
};