#include <bits/stdc++.h>
using namespace std;
class TravelOnMars{
	public:
	int minTimes(vector<int> v,int st,int en){
		int i,j,k,n=v.size(),vis[n],dis[n];
		queue<int> q;
		q.push(st);
		for(i=0;i<n;i++)vis[i]=0;
		dis[st]=0;
		vis[st]=1;
		while(!q.empty()){
			j=q.front();
			q.pop();
			cout<<j<<" "<<dis[j]<<"\n";
			for(k=1;k<=v[j];k++){
				i=(j+k)%n;
				if(vis[i]==0){
					vis[i]=1;
					dis[i]=1+dis[j];
					q.push(i);
				}
			}
			for(k=1;k<=v[j];k++){
				i=(j+k*(n-1))%n;
				if(vis[i]==0){
					vis[i]=1;
					dis[i]=1+dis[j];
					q.push(i);
				}
			}
		}
		
		return dis[en];
	}
};