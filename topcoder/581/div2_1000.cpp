#include <bits/stdc++.h>
using namespace std;
class TreeUnionDiv2{
	public:
	int maximumCycles(vector<string> t1,vector<string> t2,int K){
		int i,j,k,n=t1.size(),d1[n][n],d2[n][n],v1[n][n],v2[n][n],arr[n],ans=0;
		queue<int> q;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)v1[i][j]=v2[i][j]=0;
		for(i=0;i<n;i++){
			d1[i][i]=0;
			v1[i][i]=1;
			q.push(i);
			while(!q.empty()){
				k=q.front();
				q.pop();
				for(j=0;j<n;j++){
					if(v1[i][j]==1 || t1[k][j]=='-')continue;
					v1[i][j]=1;
					d1[i][j]=d1[i][k]+1;
					q.push(j);
				}
			}
		}
		for(i=0;i<n;i++){
			d2[i][i]=0;
			v2[i][i]=1;
			q.push(i);
			while(!q.empty()){
				k=q.front();
				q.pop();
				for(j=0;j<n;j++){
					if(v2[i][j]==1 || t2[k][j]=='-')continue;
					v2[i][j]=1;
					d2[i][j]=d2[i][k]+1;
					q.push(j);
				}
			}
		}
		for(i=0;i<n;i++)arr[i]=i;
		do{
			k=0;
			for(i=0;i<n;i++)
				for(j=i+1;j<n;j++){
					if((d1[i][j]+2+d2[arr[i]][arr[j]])==K)k++;
				}
			ans=max(ans,k);
		}while(next_permutation(arr,arr+n));
		return ans;
	}
};