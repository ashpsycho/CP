/*
ID: a1lavan1
LANG: C++
TASK: heritage
*/
#include <bits/stdc++.h>
#define MAX 100001
using namespace std;
string ans="";
char LEFT[500],RIGHT[500];
void post(char c){
	if(c==127)return;
	post(LEFT[c]);
	post(RIGHT[c]);
	ans=ans+c;
}
char create(string infix, string prefix){
	if(infix=="")return 127;
	int i,n=infix.size();
	for(i=0;i<infix.size();i++)if(infix[i]==prefix[0])break;
	LEFT[prefix[0]]=create(infix.substr(0,i),prefix.substr(1,i));
	RIGHT[prefix[0]]=create(infix.substr(i+1,n-(i+1)),prefix.substr(i+1,n-(i+1)));
	return prefix[0];
}
int main(){
	ifstream fin("heritage.in");
	ofstream fout("heritage.out");
	long long i,j,k,n,m;
	string in,pre;
	fin>>in>>pre;
	for(i=0;i<500;i++)LEFT[i]=RIGHT[i]=127;
	char head=create(in,pre);
	post(head);
	fout<<ans<<"\n";
	return 0;
}