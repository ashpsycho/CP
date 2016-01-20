#include <bits/stdc++.h>
#include <sstream>
using namespace std;
int adj[50][50];
void fill_adj(vector<string> inp){
	int i,j,n=inp.size();
	char c;
	for(i=0;i<n;i++){
		stringstream fin;
		fin<<inp[i];
		while(fin>>j){
			fin>>c;
			adj[i][j]=1;
		}
	}
	return ;
}
class UndergroundVault{
	public:
	vector<int> sealOrder(vector<string> inp){
		int i,j,k,n=inp.size(),vis[n],m,vis1[n];
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)adj[i][j]=0;
		fill_adj(inp);
		for(i=0;i<n;i++)vis[i]=0;
		queue<int>q;
		vector<int> ans;
		for(i=1;i<n;i++){
			for(j=1;j<n;j++){
				if(vis[j]==1)continue;
				q.push(0);
				for(k=0;k<n;k++)vis1[k]=0;
				vis1[0]=1;
				while(!q.empty()){
					k=q.front();
					q.pop();
					for(m=0;m<n;m++)if(adj[k][m]==1 && vis[m]==0 && m!=j && vis1[m]==0){
						q.push(m);
						vis1[m]=1;
					}
				}
				for(k=0;k<n;k++){
					if(k==j)continue;
					if(vis[k]==1 || vis1[k]==1)continue;
					break;
				}
				if(k==n)break;
			}
			ans.push_back(j);
			vis[j]=1;
		}
		ans.push_back(0);
		return ans;
	}
};