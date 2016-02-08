#include <bits/stdc++.h>
#define T pair<long long,long long>
#define x first
#define y second
using namespace std;
T fn(vector<int> v){
	long long i,d=0,dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	T init=T(0,0);
	for(i=0;i<v.size();i++){
		init=T(init.x+1LL*v[i]*dir[d][0],init.y+1LL*v[i]*dir[d][1]);
		d=(d+v[i])%4;
	}
	return init;
}
long long abs1(long long n){
	return max(n,n*(-1));
}
class RobotHerb{
	public:
	long long getdist(int t,vector<int> v){
		int i,j,k;
		vector<int> v1;
		for(i=0;i<4;i++)
			for(j=0;j<v.size();j++)v1.push_back(v[j]);
		T ans,a;
		a=fn(v1);
		a=T(a.x*(t/4),a.y*(t/4));
		v1.clear();
		for(i=0;i<(t%4);i++)
			for(j=0;j<v.size();j++)v1.push_back(v[j]);
		ans=fn(v1);
		ans=T(ans.x+a.x,ans.y+a.y);
		return (abs1(ans.x)+abs1(ans.y));
	}
};