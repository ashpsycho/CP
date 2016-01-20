#include <bits/stdc++.h>
#define T pair<long long,long long>
#define x first
#define y second
using namespace std;
vector<T> v;
bool isp(long long k,long long m){
	int i,j,n=v.size(),ans=0,now=0;
	for(i=0;i<n;){
		ans++;
		for(j=i;j<n &&(v[i].y-v[j].y)<=k;j++){
			now=j;
		}
		for(j=now+1;j<n &&(v[j].x-v[now].x)<=k;j++);
		i=j;
	}
	return (ans<=m);
}
class TheEmpireStrikesBack{
	public:
	int find(int ax,int bx,int cx,int ay,int by,int cy,int n,int m){
		long long i,j,k,mod=1000000007;
		T a;
		vector<T> v1;
		a=T(ax,ay);
		for(i=0;i<n;i++){
			v1.push_back(a);
			a=T((a.x*bx+1LL*cx)%mod,(a.y*by+1LL*cy)%mod);
		}
		sort(v1.begin(),v1.end());
		for(i=n-1,k=-1;i>=0;i--){
			if(v1[i].y<=k)continue;
			v.push_back(v1[i]);
			k=v1[i].y;
		}
		reverse(v.begin(),v.end());
		for(i=0,j=mod;i<j;){
			k=i+(j-i)/2;
			if(isp(k,m)==1)
				j=k;
			else
				i=k+1;
		}
		return i;
	}
};