/*
ID: a1lavan1
LANG: C++
TASK: preface
*/
#include <bits/stdc++.h> 
#define T pair<long long,long long>
#define x first
#define y second
#define MAX 100001
using namespace std;

// I= 1, V =5, X=10, L= 50, C= 100, D=500, M= 1000
string roman[7]={"I","V","X","L","C","D","M"};

string getRomanNumber(int n){
	int i,j,k,po;
	vector<int> calc[10];
	calc[1].push_back(0);
	calc[2].push_back(0);
	calc[2].push_back(0);
	calc[3].push_back(0);
	calc[3].push_back(0);
	calc[3].push_back(0);
	calc[4].push_back(0);
	calc[4].push_back(1);
	calc[5].push_back(1);
	calc[6].push_back(1);
	calc[7].push_back(1);
	calc[8].push_back(1);
	calc[6].push_back(0);
	calc[7].push_back(0);
	calc[7].push_back(0);
	calc[8].push_back(0);
	calc[8].push_back(0);
	calc[8].push_back(0);
	calc[9].push_back(0);
	calc[9].push_back(2);
	string ans="", temp="";
	for(po=0;n>0;po++, n/=10){
		k=(n%10);
		temp="";
		for(i=0;i<calc[k].size();i++){
			temp+=roman[po*2+calc[k][i]];
		}
		ans=temp+ans;
	}
	return ans;
}
int main(){
	ifstream fin("preface.in");
	ofstream fout("preface.out");
	long long i,ans,j,k,n,arr[MAX];
	fin>>n;
	map<char,int>m ;
	string s;
	for(i=1;i<=n;i++){
		s=getRomanNumber(i);
		for(j=0;j<s.size();j++)m[s[j]]++;
	};
	for(i=0;i<7;++i){
		if(m[roman[i][0]]>0)fout<<roman[i]<<" "<<m[roman[i][0]]<<"\n";
	}
	return 0;
}