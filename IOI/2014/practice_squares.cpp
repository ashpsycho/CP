#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
#define MAX 1001
using namespace std;
int main(){
	static int t,te,i,j,k,n,m,ans,arr[MAX][MAX],sum[MAX][MAX];
	cin>>n;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			cin>>arr[i][j];
			sum[i][j]=arr[i][j];
		}

	for(i=1;i<n;i++){
		sum[i][0]+=sum[i-1][0];
		sum[0][i]+=sum[0][i-1];
	}
	for(i=1;i<n;i++)
		for(j=1;j<n;j++)
			sum[i][j]-=(sum[i-1][j-1]-(sum[i-1][j]+sum[i][j-1]));

	for(i=n;i>0;i--){
		for(j=ans=0;(j+i)<=n;j++){
			for(k=0;(k+i)<=n;k++){
				if(j==0 && k==0){
					if(sum[i-1][i-1]==0)ans++;
				}
				else if(j==0){
					if((sum[i-1][i+k-1]-sum[i-1][k-1])==(n*n))ans++;
				}
				else if(k==0){
					if((sum[i+j-1][i-1]-sum[j-1][i-1])==(n*n))ans++;
				}
				else{
					if((sum[i+j-1][i+k-1]+sum[j-1][k-1])==(n*n+sum[i+j-1][k-1]+sum[j-1][i+k-1]))ans++;
				}
			}
		}
		if(ans)break;
	}
	cout<<ans*n*n<<"\n";
	return 0;
}