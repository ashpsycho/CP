#include <bits/stdc++.h>
using namespace std;
int cap[102][102],cur[102][102],par[102],vis[102];
int maxFlow(int curr){
	int i,j,k;
	for(i=0;i<102;i++)vis[i]=0,par[i]=-1;
	queue<int>q;
	q.push(0);
	vis[0]=1;
	while(!q.empty()){
		j=q.front();
		q.pop();
		for(i=0;i<102;i++){
			if(vis[i])continue;
			if(cur[j][i]!=0 || cap[j][i]!=1)continue;
			vis[i]=1;
			par[i]=j;
			q.push(i);
		}
	}
	if(vis[101]==0)return curr;
	curr++;
	for(i=101;par[i]!=-1;i=par[i]){
		k=par[i];
		cap[i][k]=1;
		cap[k][i]=0;
		cur[k][i]=1;
		cur[i][k]=0;
	}
	return maxFlow(curr);
	
}
class PointyWizardHats{
	public:
	int getNumHats(vector<int> topH,vector<int>topR,vector<int>botH,vector<int>botR){
		int i,j,n=topH.size(),m=botH.size();
		for(i=0;i<102;i++)
			for(j=0;j<102;j++)cap[i][j]=cur[i][j]=0;
		for(i=0;i<n;i++)cap[0][i+1]=1;	
		for(i=0;i<m;i++)cap[51+i][101]=1;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(topR[i]>=botR[j])continue;
				if((topR[i]*botH[j])>=(topH[i]*botR[j]))continue;
				cap[i+1][51+j]=1;
			}
		}	
		return maxFlow(0);
	}
};