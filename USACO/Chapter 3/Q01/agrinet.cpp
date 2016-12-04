/*
ID: a1lavan1
LANG: C++
TASK: agrinet
*/
#include <bits/stdc++.h> 
#define T pair<long long,long long>
#define TT pair<T,long long>
#define x first
#define y second
#define MAX 101
using namespace std;
class compare{
public:
	bool operator()(TT &a,TT &b ){
		return (a.y>b.y);
	}
};
int main(){
	ifstream fin("agrinet.in");
	ofstream fout("agrinet.out");
	long long i,ans=0,j,k,n,m,arr[MAX][MAX],vis[MAX],tot=0;
	fin>>n;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)fin>>arr[i][j];
		vis[i]=0;
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)cout<<arr[i][j]<<" ";
		cout<<"\n";
	}
	//Prim time
	priority_queue<TT,vector<TT>,compare> q;
	vis[0]=tot=1;
	for(i=1;i<n;i++)
		q.push(TT(T(0,i),arr[0][i]));
	
	for(;tot<n;tot++){
		while(vis[q.top().x.y]==1)q.pop();
		vis[q.top().x.y]=1;
		ans+=q.top().y;
		TT a=q.top();
		q.pop();
		for(i=0;i<n;i++){
			if(vis[i]==1)continue;
			q.push(TT(T(a.x.y,i),arr[a.x.y][i]));	
		}
	}
	fout<<ans<<"\n";
	return 0;
}