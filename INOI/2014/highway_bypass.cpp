#include <bits/stdc++.h>
#define MAX 301
using namespace std;
int main(){
	int i,j,k,n,m,arr[MAX][MAX],ans[MAX][MAX][2],d,mod=20011;
	cin>>n>>m>>d;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cin>>arr[i][j];
			ans[i][j][0]=ans[i][j][1]=0;
		}
	}
	ans[0][0][0]=ans[0][0][1]=1;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(arr[i][j]==0)continue;
			for(k=i-1;k>=max(0,i-d)&&arr[k][j]!=0;k--)
				ans[i][j][1]=(ans[i][j][1]+ans[k][j][0])%mod;
			for(k=j-1;k>=max(0,j-d)&&arr[i][k]!=0;k--)
				ans[i][j][0]=(ans[i][j][0]+ans[i][k][1])%mod;
		}
	}
	cout<<(ans[n-1][m-1][0]+ans[n-1][m-1][1])%mod;
	return 0;
}
