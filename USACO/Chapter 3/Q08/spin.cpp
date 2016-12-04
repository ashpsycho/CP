/*
ID: a1lavan1
LANG: C++
TASK: spin
*/
#include <bits/stdc++.h> 
using namespace std;
int main(){
	ifstream fin("spin.in");
	ofstream fout("spin.out");
	long long i,ans,j,k,n=5,m,a,b;
	int inp[n][360],speed[n],curr[360];
	for(i=0;i<n;i++){
		fin>>speed[i]>>m;
		for(j=0;j<360;j++)inp[i][j]=0;
		for(j=0;j<m;j++){
			fin>>a>>b;
			for(k=0;k<=b;k++)inp[i][(a+k)%360]=1;
		}
	}
	for(i=0;i<360;i++){
		for(j=0;j<360;j++)curr[j]=1;
		for(j=0;j<n;j++){
			for(k=0;k<360;k++)
				curr[(speed[j]*i+k)%360]=curr[(speed[j]*i+k)%360]&inp[j][k];
		}
		for(j=0;j<360 && curr[j]==0;j++);
		if(j<360)break;
	}
	if(i<360)fout<<i<<"\n";
	else fout<<"none\n";
	return 0;
}