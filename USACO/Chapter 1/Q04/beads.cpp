/*
ID: a1lavan1
LANG: C++
TASK: beads
*/
#include <bits/stdc++.h> 
#include <fstream>
#define MAX 100001
using namespace std;
string s;
int n, i, ans=0;
int fn(int st,int d){
	int x=0,ans=0;
	while(ans<n){
		if(s[st]=='r')x=x|1;
		if(s[st]=='b')x=x|2;
		if(x==3)return ans;
		st=(st+d)%n;
		ans++;
	}
	return ans;
}
int main(){
	ifstream fin("beads.in");
	ofstream fout("beads.out");
	fin>>n;
	fin>>s;
	for(i=0;i<n;i++){
		ans=max(ans,min(n,fn(i,n-1)+fn((i+1)%n,1)));
	}
	fout<<ans<<"\n";
	return 0;
}