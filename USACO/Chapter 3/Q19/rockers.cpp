/*
ID: a1lavan1
LANG: C++
TASK: rockers
*/
#include <bits/stdc++.h> 
#define MAX 21
using namespace std;
int main(){
	ifstream fin("rockers.in");
	ofstream fout("rockers.out");
	long long i,ans=0,j,k,n,m,K,arr[MAX],po[MAX],curr;
	po[0]=1;
	for(i=1;i<MAX;i++)po[i]=po[i-1]*2;
	fin>>n>>m>>K;
	for(i=0;i<n;i++)fin>>arr[i];
	vector<long long> v;
	for(i=1;i<po[n];i++){
		v.clear();
		for(j=0;j<n;j++){
			if(i&po[j])v.push_back(arr[j]);
		}
		for(j=0,k=0,curr=0;j<v.size() && k<K;j++){
			if(v[j]<=(m-curr)){
				curr+=v[j];
				continue;
			}
			if(v[j]>m)break;
			curr=v[j];
			k++;
			if(k==K)break;
		}
		if(j==v.size())ans=max(ans,(long long)__builtin_popcount(i));
	}
	fout<<ans<<"\n";
	cout<<ans<<"\n";
	return 0;
}