#include <bits/stdc++.h>
#define ll long long
#define MAX 1000001
using namespace std;
int main(){
	static ll i,ans,j,k,n,m,a[MAX],b[MAX],sum=0;
	cin>>n;
	for(i=0;i<n;i++)scanf("%lld",&a[i]);
	for(i=0;i<n;i++)scanf("%lld",&b[i]);
	ans=a[0];
	for(i=0;i<n;i++)sum+=b[i];
	for(i=0;i<n;i++)ans=max(a[i],ans);
	for(i=1,j=b[0]-a[0],k=b[0];i<n;i++){
		ans=max(ans,a[i]+k-j);
		k+=b[i];
		if((k-a[i])<j)j=k-a[i];
	}
	for(i=1,j=a[0],k=b[0];i<n;i++){
		ans=max(ans,a[i] + (sum-(k+b[i])) + j);
		if((k+a[i])>j)j=k+a[i];	
		k+=b[i];
	}
	cout<<ans;
	return 0;
}