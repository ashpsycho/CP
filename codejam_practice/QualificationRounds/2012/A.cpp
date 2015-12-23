#include <bits/stdc++.h>
#include <fstream>
using namespace std;
int main(){
	char mapping[26] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
	long long t,te,i,j,k,n,m,ans;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin>>t;
	string s;
	getline(fin,s);
	for(te=0;te<t;te++){
		getline(fin,s);
		string ans = "";
		for(i=0;i<s.size();i++){
			if(s[i]==' ')ans=ans+' ';
			else ans=ans+mapping[s[i]-'a'];
		}
		fout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
		cout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
	}
	return 0;
}
