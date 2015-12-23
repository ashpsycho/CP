#include <bits/stdc++.h>
#include <fstream>
using namespace std;
int main(){
	long long s,p,t,te,i,j,k,n,m,ans;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin>>t;
	for(te=0;te<t;te++){
		fin>>n>>s>>p;
		vector<int> v;
		for(i=0;i<n;i++){
			fin>>j;
			v.push_back(j);
		}
		sort(v.begin(),v.end());
		reverse(v.begin(),v.end());

		p--;
		ans=0;
		for(i=0;i<n;i++){
			if(((v[i]+1)/3)<p)break;
			if(v[i]>=((3*p)+1))ans++;
			else if(s>0 && p>0){
				s--;
				ans++;
			}
		}

		fout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
		cout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
	}
	return 0;
}