#include <bits/stdc++.h>
using namespace std;
class FriendScore{
	public:
	int highestScore(vector<string> adj){
		int i,j,k,n=adj.size(),ans=0,curr;
		for(i=0;i<n;i++){
			curr=0;
			for(j=0;j<n;j++){
				if(i==j)continue;
				if(adj[i][j]=='Y'){
					curr++;
					continue;
				}
				for(k=0;k<n;k++)if(adj[j][k]=='Y' && adj[i][k]=='Y')break;
				if(k<n)curr++;
			}
			ans=max(ans,curr);
		}
		return ans;
	}
};