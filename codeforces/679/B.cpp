#include <bits/stdc++.h> 
using namespace std;
#define MAX 100001
long long i,ans,ans2,j,k,n,m,arr[MAX],calc[MAX],tot[MAX],all=0;
void fillArr(long long n){
	for(i=MAX-1;i>0;i--){
		arr[i]=(n/(i*i*i));
		n=n%(i*i*i);
		all+=arr[i];
	}
	return;
}
int main(){
	cin>>n;
	for(i=2;i<MAX;i++)calc[i-1]=((i*i*i)-1)/((i-1)*(i-1)*(i-1));
	calc[0]=tot[0]=0;
	for(i=1;i<MAX;i++){
		tot[i]=tot[i-1]+(calc[i]*i*i*i);
		calc[i]+=calc[i-1];
	}
	fillArr(n);
	ans=all;
	ans2=n;
	for(i=2,k=0;i<MAX;i++){
		if(arr[i]==0)continue;
		j=(all+calc[i-1]-(k+1));
		m=n+tot[i-1]-(i*i*i);
		if(j>ans && m<n){
			ans=j;
			ans2=m;
		}
		k+=arr[i];
	}
	cout<<ans<<" "<<ans2<<"\n";
	return 0;
}
