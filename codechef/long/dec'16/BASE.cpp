#include <bits/stdc++.h> 
#define T pair<long long,long long>
#define x first
#define y second
#define ll long long
#define MAX 41
using namespace std;

ll fn(ll n){
	ll lo=(n/2LL)+1, ans=0;
	vector<T> v;
	long double x=1.0;
	for(int i=1;i<MAX;i++){
		v.push_back(T((ll)(ceill(powl(lo,x/(long double)i)-1e-13)), (ll)(floorl(powl(n,x/(long double)i)+1e-13)) ));
	}
	sort(v.begin(),v.end());
	for(int i=1;i<v.size();i++){
		if(v[i].y<=(v[i-1].y) || (v[i].y<v[i].x)){
			v.erase(v.begin()+i);
			i--;
			continue;
		}
		v[i].x=max(v[i].x,v[i-1].y+1);
	}

	for(int i=0;i<v.size();i++){
		ans+=(v[i].y+1-v[i].x);
	}
	return ans;

}

int main(){
	ll t,te,n;
	cin>>t;
	for(te=0;te<t;te++){
		scanf("%lld",&n);
		if(n==1){
			printf("INFINITY\n");
			continue;
		}
		printf("%lld\n", fn(n));
	}
	return 0;
}