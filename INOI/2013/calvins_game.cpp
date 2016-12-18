#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;
int main(){
	static int i,j,k,K,n,m,arr[MAX],ans[MAX][2],fin=-2000000000;
	cin>>n>>K;
	K--;
	for(i=0;i<n;i++)cin>>arr[i],ans[i][0]=ans[i][1]=0;
	ans[0][0]=ans[K][1]=0;
	for(i=1;i<n;i++){
		if(i>1)ans[i][0]=arr[i]+max(ans[i-1][0],ans[i-2][0]);
		else ans[i][0]=ans[i-1][0]+arr[i];
		if(i>K){
			if(i>1)ans[i][1]=arr[i]+max(ans[i-1][1],ans[i-2][1]);
			else ans[i][1]=ans[i-1][1]+arr[i];
		}
		if(i>=K){
			fin=max(fin,ans[i][0]+ans[i][1]+arr[0]-arr[i]);
		}
	}

	cout<<fin<<"\n";
	return 0;
}