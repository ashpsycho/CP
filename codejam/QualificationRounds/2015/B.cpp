#include <bits/stdc++.h>
#include <fstream>
#include <stdio.h>
#define T pair<int,int>
#define x first
#define y second
using namespace std;
int main(){
	long long t,te,i,j,k,n,m,ans,arr[1001];
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin>>t;
	for(te=0;te<t;te++){
		fin>>n;
		for(i=0;i<n;i++)fin>>arr[i];
		ans=1001;
		for(i=1001;i>0;i--){
			for(j=k=0;j<n;j++){
				k+=(((arr[j]+i-1)/i)-1);
			}
			ans=min(ans,i+k);
		}
		fout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
		cout<<"Case #"<<(te+1)<<": "<<ans<<"\n";

	}
	return 0;
}
