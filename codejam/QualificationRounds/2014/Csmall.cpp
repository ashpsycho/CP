#include <bits/stdc++.h>
#include <fstream>
#include <stdio.h>
#define T pair<int,int>
#define x first
#define y second
using namespace std;
string ans[51][51];
int impossible;
void solve(int r,int c,int m){
	int i,j,k,n,x,y;
	if(r==1){
		for(i=0;i<c;i++){
			if(i<m)ans[0][i]=".";
			else ans[0][i]="*";
			ans[0][0]="c";
		}
		return;
	}
	if(c==1){
		for(i=0;i<r;i++){
			if(i<m)ans[i][0]=".";
			else ans[i][0]="*";
			ans[0][0]="c";
		}	
		return;
	}
	for(i=2;i<=r;i++)
		if((m%i)==0 && (m/i)<=c && (m/i)>1)break;
	if(i<=r){
		for(j=0;j<r;j++)
			for(k=0;k<c;k++){
				ans[j][k]="*";
			}
		for(j=0;j<i;j++){
			for(k=0;k<(m/i);k++)ans[j][k]=".";
		}
		ans[0][0]="c";
		return;
	}
	for(i=3;i<=r;i++){
		for(j=2;j<i;j++){
			for(k=2;k<c;k++){
				if((i*k)>=m)continue;
				n=m-(i*k);
				if((n%j)==0 && (k+(n/j))<=c && (n/j)>1 &&(n<j)<k)break;
			}
			if(k<c)break;
		}
		if(j<i)break;
	}
	if(i>r){
		impossible=1;
		return;
	}
	for(x=0;x<r;x++)
		for(y=0;y<c;y++)ans[x][y]="*";
	for(x=0;x<i;x++)
		for(y=0;y<k;y++)ans[x][y]=".";
	for(x=0;x<j;x++)
		for(y=0;y<(n/j);y++)ans[x][k+y]=".";
	ans[0][0]="c";
	return;
}
int main(){
	long long t,te,i,j,k,n,m,r,c;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin>>t;
	for(te=0;te<t;te++){
		fin>>r>>c>>m;
		m=(r*c)-m;
		impossible=0;
		solve(r,c,m);
		if(impossible){
			fout<<"Case #"<<(te+1)<<":\nImpossible\n";
			cout<<"Case #"<<(te+1)<<":\nImpossible\n";
			continue;
		}
		fout<<"Case #"<<(te+1)<<":\n";
		for(i=0;i<r;i++){
			for(j=0;j<c;j++)fout<<ans[i][j];
			fout<<"\n";	
		}

		cout<<"Case #"<<(te+1)<<":\n";
		for(i=0;i<r;i++){
			for(j=0;j<c;j++)cout<<ans[i][j];
			cout<<"\n";						
		}

	}
	return 0;
}
