#include <bits/stdc++.h>
#define ll long long
#define MAX 200001
using namespace std;
int main(){
	ll i,j,k,n,m,arr[MAX],ans[MAX];
	cin>>n;
	for(i=0;i<n;i++)cin>>arr[i];
	for(i=0;i<n;i++){
		arr[i]+=i;
	}
	arr[0]+=n;
	priority_queue<ll>q;
	for(i=0;i<n;i++)q.push(arr[i]);
	for(i=0;i<n;i++){
		ans[i]=q.top()-i;
		q.push(arr[i+1]+n);
	}
	for(i=n-1;i>=0;i--)cout<<ans[i]<<" ";
	return 0;
}