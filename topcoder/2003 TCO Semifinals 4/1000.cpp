#include <bits/stdc++.h>
#include <sstream>
#define T pair<int,int>
#define x first
#define y second
using namespace std;
int rook[602][602],vis[602],par[602];
int maxFlow(int curr){
	int i,j,k;
	queue<int>q;
	for(i=0;i<602;i++)vis[i]=0,par[i]=-1;
	q.push(0);
	vis[0]=1;
	while(!q.empty()){
		j=q.front();
		q.pop();
		for(k=0;k<602;k++){
			if(vis[k]==1||rook[j][k]==0)continue;
			vis[k]=1;
			par[k]=j;
			q.push(k);
		}
	}
	if(vis[601]==0)return curr;
	curr++;
	for(i=601;par[i]!=-1;i=par[i]){
		k=par[i];
		rook[k][i]=0;
		rook[i][k]=1;
	}
	return maxFlow(curr);
}
void discard(string s){
	stringstream fin;
	fin<<s;
	int a,b;
	char c;
	while(fin>>a>>b){
		fin>>c;
		cout<<a<<" "<<b<<"\n";
		rook[a+1][301+b]=0;
	}
	return;
}
class RookAttack{
	public:
	int howMany(int r,int c,vector<string> inp){
		int i,j;
		for(i=0;i<602;i++)
			for(j=0;j<602;j++)rook[i][j]=0;
		for(i=1;i<=r;i++)rook[0][i]=1;
		for(i=1;i<=c;i++)rook[i+300][601]=1;
		for(i=0;i<r;i++)
			for(j=0;j<c;j++){
				rook[i+1][j+301]=1;
			}
		for(i=0;i<inp.size();i++){
			discard(inp[i]);
		}
		return maxFlow(0);
	}
};