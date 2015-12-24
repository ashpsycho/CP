#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
#define MAX 200001
using namespace std;
int main(){
	static int t,te,i,j,k,n,m,ans,arr[MAX];
	string s1="",s=s1;
	vector<string> v;
	while(cin>>s1 && s1!=".")
		v.push_back(s1);

	while(cin>>s1)
		s+=s1;

	for(i=0;i<=s.size();i++)arr[i]=0;
	arr[0]=1;

	for(i=0;i<s.size();i++){
		for(j=0;j<v.size();j++){
			if(v[j].size()>(i+1))continue;
			if(v[j] == s.substr(i+1-v[j].size(),v[j].size()) && arr[i+1-v[j].size()]==1)arr[i+1]=1;
		}
	}
	for(i=s.size();i>=0 && arr[i]==0;i--);
	cout<<i<<"\n";
	return 0;
}