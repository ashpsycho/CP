#include <bits/stdc++.h>
using namespace std;
class GooseTattarrattatDiv1{
	public:
	int getmin(string s){
		int i,j,k=0,x,n=s.size(),Count[26],vis[26],tot,ma;
		int adj[26][26];
		for(i=0;i<26;i++){
			Count[i]=vis[i]=0;
			for(j=0;j<26;j++)adj[i][j]=0;
		}
		for(i=0;i<n;i++)Count[s[i]-'a']++;
		for(i=0;i<n;i++){
			adj[s[i]-'a'][s[n-(i+1)]-'a']=1;
		}
		for(i=0;i<26;i++){
			if(vis[i])continue;
			vis[i]=1;
			tot=ma=Count[i];
			queue<int>q;
			q.push(i);
			while(!q.empty()){
				x=q.front();
				q.pop();
				for(j=0;j<26;j++){
					if(vis[j]==0 && adj[x][j]==1){
						vis[j]=1;
						q.push(j);
						tot+=Count[j];
						ma=max(ma,Count[j]);
					}
				}
			}
			k+=(tot-ma);
		}
		return k;
	}
};
