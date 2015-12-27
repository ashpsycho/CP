#include <bits/stdc++.h>
using namespace std;
class RobotOnMoon{
	public:
	int longestSafeCommand(vector<string> g){
		int i,j,k,sx=0,sy=0,n=g.size(),m=g[0].size(),ans[4],dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)if(g[i][j]=='S'){
				sx=i;
				sy=j;
			}
			
		for(i=0;i<4;i++){
			for(ans[i]=0,j=sx,k=sy;j<n && j>=0 && k<m && k>=0 && g[j][k]!='#';ans[i]++,j+=dir[i][0],k+=dir[i][1]);
			if(j<n && j>=0 && k<m && k>=0)return -1;
		}
		for(i=0,j=0;i<4;i++)j+=(ans[i]-1);
		return j;
	}
};