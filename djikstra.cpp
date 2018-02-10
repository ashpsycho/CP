#include <bits/stdc++.h>
using namespace std;
#define T pair<int,int>
#define x first
#define y second

class compare{

	public:
	bool operator()(T &a, T &b) {
		return (a.y>b.y);
	}
	
};
int main(){

	vector<T> adj[300];
	int i,j,k,n,m,a,b, visited[300],dist[300];
	
	set<int> s;
	set<int>::iterator it;
	s.insert(10);
	s.erase(1);
	s.find(12);

	for(it=s.begin();it!=s.end();++it){
		cout<<(*it)<<"\n";
	}













	cin>>n>>m;
	T t;

	for(i=0;i<m;i++){
		cin>>a>>b>>k;
		adj[a].push_back( T(b,k) );
		adj[b].push_back( T(a,k) );
	}
	priority_queue< T, vector<T>, compare > q;

	for(i=0;i<n;i++)visited[i]=0;

	q.push(T(0,0));

	while(!q.empty()){

		t=q.top();
		q.pop();
		if(visited[t.x]==1)continue;
		
		for(i=0;i< adj[t.x].size() ;i++){
			if(visited[ adj[t.x][i].x ] == 1 )continue;
			q.push(T(adj[t.x][i].x , t.y + adj[t.x][i].y ));
		}
	
		visited[t.x]=1;
		dist[t.x]=t.y;
	}

	for(i=0;i<n;i++){
		if(visited[i]==1)cout<<i<<" "<<dist[i]<<"\n";
	}

	return 0;
}