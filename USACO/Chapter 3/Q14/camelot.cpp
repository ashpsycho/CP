/*
ID: a1lavan1
LANG: C++
TASK: camelot
*/
#include <bits/stdc++.h> 
#define T pair<int,int>
#define x first
#define y second
#define MAX 100001
using namespace std;
int i,j,k,dist[30][30][30][30],n,m,vis[30][30];
T dir[8]={T(1,2),T(2,1),T(-1,2),T(-2,1),T(1,-2),T(2,-1),T(-1,-2),T(-2,-1)};

void bfs(T a){
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)vis[i][j]=0;
	vis[a.x][a.y]=1;
	queue<T>q;
	q.push(a);
	T b,c;
	dist[a.x][a.y][a.x][a.y]=0;
	while(!q.empty()){
		c=q.front();
		q.pop();
		for(i=0;i<8;i++){
			b=T(c.x+dir[i].x,c.y+dir[i].y);
			if(b.x<0 || b.y<0 || b.x>=n || b.y>=m||(vis[b.x][b.y]==1))continue;
			q.push(b);
			vis[b.x][b.y]=1;
			dist[b.x][b.y][a.x][a.y]=1+dist[c.x][c.y][a.x][a.y];
		}
	}
}
int kingDist(T king, T b){
	return max(abs(king.x-b.x),abs(king.y-b.y));
}
int main(){
	ifstream fin("camelot.in");
	ofstream fout("camelot.out");
	int i,ans=800*800,j,k,arr[MAX],x,y,z;
	fin>>m>>n;
	string a,b;
	T king;
	vector<T>knight;
	fin>>a>>k;
	king=T(a[0]-'A',k-1);
	for(i=0;i<30;i++)
		for(j=0;j<30;j++)
			for(x=0;x<30;x++)
				for(y=0;y<30;y++)dist[i][j][x][y]=800*800;
	while(fin>>a>>k){
		knight.push_back(T(a[0]-'A',k-1));
	}
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)bfs(T(i,j));
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			k=kingDist(king,T(i,j));
			for(x=0;x<knight.size();x++)
				k+=dist[i][j][knight[x].x][knight[x].y];
			ans=min(ans,k);
			for(x=0;x<knight.size();x++){
				for(y=max(0,king.x-3);y<min(n,king.x+3);y++){
					for(z=max(0,king.y-3);z<min(m,king.y+3);z++){
						ans=min(ans,k-(kingDist(king,T(i,j))+dist[i][j][knight[x].x][knight[x].y])
						+kingDist(king,T(y,z))+dist[knight[x].x][knight[x].y][y][z]+
						dist[y][z][i][j]);
					}
				}
			}
		}
	}
	fout<<ans<<"\n";
	return 0;
}
