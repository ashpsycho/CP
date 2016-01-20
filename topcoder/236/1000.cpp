#include <bits/stdc++.h>
#include <sstream>
#define T pair<int,int>
#define TT pair<T,int>
#define x first
#define y second
using namespace std;
int rook[202][202],vis[202],par[202];
int maxFlow(int curr){
	int i,j,k;
	queue<int>q;
	for(i=0;i<202;i++)vis[i]=0,par[i]=-1;
	q.push(0);
	vis[0]=1;
	while(!q.empty()){
		j=q.front();
		q.pop();
		for(k=0;k<202;k++){
			if(vis[k]==1||rook[j][k]==0)continue;
			vis[k]=1;
			par[k]=j;
			q.push(k);
		}
	}
	if(vis[201]==0)return curr;
	curr++;
	for(i=201;par[i]!=-1;i=par[i]){
		k=par[i];
		rook[k][i]=0;
		rook[i][k]=1;
	}
	return maxFlow(curr);
}
bool fn(TT a, TT b){
	return (a.y>b.y);
}
class Parking{
	public:
	int minTime(vector<string> g){
		vector<T>cars,park;
		int i,j,k,n=g.size(),m=g[0].size(),vis[n][m],dis[n][m],rook1[202][202];
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(g[i][j]=='C')cars.push_back(T(i,j));
				if(g[i][j]=='P')park.push_back(T(i,j));
			}
		}
		if(cars.size()>park.size())return -1;
		for(i=0;i<202;i++){
			for(j=0;j<202;j++)rook[i][j]=0;
		}
		for(i=1;i<101;i++){
			rook[0][i]=1;
			rook[i+100][201]=1;
		}
		T dir[4]={
			{0,1},
			{0,-1},
			{1,0},
			{-1,0}
		};
		T a,b;
		vector<TT> edge;
		for(i=0;i<cars.size();i++){
			queue<T> q;
			q.push(cars[i]);
			for(j=0;j<n;j++)
				for(k=0;k<m;k++)vis[j][k]=0;
			vis[cars[i].x][cars[i].y]=1;
			dis[cars[i].x][cars[i].y]=0;
			while(!q.empty()){
				a=q.front();
				q.pop();
				for(k=0;k<4;k++){
					b=T(a.x+dir[k].x,a.y+dir[k].y);
					if(b.x<0 || b.y <0 || b.x>=n || b.y>=m)continue;
					if(vis[b.x][b.y]==1 || g[b.x][b.y]=='X')continue;
					vis[b.x][b.y]=1;
					dis[b.x][b.y]=1+dis[a.x][a.y];
					q.push(b);
				}
			}
			for(j=0,k=0;j<park.size();j++){
				if(vis[park[j].x][park[j].y]==0)continue;
				k++;
				rook[i+1][j+101]=1;
				edge.push_back(TT(T(i+1,j+101),dis[park[j].x][park[j].y]));
			}
			if(k==0)return -1;
		}
		for(i=0;i<202;i++)
			for(j=0;j<202;j++)rook1[i][j]=rook[i][j];
		sort(edge.begin(),edge.end(),fn);
		if(cars.size()==0)return 0;
		for(i=0,k=-1;i<edge.size();){
			for(int i1=0;i1<202;i1++)
				for(j=0;j<202;j++)rook[i1][j]=rook1[i1][j];
			for(j=0;j<i;j++)rook[edge[j].x.x][edge[j].x.y]=0;
			j=maxFlow(0);
			cout<<i<<" "<<j<<" "<<edge[i].y<<"\n";
			if(j==cars.size())k=edge[i].y;
			else break;
			for(j=i+1;j<edge.size() && edge[i].y==edge[j].y;j++);
			i=j;
		}
		return k;
		
	}
};