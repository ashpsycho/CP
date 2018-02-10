#include <bits/stdc++.h> 
#define T pair<long long,long long>
#define x first
#define y second
#define ll long long
#define MAX 100001
using namespace std;
int main(){
	ll t,te,i,j,k,n,m;
	cin>>t;
	string ans;
	for(te=0;te<t;te++){
		cin >> i >> j >> k;
		ans=((2*j*j)>(k*k))?"Stairs":"Elevator";
		cout<<ans<<"\n";
	}
	return 0;
}