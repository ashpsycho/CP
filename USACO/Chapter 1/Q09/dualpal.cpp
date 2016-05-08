/*
ID: a1lavan1
LANG: C++
TASK: dualpal
*/
#include <bits/stdc++.h>
using namespace std;
bool isPalin(string s){
	for(int i=0,n=s.size();i<(n/2);i++)
		if(s[i]!=s[n-(i+1)])return false;
	return true;
}
string toBase(int base,int num){
	string ans="";
	char all[20]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};
	while(num>0){
		ans=all[num%base]+ans;
		num/=base;
	}
	return ans;
}
int main(){
	ifstream fin("dualpal.in");
	ofstream fout("dualpal.out");
	long long i,ans,j,k,n,m;
	fin>>n>>m;
	while(n>0){
		m++;
		for(i=2,j=0;i<11;i++)if(isPalin(toBase(i,m)))j++;
		if(j>1){
			fout<<m<<"\n";
			n--;
		}
	}
	return 0;
}