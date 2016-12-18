#include <bits/stdc++.h>
using namespace std;
//ERROR: Too many errors,1 logical though for next+=left[i]
void rec(string curr,string left){
	if(left.size()==0){
		cout<<curr<<"\n";
		return;
	}
	string next="";
	for(int j,n,i=0;i<left.size();i++){
		if(i!=0)next+=left[i-1];
		for(j=0;j<i;j++){
			if(left[i]==left[j])break;
		}
		if(j<i)continue;
		rec(curr+left[i],next+left.substr(i+1,n-(i+1)));
	}
}

int main(){
	cout<<"Enter String\n";
	string s;
	cin>>s;
	rec("",s);
	return 0;
}