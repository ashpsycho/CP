#include <bits/stdc++.h>
#include <fstream>
#include <stdio.h>
#define T pair<int,int>
#define x first
#define y second
using namespace std;
int getVal(char c){
	switch(c){
		case 'P':
			return 1;
		case 'R':
			return 2;
		case 'S':
			return 4;
	}
}
bool isp(char s[],int n){
	queue<char> q;
	for(int i=0;i<n;i++)q.push(s[i]);
	char a,b;
	int x;
	while(!q.empty()){
		x=0;
		a=q.front();
		q.pop();
		if(q.empty())return true;
		b=q.front();
		q.pop();
		if(a==b)return false;
		x=getVal(a)|getVal(b);
		if(x==3)q.push('P');
		if(x==6)q.push('R');
		if(x==5)q.push('S');
	}
	return true;
}
int main(){
	long long t,te,i,j,k,n,m,p,r,s;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin>>t;
	string ans;
	for(te=0;te<t;te++){
		fin>>n>>r>>p>>s;
		n=(1<<n);
		char curr[n];
		for(i=0;i<p;i++)curr[i]='P';
		for(i=0;i<r;i++)curr[p+i]='R';
		for(i=0;i<s;i++)curr[p+r+i]='S';
		i=0;
		do{
			if(isp(curr,n)){
				i=1;
				break;
			}
		}while(next_permutation(curr,curr+n));
		for(j=0,ans="";j<n;j++)ans=ans+curr[j];
		if(i==0)ans="IMPOSSIBLE";
		fout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
		cout<<"Case #"<<(te+1)<<": "<<ans<<"\n";

	}
	return 0;
}