#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
#define MAX 2001
using namespace std;
int main(){
	int t,te,i,j,k,n,m,ans=0,q,arr[MAX],brr[MAX],dp[150001];
	cin>>q>>n>>m;
	for(i=0;i<n;i++)cin>>arr[i];
	for(i=0;i<m;i++)cin>>brr[i];
	sort(brr,brr+m);
	sort(arr,arr+n);
	for(i=0;i<(m/2);i++)swap(brr[i],brr[m-(i+1)]);
	for(i=0;i<(n/2);i++)swap(arr[i],arr[n-(i+1)]);
	for(i=0;i<150001;i++)dp[i]=0;
	for(i=j=0;i<n;i++)j+=arr[i];
	if(q>=j){
		ans=j;
		q-=j;
		for(i=0;i<m && q>0;i++){
			if(brr[i]>q)ans+=(q-1);
			else ans+=(brr[i]-1);
			q-=min(q,brr[i]);
		}
	}
	else{
		dp[0]=1;
		for(i=0;i<n;i++){
			for(j=arr[i];j<=q;j++)
				if(dp[j-arr[i]]==1)dp[j]=1;
		}
		for(i=q;i>=0 && dp[i]==0;i--);
		ans=i;
		if(ans<q)ans=q-1;
	}
	cout<<ans<<"\n";
	return 0;
}
