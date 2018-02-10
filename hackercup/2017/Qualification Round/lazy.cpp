#include <bits/stdc++.h>
#include <fstream>
#include <stdio.h>
#define T pair<int,int>
#define x first
#define y second
using namespace std;
int main(){
	long long t,te,i,j,k,n,m,ans,arr[1001];
	ofstream fout("output.txt");
	cin>>t;
	for(te=0;te<t;te++){
		cin>>n;
		for(i=0;i<n;i++)cin>>arr[i];
		sort(arr,arr+n);
		for(i=1;i<=n;i++){
			for(j=n-1,k=0,m=0;m<i;m++){
				k+=(((49+arr[j])/arr[j])-1);
				if(k>j)break;
				j--;
			}
			if(m<i)break;
		}
		fout<<"Case #"<<(te+1)<<": "<<i-1<<"\n";
		cout<<"Case #"<<(te+1)<<": "<<i-1<<"\n";
	}
	return 0;
}