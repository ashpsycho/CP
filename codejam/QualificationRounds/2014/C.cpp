#include <bits/stdc++.h>
#include <fstream>
#include <stdio.h>
#define T pair<int,int>
#define x first
#define y second
using namespace std;
string ans[51][51];
int impossible;
int check(int r,int c){
	int i,j,k,n,dir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,-1},{1,1},{-1,1},{-1,-1}},vis[51][51];
	queue<T>q;
	T a,b;
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)vis[i][j]=0;
	q.push(T(r-1,c-1));
	vis[r-1][c-1]=1;
	while(!q.empty()){
		a=q.front();
		q.pop();
		for(i=j=0;i<8;i++){
			b=T(a.x+dir[i][0],a.y+dir[i][1]);
			if(b.x<0 || b.y<0 || b.x>=r || b.y>=c)continue;
			if(ans[b.x][b.y]=="*")j++;
		}
		if(j>0)continue;
		for(i=j=0;i<8;i++){
			b=T(a.x+dir[i][0],a.y+dir[i][1]);
			if(b.x<0 || b.y<0 || b.x>=r || b.y>=c)continue;
			if(ans[b.x][b.y]!="*" && vis[b.x][b.y]==0){
				vis[b.x][b.y]=1;
				q.push(b);
			}
		}
	}
	for(i=0;i<r;i++)
		for(j=0;j<c;j++){
			if(ans[i][j]=="." && vis[i][j]==0)return 0;
		}
	return 1;
}
void solve(int r,int c,int m){			// m = no of mines
	int i,j,k,n,x,y,m1;
	for(n=0;n<c && (r*n)<=m;n++){
		for(i=0;i<r;i++)
			for(j=0;j<c;j++)ans[i][j]=".";
		for(i=0;i<r;i++){
			for(j=0;j<n;j++)ans[i][j]="*";
		}
		m1=m;
		m=m1-(r*n);
		for(i=k=0;i<r;i++){
			for(j=n;j<c && k<m;j++,k++){
				ans[i][j]="*";
			}
			if(k==m)break;
		}
		cout<<r<<" "<<c<<" "<<i<<" "<<j<<"\n";
		if(j==(c-1) && i!=(r-1) && c>1){
			j--;
			ans[i][j]=".";
			ans[i+1][n]="*";
		}
		ans[r-1][c-1]="c";
		if(check(r,c))return;
		m=m1;
	}
	impossible =1;
}
int main(){
	long long t,te,i,j,k,n,m,r,c;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin>>t;
	for(te=0;te<t;te++){
		fin>>r>>c>>m;
		impossible=0;
		solve(r,c,m);
		if(impossible){
			fout<<"Case #"<<(te+1)<<":\nImpossible\n";
			cout<<"Case #"<<(te+1)<<":\nImpossible\n";
			cout<<r<<" "<<c<<" "<<m<<" "<<(r*c)-m<<"\n";
			continue;
		}
		fout<<"Case #"<<(te+1)<<":\n";
		for(i=r-1;i>=0;i--){
			for(j=c-1;j>=0;j--)fout<<ans[i][j];
			fout<<"\n";	
		}

	 	cout<<"Case #"<<(te+1)<<":\n";
	 	for(i=r-1;i>=0;i--){
	 		for(j=c-1;j>=0;j--)cout<<ans[i][j];
	 		cout<<"\n";						
	 	}

	}
	return 0;
}
