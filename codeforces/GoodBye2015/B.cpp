#include <bits/stdc++.h>
using namespace std;
int main(){
	long long t,te,i,j,k,n,m,fin=0,a,b;
	vector<long long> v;
	for(i=2;i<61;i++){
		m=1LL<<i;
		m--;
		for(j=0,k=1;j<(i-1);j++,k*=2LL){
			v.push_back(m-k);
		}
	}
	sort(v.begin(),v.end());
	cin>>a>>b;
	for(i=0;i<v.size();i++){
		if(a>v[i]||b<v[i])continue;
		fin++;
	}
	cout<<fin<<"\n";
	return 0;
}