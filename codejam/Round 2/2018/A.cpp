#include <bits/stdc++.h>
using namespace std;
int inp[1001],n;
char layout[1001][101];

int calc(){
	if(inp[0]==0 || inp[n-1]==0)return -1;
	int i,j,k,ans=1,m;
	for(i=j=0;i<n;i++)j+=inp[i];
	if(j!=n)return -1;
	int pos[101];
	for(i=j=0;i<n;i++){
		for(k=0;k<inp[i];k++){
			pos[j+k]=i;
			ans=max(ans,1+abs(j+k-i));
		}
		j+=inp[i];
	}
	for(i=0;i<ans;i++){
		for(j=0;j<n;j++)layout[i][j]='.';
	}
	for(i=0;i<n;i++){
		if(pos[i]<i)k=-1;
		else k=1;
		for(j=i,m=0;j!=pos[i];j+=k,m++){
			layout[m][j]=(k==1)?'\\':'/';
		}
	}
	return ans;
}

int main(){
	long long t,te,i,j,k,ans;
	cin>>t;
	for(te=0;te<t;te++){
		cin>>n;
		for(i=0;i<n;i++)cin>>inp[i];
		ans = calc();
		if(ans==-1){
			cout<<"Case #"<<(te+1)<<": IMPOSSIBLE\n";	
			continue;
		}
		cout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
		for(i=0;i<ans;i++){
			for(j=0;j<n;j++)cout<<layout[i][j];
			cout<<"\n";
		}
	}
	return 0;
}