#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
#define MAX 100001
using namespace std;
class ChristmasTreeDecoration{
	public:
	int solve(vector<int>col,vector<int>x,vector<int>y){
		int i,j,k,n=col.size(),ans=0,iscon[n][n],vis[n];
		for(i=0;i<n;i++){
			for(j=0;j<n;j++)
				iscon[i][j]=0;
			vis[i]=0;
		}
		
		for(i=0;i<x.size();i++){
			if(col[x[i]-1]!=col[y[i]-1]){
				iscon[x[i]-1][y[i]-1]=iscon[y[i]-1][x[i]-1]=1;
			}
		}
		queue<int>q;
		for(i=0;i<n;i++){
			if(vis[i]==0){
				ans++;
				q.push(i);
				vis[i]=1;
				while(!q.empty()){
					j=q.front();
					q.pop();
					for(k=0;k<n;k++)
						if(vis[k]==0 && iscon[j][k]==1){
							vis[k]=1;
							q.push(k);
						}
				}
			}
		}
		return ans-1;
	}	
};