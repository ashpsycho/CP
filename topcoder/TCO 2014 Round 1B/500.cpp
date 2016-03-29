#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
using namespace std;
class WolvesAndSheep{
	public:
	int getmin(vector<string> g){
		int i,j,k,n=g.size(),m=g[0].size(),ans=n+m-2,po=1<<(n-1),co,arr[m],x,y;
		vector<int>v;
		vector<T>vv;
		for(i=0;i<po;i++){
			v.clear();
			vv.clear();
			co=0;
			v.push_back(-1);
			for(j=0,k=1;j<(n-1);j++,k*=2){
				if(k&i)v.push_back(j);
			}
			v.push_back(n-1);
			for(j=1;j<v.size();j++){
				for(k=0;k<m;k++){
					arr[k]=0;
					for(x=1+v[j-1];x<=v[j];x++){
						if(g[x][k]=='S')arr[k]|=1;
						if(g[x][k]=='W')arr[k]|=2;
					}
					if(arr[k]==3)break;
				}
				if(k<m)break;
				for(y=x=0,k=0;k<m;k++){
					y|=arr[k];
					if(y==3){
						y=arr[k];
						vv.push_back(T(x,k));	
					}
					if(arr[k]!=0)x=k+1;
				}
			}
			if(j<v.size())continue;
			sort(vv.begin(),vv.end());
			for(x=y=0;x<vv.size();){
				for(j=x+1,k=vv[x].y;j<vv.size() && vv[j].x<=k;j++)k=min(k,vv[j].y);
				x=j;
				y++;
			}
			ans=min(ans,y+__builtin_popcount(i));
		}
		return ans;
	}
}; 