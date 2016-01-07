#include <bits/stdc++.h>
#include <fstream>
#include <stdio.h>
#define T pair<int,int>
#define x first
#define y second
using namespace std;
int main(){
	long long t,te,i,j,k,n,m,ans;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin>>t;
	string s;
	for(te=0;te<t;te++){
		fin>>n>>s;
		ans=i=k=0;
		while(i<=n){
			for(;i<=k && i<=n;i++){
				k+=(s[i]-'0');	
			}
			for(;k<n && s[k]=='0';k++,ans++);

		}
		cout<<ans<<"\n";
		fout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
		cout<<"Case #"<<(te+1)<<": "<<ans<<"\n";

	}
	return 0;
}
