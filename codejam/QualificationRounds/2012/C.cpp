#include <bits/stdc++.h>
#include <fstream>
using namespace std;
string to_str(long long a){
	string ans="";
	while(a>0){
		ans=(char)('0'+(a%10))+ans;
		a=a/10;
	}
	return ans;
}
int to_int(string s){
	long long ans=0;
	for(int i=0;i<s.size();i++){
		ans=ans*10+(s[i]-'0');
	}
	return ans;
}
int main(){
	long long t,te,i,j,k,n,m,ans,a,b;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin>>t;
	set<long long> s2;
	for(te=0;te<t;te++){
		fin>>a>>b;
		ans=0;
		for(i=a;i<b;i++){
			s2.clear();
			string s= to_str(i),s1;
			for(j=s.size()-1;j>0;j--){
				s1=s.substr(j,s.size()-j)+s.substr(0,j);
				m=to_int(s1);
				if(m>i && m<=b){
					s2.insert(m);
				}
			}
			ans+=s2.size();
		}

		fout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
		cout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
	}
	return 0;
}
