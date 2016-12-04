/*
ID: a1lavan1
LANG: C++
TASK: maze1
*/
#include <bits/stdc++.h> 
#define T pair<long long,long long>
#define x first
#define y second
#define MAX 100001
using namespace std;
int i,j,k,n,m,isp[100][38][4],vis[100][100];
T dir[4]={T(-1,0),T(1,0),T(0,-1),T(0,1)};
int bfs( T a){
	T b;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)vis[i][j]=0;
	queue<T> q;
	q.push(a);
	vis[a.x][a.y]=1;
	while(!q.empty()){
		a=q.front();
		q.pop();
		for(i=0;i<4;i++){
			b=T(a.x+dir[i].x,a.y+dir[i].y);
			if(isp[a.x][a.y][i]==0)continue;
			if(b.x>=0 && b.x<n && b.y>=0 && b.y<m){
				if( vis[b.x][b.y]!=0)continue;
				vis[b.x][b.y]=1+vis[a.x][a.y];
			}
			else break;
			q.push(b);
		}
		if(i<4)break;
	}
	return vis[a.x][a.y];
}
int main(){
	ifstream fin("maze1.in");
	ofstream fout("maze1.out");
	int i,ans,j,k;
	fin>>m>>n;
	string inp[201];
	getline(fin,inp[0]);
	for(i=0;i<(2*n+1);i++)getline(fin,inp[i]);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++)
			for(k=0;k<4;k++)
				isp[i][j][k]=(inp[2*i+1+dir[k].x][2*j+1+dir[k].y]==' ')?1:0;
	}
	for(i=0,ans=0000;i<n;i++){
		for(j=0;j<m;j++)
			ans=max(ans,bfs(T(i,j)));
	}
	fout<<ans<<"\n";
	return 0;
}