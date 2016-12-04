/*
ID: a1lavan1
LANG: C++
TASK: castle
*/
#include <bits/stdc++.h> 
#define T pair<long long,long long>
#define x first
#define y second
#define MAX 101
using namespace std;
int main(){
	ifstream fin("castle.in");
	ofstream fout("castle.out");
	long long i,ans,j,k,n,m,arr[MAX][MAX], vis[MAX][MAX], components = 0,component_sizes[MAX*MAX],p;
	T dir[4]={T(0,-1),T(-1,0),T(0,1),T(1,0)};
	char dirChars[4]={'W','N','E','S'}; 
	fin>>m>>n;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			fin>>arr[i][j];
			vis[i][j]=0;
		}
	}
	// Flood Fill begins
	queue<T> q;
	T node1,node2;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(vis[i][j]!=0)continue;
			components++;
			component_sizes[components-1]=0;
			vis[i][j]=components;
			q.push(T(i,j));
			//BFS Begins
			while(!q.empty()){
				component_sizes[components-1]++;
				node1=q.front();
				q.pop();
				for(k=1,p=0;k<10;k*=2,p++){
					if((arr[node1.x][node1.y] & k))continue;
					node2=T(node1.x+dir[p].x,node1.y + dir[p].y);
					if(vis[node2.x][node2.y]!=0)continue;
					q.push(node2);
					vis[node2.x][node2.y]=components;
				}
			}
			//BFS Ends
		}
	}
	//Flood fill ends
	fout<<components<<"\n";
	//Extract largest component
	for(i=j=0;i<n;i++) j=max(j,component_sizes[i]);
	fout<<j<<"\n";
	//Compute final output
	node1 = T(-1,-1);
	ans=p=0;
	for(j=0;j<m;j++){					//Start from the west
		for(i=n-1;i>=0;i--){			//Start from south
			for(k=1;k<3;k++){			//Check North & East in order
				node2=T(i+dir[k].x,j+dir[k].y);
				if(node2.x<0 || node2.y>=m)continue;
				if(vis[i][j]==vis[node2.x][node2.y])continue;
				if(p>=(component_sizes[vis[i][j]-1] + component_sizes[vis[node2.x][node2.y]-1]))continue;
				p=component_sizes[vis[i][j]-1] + component_sizes[vis[node2.x][node2.y]-1];
				node1=T(i+1,j+1);
				ans=k;		
			}
		}
	}
	//Print Final answer
	fout<<p<<"\n";
	fout<<node1.x<<" "<<node1.y<<" "<<dirChars[ans]<<"\n";
	return 0;
}