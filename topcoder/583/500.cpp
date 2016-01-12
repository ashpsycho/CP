#include <bits/stdc++.h>
#define T pair<int,int>
#define TT pair<int,T>
#define x first
#define y second
using namespace std;
class TurnOnLamps{
	public:
	int minimize(vector<int>par,string init,string fin){
		vector <TT> edges;
		int i,j,n=1+par.size(),Count[n];
		for(i=0;i<(n-1);i++){
			if(fin[i]=='0')
				edges.push_back(TT(2,T(i+1,par[i])));
			else if(init[i]=='1')
				edges.push_back(TT(0,T(i+1,par[i])));
			else
				edges.push_back(TT(1,T(i+1,par[i])));
		}
		for(i=0;i<(n-1);i++){
			if(edges[i].x==2){
				for(j=0;j<(n-1);j++){
					if(j==i)continue;
					if(edges[j].y.x==edges[i].y.y)edges[j].y.x=edges[i].y.x;
					if(edges[j].y.y==edges[i].y.y)edges[j].y.y=edges[i].y.x;
				}
				edges[i].y.y=edges[i].y.x;
			}
		}
		for(i=0;i<n;i++)Count[i]=0;
		for(i=0;i<(n-1);i++){
			if(edges[i].x!=1)continue;
			Count[edges[i].y.x]++;
			Count[edges[i].y.y]++;
		}
		for(i=j=0;i<n;i++){
			if(Count[i]&1)j++;
		}
		return (j/2);
	}
};