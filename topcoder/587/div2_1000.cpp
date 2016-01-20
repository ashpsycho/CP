#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
using namespace std;
class ThreeColorabilityEasy{
	public:
	string isColorable(vector<string> g){
		int i,j,k,n=1+g.size(),m=1+g[0].size(),color[n][m];
		vector<T> adj[n][m];
		for(i=0;i<(n-1);i++){
			for(j=0;j<(m-1);j++){
				adj[i][j].push_back(T(i,j+1));
				adj[i][j].push_back(T(i+1,j));
				adj[i+1][j].push_back(T(i,j));
				adj[i+1][j].push_back(T(i+1,j+1));
				adj[i][j+1].push_back(T(i,j));
				adj[i][j+1].push_back(T(i+1,j+1));
				adj[i+1][j+1].push_back(T(i,j+1));
				adj[i+1][j+1].push_back(T(i+1,j));
				if(g[i][j]=='N'){
					adj[i][j].push_back(T(i+1,j+1));
					adj[i+1][j+1].push_back(T(i,j));
				}
				else{
					adj[i][j+1].push_back(T(i+1,j));
					adj[i+1][j].push_back(T(i,j+1));
				}
			}
		}
		if(g[0][0]=='Z'){
			color[0][0]=color[1][1]=1;
			color[0][1]=2;
			color[1][0]=4;
		}
		else{
			color[1][0]=color[0][1]=1;
			color[0][0]=2;
			color[1][1]=4;
		}
		for(i=0;i<(n-1);i++){
			for(j=0;j<(m-1);j++){
				if(i==0 && j==0)continue;
				else if(i==0){
					if(g[i][j]=='Z'){
						color[i+1][j+1]=color[i][j];
						color[i][j+1]=7-(color[i][j]+color[i+1][j]);
					}
					else{
						color[i][j+1]=color[i+1][j];
						color[i+1][j+1]=7-(color[i][j]+color[i+1][j]);
					}
				}
				else if(j==0){
					if(g[i][j]=='Z'){
						color[i+1][j+1]=color[i][j];
						color[i+1][j]=7-(color[i][j]+color[i][j+1]);
					}
					else{
						color[i+1][j]=color[i][j+1];
						color[i+1][j+1]=7-(color[i][j]+color[i+1][j]);
					}
				}
				else{
					if(g[i][j]=='Z')color[i+1][j+1]=color[i][j];
					else color[i+1][j+1]=7-(color[i][j]+color[i+1][j]);
				}
			}
		}
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(color[i][j]!=1 && color[i][j]!=2 && color[i][j]!=4 )return "No";
				for(k=0;k<adj[i][j].size();k++)if(color[i][j]==color[adj[i][j][k].x][adj[i][j][k].y])return "No";
			}
		}
		return "Yes";
	}
};