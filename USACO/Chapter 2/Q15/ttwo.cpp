/*
ID: a1lavan1
LANG: C++
TASK: ttwo
*/
#include <bits/stdc++.h> 
#define T pair<long long,long long>
#define x first
#define y second
using namespace std;
class TT{
public:
	int x,y,z;
	TT(){}
	TT(int x1,int y1,int z1){
		x=x1;
		y=y1;
		z=z1;
	}
};
long long i,ans,j,k,n=10,vis[10][10][4],c1,c2;
string arr[10];
T dir[4]={T(-1,0),T(0,1),T(1,0),T(0,-1)},b;
vector<T> v1,v2;
vector<T> bfs(TT start){
	vector<T> ans;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			for(k=0;k<4;k++)vis[i][j][k]=0;
	}
	while(1){
		if(vis[start.x][start.y][start.z])break;
		vis[start.x][start.y][start.z]=1+ans.size();
		ans.push_back(T(start.x,start.y));
		b=T(start.x+dir[start.z].x,start.y+dir[start.z].y);
		if(b.x<0 || b.y <0 || b.x>=n || b.y>=n || arr[b.x][b.y]=='*')start.z=(start.z+1)%4;
		else{
			start.x=b.x;
			start.y=b.y;
		}
	}
	k=(vis[start.x][start.y][start.z]-1);
	return ans;
}
int main(){
	int i,j;
	ifstream fin("ttwo.in");
	ofstream fout("ttwo.out");
	for(i=0;i<n;i++)fin>>arr[i];
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(arr[i][j]=='C')v1=bfs(TT(i,j,0)),c1=k;
			if(arr[i][j]=='F')v2=bfs(TT(i,j,0)),c2=k;
		}
	}
	for(i=j=k=0;i<(v1.size()*v2.size());i++,j++,k++){
		if(j==v1.size())j=c1;
		if(k==v2.size())k=c2;
		if(v1[j].x == v2[k].x && v1[j].y == v2[k].y)break;
	}
	if(i==(v1.size()*v2.size()))i=0;
	fout<<i<<"\n";
	return 0;
}