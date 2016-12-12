#include <bits/stdc++.h>
#define MAX 231
using namespace std;
int main(){
	int i,j,k,n,m,ans,arr[MAX][MAX];
	cin>>n>>m;
	for(i=0;i<n;i++){
		arr[i][i]=0;
		for(j=0;j<n;j++)if(j!=i)arr[i][j]=1000000000;
	}
	for(i=0;i<m;i++){
		cin>>j>>k>>ans;
		arr[j-1][k-1]=arr[k-1][j-1]=ans;
	}
	for(k=0;k<n;k++){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(arr[i][j]>(arr[i][k]+arr[k][j])){
					arr[i][j]=arr[i][k]+arr[k][j];
				}
			}
		}
	}
	ans=-1;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)ans=max(ans, arr[i][j]);
	}
	cout<<ans<<"\n";
	return 0;
}