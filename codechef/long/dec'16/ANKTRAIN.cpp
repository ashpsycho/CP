#include <bits/stdc++.h> 
#define T pair<long long,long long>
#define x first
#define y second
#define ll long long
#define MAX 100001
using namespace std;

string arr[8]={"LB", "MB", "UB", "LB", "MB", "UB", "SL", "SU"};
void f(int n){
	n--;
	if((n%8)<3)n+=3;
	else if((n%8)<6)n-=3;
	else n+=(1-2*(n%2));
	cout<<(n+1)<<arr[(n%8)]<<'\n';
}

int main(){
	ll t,te,i,ans,j,k,n,m;
	cin>>t;
	for(te=0;te<t;te++){
		cin>>j;
		f(j);
	}
	return 0;
}
