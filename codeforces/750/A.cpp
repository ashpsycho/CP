#include <bits/stdc++.h> 
using namespace std;
int main(){
	int t,te,i,ans,j,k,n,m,arr[MAX];
	cin>>n>>k;
	for(i=j=0;(j+(5*(i+1))+k)<=240 && i<n;i++,j+=(5*i));
	cout<<i;
	return 0;
}