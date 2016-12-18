#include <bits/stdc++.h> 
using namespace std;
int main(){
	int i,j,n;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)arr[i]=0;
	for(i=1,j=0;i<=n;j=(j+i)%n,i++)arr[j]=1;
	for(i=0;i<n && arr[i]==1;i++);
	if(i<n)cout<<"NO";
	else cout<<"YES";
	return 0;
}