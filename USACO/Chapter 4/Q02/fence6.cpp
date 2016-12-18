/*
ID: a1lavan1
LANG: C++
TASK: fence6
*/
#include <bits/stdc++.h> 
#define T pair<long long,long long>  // node number, distance
#define x first
#define y second
#define MAX 101
using namespace std;
class edge{
public:
	int value;
	int length;
	vector<int> left,right;
	
	edge(){}
	
	void pushToLeft(int n){
		left.push_back(n);
		sort(left.begin(),left.end());
	}
	
	void pushToRight(int n){
		right.push_back(n);
		sort(right.begin(),right.end());  // messed up here causing a wrong submission
	}
};

class compare{
public:
	bool operator()(T &a, T &b){
		return (a.y>b.y);
	}
};

bool sortInp(edge a,edge b){
	return (a.value<b.value);
}

int main(){
	ifstream fin("fence6.in");
	ofstream fout("fence6.out");
	long long i,ans=100000000,j,k,n,m,visEdge[MAX],visNode[MAX],nodes=0, disNode[MAX];
	edge inp[MAX];
	vector<int> edgeNodes[MAX];
	vector<int> adj[MAX];   // for each node, keep track of all edges it is connected to
	fin>>n;
	for(i=0;i<n;i++){
		fin>>inp[i].value>>inp[i].length>>j>>k;
		while(j--){
			fin>>m;
			inp[i].pushToLeft(m);
		}
		while(k--){
			fin>>m;
			inp[i].pushToRight(m);
		}
	}
	sort(inp,inp+n,sortInp);
	for(i=0;i<n;i++){
		if(inp[i].value<inp[i].left[0]){
			nodes++;
			edgeNodes[i+1].push_back(nodes-1);
			adj[nodes-1].push_back(inp[i].value);
			for(j=0;j<inp[i].left.size();j++){
				adj[nodes-1].push_back(inp[i].left[j]);
				edgeNodes[inp[i].left[j]].push_back(nodes-1);
			}
		}
		if(inp[i].value<inp[i].right[0]){
			nodes++;
			edgeNodes[i+1].push_back(nodes-1);
			adj[nodes-1].push_back(inp[i].value);
			for(j=0;j<inp[i].right.size();j++){
				adj[nodes-1].push_back(inp[i].right[j]);
				edgeNodes[inp[i].right[j]].push_back(nodes-1);
			}
		}
	}
	priority_queue<T,vector<T>,compare>q;
	T a,b;
	for(i=0;i<nodes;i++){
		for(j=0;j<nodes;j++)visNode[j]=0;
		for(j=1;j<=n;j++)visEdge[j]=0;
		q.push(T(i,0));
		disNode[i]=0;
		while(!q.empty()){
			a=q.top();
			k=a.x;
			q.pop();
			if(visNode[k]==1){
				ans=min(ans,disNode[k]+a.y);
				continue;
			}
			visNode[k]=1;
			disNode[k]=a.y;
			for(j=0;j<adj[k].size();j++){
				if(visEdge[adj[k][j]]==1)continue;
				visEdge[adj[k][j]]=1;
				m=edgeNodes[adj[k][j]][0]+edgeNodes[adj[k][j]][1]-k;
				if(visNode[m]==0){
					q.push(T(m,disNode[k]+inp[adj[k][j]-1].length));
				}
				else{	
					ans=min(ans,disNode[k]+disNode[m]+inp[adj[k][j]-1].length);
				}
			}
		}
	}
	fout<<ans<<"\n";
	return 0;
}