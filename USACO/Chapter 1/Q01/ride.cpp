/*
ID: a1lavan1
LANG: C++
TASK: ride
*/
#include <bits/stdc++.h> 
#include <fstream>
#define MAX 100001
using namespace std;

long long i,mod=47,j,k,n,m,arr[MAX];

int stringMod(string s){
	for(i=0,j=1;i<s.size();i++){
		j=(j*(s[i]+1-'A'))%mod;
	}
	return j;
}

int main(){
	ifstream fin("ride.in");
	ofstream fout("ride.out");
	string a,b,ans;
	fin>>a>>b;
	n=stringMod(a);
	m=stringMod(b);
	ans=(n==m)?"GO":"STAY";
	fout<<ans<<"\n";
	return 0;
}