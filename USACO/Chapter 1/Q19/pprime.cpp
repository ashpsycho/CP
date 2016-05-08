/*
ID: a1lavan1
LANG: C++
TASK: pprime
*/
#include <bits/stdc++.h> 
using namespace std;

int stringToInt(string s){
	stringstream fin;
	fin<<s;
	int n;
	fin>>n;
	return n;
}

string intToString(int s){
	stringstream fin;
	fin<<s;
	string n;
	fin>>n;
	return n;
}

bool isPalin(string s){
	for(int i=0,n=s.size();i<(n/2);i++)
		if(s[i]!=s[n-(i+1)])return false;
	return true;
}

bool isPrime(int n){
	int i;
	for( i=2;(i*i)<=n;i++)if((n%i)==0)break;
	return ((i*i)>n);
}

vector<int> pprimes;
void generatePalin(int len){
	string curr;
	int i,j,k,m=pow(10,(len+1)/2);
	for(i=pow(10,(len-1)/2);i<m;i++){
		curr=intToString(i);
		for(j=curr.size()-(1+(len%2));j>=0;j--)curr+=curr[j];
		k=stringToInt(curr);
		if(isPrime(k))pprimes.push_back(k);
	}
}

int main(){
	ifstream fin("pprime.in");
	ofstream fout("pprime.out");
	long long i,ans,j,k,n,m,arr[MAX];
	fin>>n>>m;
	for(i=1;i<9;i++)generatePalin(i);
	for(i=0;i<pprimes.size();i++)if(pprimes[i]>=n && pprimes[i]<=m)fout<<pprimes[i]<<"\n";
	return 0;
}