#include <bits/stdc++.h> 
using namespace std;
long long ans=11000000000000L;

void rec(vector<long long> v,string s){
	int n=v.size(),i,j,k;
	vector<long long> v1;
	if(s.size()==0){
		ans=min(ans,v[0]);
		return;
	}
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			v1.clear();
			for(k=0;k<n;k++){
				if(k!=i && k!=j)v1.push_back(v[k]);
			}
			if(s[0]=='+')v1.push_back(v[i]+v[j]);
			else v1.push_back(v[i]*v[j]);
			rec(v1,s.substr(1));
		}
	}
}

int main(){
	long long arr[4],n=4,i,j,k;
	for(i=0;i<n;i++)cin>>arr[i];
	vector<long long>v;
	for(i=0;i<4;i++)v.push_back(arr[i]);
	string inp[3],s="";
	for(i=0;i<3;i++)cin>>inp[i],s+=inp[i];
	rec(v,s);
	cout<<ans<<"\n";
	return 0;
}