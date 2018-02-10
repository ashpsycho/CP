#include <bits/stdc++.h> 
#define T pair<long long,long long>
#define x first
#define y second
#define ll long long
#define MAX 100001
using namespace std;
int main(){
	ll t,te,i,ans,j,k,n,m,arr[MAX];
	cin>>n;
	string s;
	for(i=j=0;i<n;i++){
		cin>>k>>s;
		if(j==0 && s[0]!='S')break;
		if(j==20000 && s[0]!='N')break;
		if(s[0]=='E' || s[0]=='W')continue;
		if(s[0]=='N'){
			if(j<k)break;
			j-=k;
		}
		if(s[0]=='S'){
			if((j+k)>20000)break;
			j+=k;
		}
	}
	if(i<n || j!=0)cout<<"NO";
	else cout<<"YES";
	return 0;
}