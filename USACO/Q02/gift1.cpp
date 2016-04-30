/*
ID: a1lavan1
LANG: C++
TASK: gift1
*/
#include <bits/stdc++.h> 
#include <fstream>
#define MAX 100001
using namespace std;
int main(){
	ifstream fin("gift1.in");
	ofstream fout("gift1.out");
	long long i,ans,j,k,n;
	string arr[MAX];
	fin>>n;
	string inp;
	map<string, int> m;
	for(i=0;i<n;i++){
		fin>>inp;
		arr[i]=inp;
		m[inp]=0;
	}
	for(i=0;i<n;i++){
		fin>>inp;
		fin>>j>>k;
		if(k!=0)j-=(j%k);
		m[inp]-=j;
		if(k!=0)j/=k;
		while(k--){
			fin>>inp;
			m[inp]+=j;
		}
	}
	for(i=0;i<n;i++){
		fout<<arr[i]<<" "<<m[arr[i]]<<"\n";
	}
	return 0;
}