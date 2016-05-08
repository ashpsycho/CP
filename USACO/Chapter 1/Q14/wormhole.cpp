/*
ID: a1lavan1
LANG: C++
TASK: wormhole
*/
#include <bits/stdc++.h> 
#define T pair<long long,long long>
#define x first
#define y second
#define MAX 12
using namespace std;

long long i,ans=0,j,k,n,m,vis[MAX],next[MAX];
T arr[MAX],curr[MAX];
bool check(){	
	for(i=0;i<n;i++){
		next[i]=-1;
		for(j=0;j<n;j++){
			if(j==i || curr[j].y!=curr[i].y || curr[i].x>curr[j].x)continue;
			if(next[i]== -1 || curr[j].x<curr[next[i]].x)next[i]=j;
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)vis[j]=0;
		for(j=i;j!=-1 && vis[j]==0;vis[j]=1,j=(next[j^1]));
		if(j!=-1)return true;
	}
	return false;
}

void rec(int n,vector<int> v){
	if(v.size()==0){
		if(check())ans++;
		return;
	}
	vector<int> next;
	for(int j=0;j<(v.size()-1);j++){
		next=v;
		next.erase(next.begin()+v.size()-1);
		next.erase(next.begin()+j);
		curr[n]=arr[v[v.size()-1]];
		curr[n+1]=arr[v[j]];
		rec(n+2,next);
	}
}

int main(){
	ifstream fin("wormhole.in");
	ofstream fout("wormhole.out");
	fin>>n;
	for(i=0;i<n;i++)fin>>arr[i].x>>arr[i].y;
	vector<int> v;
	for(i=0;i<n;i++)v.push_back(i);
	rec(0,v);
	fout<<ans<<"\n";
	return 0;
}