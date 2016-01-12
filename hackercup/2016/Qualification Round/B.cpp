#include <bits/stdc++.h>
#include <fstream>
#include <stdio.h>
using namespace std;
long long ans=0;
string inp[2];
void cleanse(){
	int i,j,k,n=inp[0].size();
	for(i=0;i<n;i++){
		if(inp[0][i]=='X' || inp[1][i]=='X')continue;
		if(inp[0][i-1]=='X' &&inp[0][i+1]=='X' ){
			ans++;
			inp[1][i]=inp[0][i]='X';
			for(j=i-1;inp[1][j]!='X';j--)inp[1][j]='X';
			for(j=i+1;inp[1][j]!='X';j++)inp[1][j]='X';
			cleanse();
			return;
		}
		if(inp[1][i-1]=='X' &&inp[1][i+1]=='X' ){
			ans++;
			inp[1][i]=inp[0][i]='X';
			for(j=i-1;inp[0][j]!='X';j--)inp[0][j]='X';
			for(j=i+1;inp[0][j]!='X';j++)inp[0][j]='X';
			cleanse();
			return;
		}
	}
	return;
}
int main(){
	long long t,te,i,j,k,n,m;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin>>t;
	for(te=0;te<t;te++){
		fin>>n>>inp[0]>>inp[1];
		inp[0]="X"+inp[0]+"X";
		inp[1]="X"+inp[1]+"X";
		n+=2;
		ans=0;
		cleanse();
		for(i=0;i<n;){
			if(inp[0][i]=='X'){
				i++;
				continue;
			}
			ans++;
			for(j=i+1;j<n && inp[0][j]!='X';j++);
			i=j;
		}
		for(i=0;i<n;){
			if(inp[1][i]=='X'){
				i++;
				continue;
			}
			ans++;
			for(j=i+1;j<n && inp[1][j]!='X';j++);
			i=j;
		}
		fout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
		cout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
	}
	return 0;
}
