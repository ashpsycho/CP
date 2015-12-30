#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
#define T pair<int,int>
#define x first
#define y second
int main(){
	int t,te,i,j,k,n,m,x1,x2,y1,y2,fin,ans1[501][501],ans2[501][501];
	string inp[500];
	cin>>n>>m;
	for(i=0;i<n;i++)cin>>inp[i];
	for(i=0;i<501;i++)
		for(j=0;j<501;j++)ans1[i][j]=ans2[i][j]=0;
	for(i=0;i<n;i++){
		for(j=0;j<(m-1);j++){
			if(inp[i][j]=='.' && inp[i][j+1]=='.')ans1[i][j]=1;
			if(j>0)ans1[i][j]+=ans1[i][j-1];
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<(n-1);j++){
			if(inp[j][i]=='.' && inp[j+1][i]=='.')ans2[j][i]=1;
			if(j>0)ans2[j][i]+=ans2[j-1][i];
		}
	}
	cin>>t;
	for(te=0;te<t;te++){
		cin>>x1>>y1>>x2>>y2;
		x1--;
		x2--;
		y1--;
		y2--;
		fin=0;
		for(i=x1;i<=x2;i++){
			if(y1==y2)continue;
			if(y1==0)fin+=ans1[i][y2-1];
			else fin+=(ans1[i][y2-1]-ans1[i][y1-1]);
		}
		for(i=y1;i<=y2;i++){
			if(x1==x2)continue;
			if(x1==0)fin+=ans2[x2-1][i];
			else fin+=(ans2[x2-1][i]-ans2[x1-1][i]);
		}
		cout<<fin<<"\n";
	}
	return 0;
}