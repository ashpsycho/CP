#include <bits/stdc++.h>
using namespace std;
int main(){
	long long t,te,i,j,k,n,m,inp[100001];
	cin>>t;
	string ans;
	for(te=0;te<t;te++){
		cin>>n;
		ans="no";
		for(i=0;i<n;i++)cin>>inp[i];
		j=k=inp[0];
		for(i=1,m=n-1;i<=m;){
			if(inp[i]==(j-1)){
				j--;
				i++;
			}
			else if(inp[i]==(k+1)){
				k++;
				i++;
			}
			else if(inp[m]==(j-1)){
				j--;
				m--;
			}
			else if(inp[m]==(k+1)){
				k++;
				m--;
			}
			else break;
		}
		if(i>m)ans="yesa";
		j=k=inp[n-1];
		for(i=0,m=n-2;i<=m;){
			if(inp[i]==(j-1)){
				j--;
				i++;
			}
			else if(inp[i]==(k+1)){
				k++;
				i++;
			}
			else if(inp[m]==(j-1)){
				j--;
				m--;
			}
			else if(inp[m]==(k+1)){
				k++;
				m--;
			}
			else break;
		}
		if(i>m)ans="yes";
		cout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
	}
	return 0;
}