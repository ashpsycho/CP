#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int fn(int n, int m, int k){
	if(k>=min(n,m))return -1;
	if((2*k+3)>max(n,m))return -1;
	int ans=(min(n,m)+k-1)/k;
	if(min(n,m)>=(3*k) && max(n,m)>=(4*k))ans= min(5,ans);
	return ans;
}

using namespace std;
int main(){
	long long t,te,i,j,k,n,m,ans;
	ofstream fout("output.txt");
	cin>>t;
	for(te=0;te<t;te++){
		cin>>n>>m>>k;
		ans=fn(n,m,k);

		fout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
		cout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
	}
	return 0;
}