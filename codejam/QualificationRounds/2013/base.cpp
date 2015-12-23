#include <bits/stdc++.h>
#include <fstream>
using namespace std;
int main(){
	long long t,te,i,j,k,n,m,ans;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin>>t;
	for(te=0;te<t;te++){
		fin>>n;
		

		fout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
		cout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
	}
	return 0;
}