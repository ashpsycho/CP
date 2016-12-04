/*
ID: a1lavan1
LANG: C++
TASK: comehome
*/
#include <bits/stdc++.h> 
#define T pair<char,int>
#define x first
#define y second
using namespace std;
long long adj[500][500];
int main(){
	ifstream fin("comehome.in");
	ofstream fout("comehome.out");
	long long i,ans,j,k,n,m, vis[500], dist[500];
	fin>>m;
	string a,b;
	for(i=0;i<500;i++)
		for(j=0;j<500;j++)adj[i][j]=1000000;
	for(i=0;i<m;i++){
		fin>>a>>b>>j;
		adj[b[0]][a[0]]=adj[a[0]][b[0]]=min(adj[a[0]][b[0]],j);
	}
	for(i=0;i<500;i++)vis[i]=0, dist[i]=1000000;
	for(i=0;i<500;i++)dist[i]=adj['Z'][i];
	dist['Z']=0;
	vis['Z']=1;
	//Djikstra time
	while(1){
		for(i='A',k=499;i<500;i++){
			if(vis[i]==0 && dist[k]>dist[i])k=i;
		}
		vis[k]=1;
		if(k==499)break;
		for(i=0;i<500;i++)dist[i]=min(dist[i],dist[k]+adj[k][i]);
	}
	for(i='A',k=499;i<'Z';i++)
		if(dist[k]>dist[i])k=i;
	fout<<(char)k<<" "<<dist[k]<<"\n";
	return 0;
}