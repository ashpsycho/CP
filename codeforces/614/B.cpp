#include <bits/stdc++.h>
using namespace std;
int main(){
	int i,j,k,n;
	cin>>n;
	vector<string> v;
	string s;
	for(i=k=0;i<n;i++){
		cin>>s;
		v.push_back(s);
		if(s=="0")k++;
	}
	if(k>0){
		cout<<"0\n";
		return 0;
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	cout<<v[0];
	char ans[100001];
	for(i=1,j=0;i<n;i++){
		j+=(v[i].size()-1);
	}
	for(i=0;i<j;i++)ans[i]='0';
	ans[i]='\0';
	cout<<ans<<"\n";
	return 0;
}
