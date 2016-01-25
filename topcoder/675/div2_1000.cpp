#include <bits/stdc++.h>
using namespace std;
class TreeAndPathLength2{
	public:
	string possible(int n,int s){
		int i,j,k,isp[51][1001];
		if(n<3)return "Impossible";
		set<int>adj[51][1001];
		set<int>::iterator it;
		for(i=0;i<51;i++)
			for(j=0;j<1001;j++)isp[i][j]=0;
		isp[3][1]=1;
		adj[3][1].insert(2);
		adj[3][1].insert(1);
		for(i=3;i<50;i++){
			for(j=0;j<1001;j++){	
				if(isp[i][j]==0)continue;
				for(it=adj[i][j].begin();it!=adj[i][j].end();++it){
					k=*it;
					if((j+k)>1000)continue;
					isp[i+1][j+k]=1;
					adj[i+1][j+k].insert(1);
					adj[i+1][j+k].insert(1+k);
				}
			}
		}
		return (isp[n][s]==1)?"Possible":"Impossible";
	}
};
