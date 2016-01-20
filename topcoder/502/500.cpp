#include <bits/stdc++.h>
using namespace std;
class T{
	public:
	long long t,ppm,mp;
	T(){}
	T(long long a,long long b,long long c){
		mp=a;
		ppm=b;
		t=c;
	}
};
bool fn(T a,T b){
	return (a.t*b.ppm)<(b.t*a.ppm);
}
class TheProgrammingContestDivOne{
	public:
	int find(int tot,vector<int>mp,vector<int>ppm,vector<int> t){
		long long i,j,n=mp.size();
		vector<T> v;
		for(i=0;i<n;i++){
			v.push_back(T(mp[i],ppm[i],t[i]));
		}
		sort(v.begin(),v.end(),fn);
		static long long dp[100001];
		for(i=0;i<=tot;i++)dp[i]=0;
		for(i=0;i<n;i++){
			for(j=tot;j>=v[i].t;j--){
				dp[j]=max(dp[j],dp[j-v[i].t]+v[i].mp-(j*v[i].ppm));
			}
			for(j=1;j<=tot;j++)dp[j]=max(dp[j],dp[j-1]);
		}
		return dp[tot];
	}
};