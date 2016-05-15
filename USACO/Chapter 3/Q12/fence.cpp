/*
ID: a1lavan1
LANG: C++
TASK: fence
*/
#include <bits/stdc++.h> 
#define MAX 501
using namespace std;
int main(){
	ifstream fin("fence.in");
	ofstream fout("fence.out");
	long long i,j,k,n,m;
	static int adj[MAX][MAX];
	fin>>m;
	for(i=0;i<MAX;i++)
		for(j=0;j<MAX;j++)adj[i][j]=0;
	for(i=0;i<m;i++){
		fin>>j>>k;
		adj[j][k]++;
		adj[k][j]++;
	}
	stack<long long> s;
	vector<int> ans;
	for(i=0;;i++){
		for(j=0;j<MAX;j++)if(adj[i][j])break;
		if(j<MAX)break;
	}
	for(k=0;k<MAX;k++){
		for(j=m=0;j<MAX;j++)m+=adj[k][j];
		if(m&1)break;
	}
	if(k<MAX)i=k;
	s.push(i);
	while(!s.empty()){
		k=s.top();
		for(i=0;i<MAX;i++)if(adj[k][i]>0)break;
		if(i==MAX){
			ans.push_back(k);
			s.pop();
			continue;
		}
		s.push(i);
		adj[k][i]--;
		adj[i][k]--;
	}
	for(i=ans.size()-1;i>=0;i--)fout<<ans[i]<<"\n";
	return 0;
}