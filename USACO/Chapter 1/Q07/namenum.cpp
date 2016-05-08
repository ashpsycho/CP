/*
ID: a1lavan1
LANG: C++
TASK: namenum
*/
#include <bits/stdc++.h> 
#include <fstream>
#define MAX 100001
using namespace std;
int main(){
	ifstream fin("namenum.in");
	ifstream fin1("dict.txt");
	ofstream fout("namenum.out");
	long long i,ans=0,j,k,n,m;
	char arr[8][3]={{'A','B','C'},{'D','E','F'},{'G','H','I'},{'J','K','L'},{'M','N','O'},{'P','R','S'},{'T','U','V'},{'W','X','Y'}};
	string s,inp,curr;
	fin>>s;
	n=s.size();
	for(i=0;i<n;i++)curr+=" ";
	set<string> words;
	while(fin1>>inp)words.insert(inp);
	for(i=0,m=(int)powl(3,n);i<m;i++){
		for(j=n-1,k=i;j>=0;j--,k/=3){
			curr[j]=arr[s[j]-'2'][k%3];
		}
		if(words.find(curr)!=(words.end()))fout<<curr<<"\n",ans++;
	}
	if(ans==0)fout<<"NONE\n";
	return 0;
}               