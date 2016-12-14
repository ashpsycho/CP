#include <bits/stdc++.h>
using namespace std;

long long po(long long e, long long m){
	if(e<=0)return 1;
	long long b=2,ans=1;
	while(e>0){
		if(e&1)ans=(ans*b)%m;
		e=e>>1;
		b=(b*b)%m;
	}
	return ans; 
}

int main(){
	long long t,te,i,j,k,n,m;
	cin>>n>>m;
	vector<long long>v,ans; 
	for(i=1;(i*i)<=n;i++){
		if((n%i)==0){
			v.push_back(i);
			v.push_back(n/i);
		}
	}
	sort(v.begin(),v.end());
	for(i=0;i<v.size();i++){
		ans.push_back(po(v[i],m));
		for(j=0;j<i;j++){
			if((v[i]%v[j])==0){
				ans[i]=(ans[i]+m-ans[j])%m;
			}
		}
	}
	cout<<ans[v.size()-1]<<"\n";
	return 0;
}