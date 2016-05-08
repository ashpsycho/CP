/*
ID: a1lavan1
LANG: C++
TASK: palsquare
*/
#include <bits/stdc++.h> 
#include <fstream>
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
	ifstream fin("palsquare.in");
	ofstream fout("palsquare.out");
	long long i,ans,j,k,n,m;
	fin>>n;
	for(i=1;i<=300;i++){
		if(isPalin(toBase(n,i*i)))fout<<toBase(n,i)<<" "<<toBase(n,i*i)<<"\n";
	}
	return 0;
}