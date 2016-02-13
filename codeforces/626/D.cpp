#include <bits/stdc++.h>
using namespace std;
int main(){
	int i,j,k,n,m,x,y,inp[2001];
	long double p1[5001],p2[10001],p2sum[10001],ans=0.0,sum=0;
	cin>>n;
	for(i=0;i<n;i++)cin>>inp[i];
	sort(inp,inp+n);
	if(inp[n-1]>5000)for(i=0;;i++);
	for(i=0;i<5001;i++)p1[i]=0;
	for(i=0;i<10001;i++)p2[i]=p2sum[i]=0;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			sum+=1.0;
			p1[inp[j]-inp[i]]+=1.0;
		}
	}
	for(i=0;i<5001;i++)p1[i]/=sum;
	for(i=0;i<5001;i++){
		for(j=0;j<5001;j++)p2[i+j]+=(p1[i]*p1[j]);
	}
	for(i=0;i<10001;i++)p2sum[i]=p2[i];
	for(i=1;i<10001;i++)p2sum[i]+=p2sum[i-1];
	for(i=1;i<5001;i++){
		p1[i]*=sum;
		for(j=0;j<i;j++)ans+=(p1[i]*p2[j]);
	}
	ans/=sum;
	cout<<ans<<"\n";
	return 0;
}