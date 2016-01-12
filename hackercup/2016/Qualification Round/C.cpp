#include <bits/stdc++.h>
#include <fstream>
using namespace std;
int main(){
	static long long t,te,i,j,k,n,m,ans,arr[100001],sum[100001];
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin>>t;
	for(te=0;te<t;te++){
		fin>>n>>m;
		ans=0;
		for(i=0;i<n;i++)fin>>arr[i],sum[i+1]=arr[i];
		sum[0]=0;
		for(i=1;i<=n;i++)sum[i]+=sum[i-1];
		for(i=0,j=1;j<=n;j++){
			while((i<j) && (sum[j]-sum[i])>m)i++;
			ans+=(j-i);
		}
		fout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
		cout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
	}
	return 0;
}