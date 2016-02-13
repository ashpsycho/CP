#include <bits/stdc++.h>
#define T pair<int,char>
#define x first
#define y second
using namespace std;
int main(){
	string s,ans="";
	int i,j,k,n,x,y;
	cin>>n>>s;
	sort(s.begin(),s.end());
	vector<T> v;
	for(i=0;i<n;){
		for(j=i+1;j<n && s[j]==s[i];j++);
		v.push_back(j-i,s[i]);
		i=j;
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	if(v.size()==1){
		ans=ans+v[0].y;
	}
	else if(v.size()==2){
		if(v[1].x>1)ans="BGR";
		else if(v[1].x==1 && v[0].x==1)ans=ans+(char)('R'+'G'+'B'-v[0].y-v[1].y);
		else{
			if(v[0].y=='R')ans="BG";
			else if(v[0].y=='G')ans="BR";
			else ans="GR";
		}
	}
	else ans="BGR";
	cout<<ans<<"\n";
	return 0;
}
