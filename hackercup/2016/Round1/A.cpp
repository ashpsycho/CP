#include <bits/stdc++.h>
#include <fstream>
using namespace std;
int main(){
	static long long t,te,i,j,k,n,m,ans,arr[100001];
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin>>t;
	for(te=0;te<t;te++){
		fin>>n;
		ans=0;
		for(i=0;i<n;i++)fin>>arr[i];
		for(i=0;i<n;){
			for(j=i+1,k=1,m=arr[i];k<4;k++){
				if(j==n)break;
				if(arr[j]<=m)break;
				if((arr[j]-m)<=10){
					m=arr[j];
					j++;
				}
				else
					m+=10;
			}
			i=j;
			ans++;
		}
		ans=(ans*4)-n;
		fout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
		cout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
	}
	return 0;
}
