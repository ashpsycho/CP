#include <bits/stdc++.h>
using namespace std;
int a[100001],b[100001],inp[100001],ans[100001];
void calc(int n,int m){
	int i,j;
	while(m>0){
		if(m&1){
			for(i=0;i<n;i++)ans[i]=a[ans[i]];
		}
		for(i=0;i<n;i++)b[i]=a[a[i]];
		for(i=0;i<n;i++)a[i]=b[i];
		m/=2;
	}
}
int main(){
	int n,k,m,i;
	cin>>n>>k>>m;
	for(i=0;i<n;i++)scanf("%d",&inp[i]);
	for(i=0;i<k;i++)ans[i]=i;
	for(i=0;i<k;i++)scanf("%d",&a[i]),a[i]--;
	calc(k,m);
	for(i=0;i<n;i++)printf("%d ",ans[inp[i]]);
	printf("\n");
	return 0;
}