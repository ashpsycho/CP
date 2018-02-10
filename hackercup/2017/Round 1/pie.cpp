#include <bits/stdc++.h>
#include <fstream>
using namespace std;
int main(){
	long long t,te,i,j,k,n,m,M,ans,arr[301][301],curr[301];
	ofstream fout("output.txt");
	cin>>t;
	for(te=0;te<t;te++){
		cin>>n>>M;
		for(i=0;i<n;i++){
			for(j=0;j<M;j++){
				cin>>arr[i][j];
			}
			sort(arr[i],arr[i]+M);
		}
		ans=0;
		for(i=0;i<n;i++)curr[i]=0;
		for(i=0;i<n;i++){
			for(j=0,k=-1,m=100000000;j<=i;j++){
				if(curr[j]==M)continue;
				if(m>(arr[j][curr[j]]+(1+2*curr[j]))){
					m=arr[j][curr[j]]+(1+2*curr[j]);
					k=j;
				}
			}
			ans+=m;
			curr[k]++;
		}
		fout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
		cout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
	}
	return 0;
}