#include <bits/stdc++.h>
using namespace std;
int main(){
	int t,te,i,j,k,n,m,ans1[100001],ans2[100001],ans;
	cin>>t;
	string a,b;
	for(te=0;te<t;te++){
		cin>>n>>a>>b;
		for(i=0;i<=n;i++){
			ans1[i]=ans2[i]=0;
		}
		for(i=1,k=1;i<=n;i++){
			if(i>1 && (b[i-1]!=b[i-2]))k++;
			if(a[i-1]==b[i-1]){
				ans1[i]=ans1[i-1];
			}
			else{
				ans1[i]=k;
			}
		}
		reverse(a.begin(),a.end());
		reverse(b.begin(),b.end());
		for(i=1,k=1;i<=n;i++){
			if(i>1 && (b[i-1]!=b[i-2]))k++;
			if(a[i-1]==b[i-1]){
				ans2[i]=ans2[i-1];
			}
			else{
				ans2[i]=k;
			}
		}
		for(i=0,ans=n;i<=n;i++){
			ans=min(ans,max(ans1[i],ans2[n-i]));
		}
		cout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
	}
	return 0;
}