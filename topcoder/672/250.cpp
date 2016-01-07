#include <bits/stdc++.h>
using namespace std;
class Procrastination{
	public:
	long long findFinalAssignee(long long n){
		long long i,j,k=1,k1,k2;
		vector<long long> adj[1000];
		for(i=0;i<1000;i++){
			for(j=(n-500+i),k=2;(k*k)<=j && (j>3);k++){
				if((j%k)!=0)continue;
				adj[i].push_back(k);
				adj[i].push_back(j/k);
			}
			sort(adj[i].begin(),adj[i].end());
		}
		for(i=n,k=1;;){
			for(j=0;j<1000;j++)while(adj[j].size()>0 && adj[j][0]<=k)adj[j].erase(adj[j].begin());
			k1=i+500-n;
			k2=i+499-n;
			if(adj[k1].size()==0 && adj[k2].size()==0)break;
			else if(adj[k1].size()==0){
				k=adj[k2][0];
				i--;
			}
			else if(adj[k2].size()==0){
				k=adj[k1][0];
				i++;	
			}
			else{
				if(adj[k1][0]<adj[k2][0]){
					k=adj[k1][0];
					i++;
				}
				else{
					k=adj[k2][0];
					i--;
				}
			}
		}
		return i;
	}
};