#include <bits/stdc++.h>
using namespace std;
class ColorfulWolves{
	public:
	int getmin(vector<string> adj){
		int i,j,k,n=adj.size(),ans[51];
		queue<int>q;
		for(i=0;i<51;i++)ans[i]=9999;
		ans[0]=0;
		q.push(0);
		while(!q.empty()){
			j=q.front();
			q.pop();
			for(k=i=0;k<n;k++){
				if(adj[j][k]=='N')continue;
				if(ans[k]>(ans[j]+i)){
					ans[k]=ans[j]+i;
					q.push(k);
				}
				i++;
			}
		}
		if(ans[n-1]>5000)return -1;
		return ans[n-1];
	}
};