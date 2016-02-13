#include <bits/stdc++.h>
using namespace std;
class Family{
	public:
	string isFamily(vector<int> p1,vector<int> p2){
		int i,j,k,n=p1.size(),col[n];
		vector<int> adj[n];
		for(i=0;i<n;i++){
			col[i]=0;
			if(p1[i]==-1)continue;
			adj[p1[i]].push_back(p2[i]);
			adj[p2[i]].push_back(p1[i]);
		}
		queue<int>q;
		for(i=0;i<n;i++){
			if(col[i]!=0)continue;
			col[i]=1;
			q.push(i);
			while(!q.empty()){
				j=q.front();
				q.pop();
				for(k=0;k<adj[j].size();k++){
					if(col[j]==col[adj[j][k]])return "Impossible";
					if(col[adj[j][k]]!=0)continue;
					col[adj[j][k]]=3-col[j];
					q.push(adj[j][k]);
				}
			}
		}
		return "Possible";
	}
};