#include <bits/stdc++.h>
using namespace std;
//ERROR: Too many errors,1 logical though for next+=left[i]
void rec(int n,string curr,string left){
	if(n==0){
		cout<<curr<<"\n";
		return;
	}
	string next="";
	for(int j,i=0;i<left.size();i++){
		if(i!=0)next+=left[i-1];
		for(j=0;j<i;j++){
			if(left[i]==left[j])break;
		}
		if(j<i)continue;
		rec(n-1,curr+left[i],next+left.substr(i+1,left.size()-(i+1)));
	}
}

int main(){
	cout<<"Enter String\n";
	string s;
	int n=-1;
	cin>>s;
	while(n>s.size() || n<0){
		cout<<"Enter length\n";
		cin>>n;
	}
	rec(n,"",s);
	return 0;
}