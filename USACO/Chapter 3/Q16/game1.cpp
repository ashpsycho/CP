/*
ID: a1lavan1
LANG: C++
TASK: game1
*/
#include <bits/stdc++.h> 
#define T pair<long long,long long>
#define x first
#define y second
#define MAX 201
using namespace std;
T dp[201][201];
int vis[201][201],arr[MAX];
T rec(int st, int en){
	if(vis[st][en]==1)return dp[st][en];
	vis[st][en]=1;
	if(st==en){
		return dp[st][en]=T(arr[st],0);
	}
	T a=rec(st+1,en),b=rec(st,en-1);
	a.y+=arr[st];
	b.y+=arr[en];
	if(b.y>a.y)a=b;
	swap(a.x,a.y);
	return dp[st][en]=a;
}
int main(){
	ifstream fin("game1.in");
	ofstream fout("game1.out");
	long long i,j,k,n,m;
	fin>>n;
	for(i=0;i<n;i++)fin>>arr[i];
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)vis[i][j]=0;
	}
	T ans=rec(0,n-1);
	fout<<ans.x<<" "<<ans.y<<"\n";
	return 0;
}