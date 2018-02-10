#include <bits/stdc++.h> 
#define T pair<long long,long long>
#define x first
#define y second
#define ll long long
#define MAX 100001
using namespace std;
int main(){
	ll t,te,i,ans,j,k,n,x,y;
	cin>>t;
	for(te=0;te<t;te++){
		cin>>i>>j>>k;
		if(j>k)swap(j,k);
		x = k-j;
		y = i-x;
		if(x==y)ans=0;
		else ans= min(x,y)-1;
		cout<<ans<<"\n";
	}
	return 0;
}