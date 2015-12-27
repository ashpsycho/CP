#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
#define MAX 100001
using namespace std;
int main(){
	int te,t=5,i,j,k,n,m,ans,arr[5][5],po,x,y,z;
	string inp[5];
	vector<T>neigh[5][5];
	int crypt[5][5];
	T decrypt[25];
	T a,b,dir[4]={T(0,1),T(0,-1),T(1,0),T(-1,0)};
	for(te=0;te<t;te++){
		cin>>n>>m;
		for(i=0;i<n;i++)cin>>inp[i];
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				neigh[i][j].clear();
				neigh[i][j].push_back(T(i,j));
				crypt[i][j]=(i*m)+j;
				decrypt[(i*m)+j]=T(i,j);
			}
		}
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				a=T(i,j);
				for(k=0;k<4;k++){
					b=T(a.x+dir[k].x,a.y+dir[k].y);
					if( b.x<0 || b.y<0 || b.y>=m || b.x>=m )continue;
					neigh[i][j].push_back(b);
				}
			}
		}
		for(i=0;i<=(n*m);i++){
			for(j=0,po=(1<<(n*m));j<po;j++){
				if(__builtin_popcount(j)!=i)continue;
				for(x=0;x<n;x++)
					for(y=0;y<m;y++)arr[x][y]=inp[x][y]-'0';
				for(y=0,z=1;z<po;z*=2,y++){
					if((z&j)){
						a=decrypt[y];
						for(x=0;x<neigh[a.x][a.y].size();x++)
							arr[neigh[a.x][a.y][x].x][neigh[a.x][a.y][x].y]^=1;
					}
				}
				for(x=0;x<n;x++){
					for(y=0;y<m;y++)if(arr[x][y]==1)break;
					if(y<m)break;
				}
				if(x==n)break;
			}
			if(j<po)break;
		}
		if(i<=(n*m))cout<<i<<"\n";
		else cout<<"-1\n";
	}
	return 0;
}