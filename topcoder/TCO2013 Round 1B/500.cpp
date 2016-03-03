#include <bits/stdc++.h>
using namespace std;
class EllysFigurines{
	public:
	int getMoves(vector<string>g,int R,int C){
		int i,j,k,n=g.size(),m=g[0].size(),ans=15,po,x,y,z,curr;
		vector<string>v;
		for(i=0;i<=((n+(R-1))/R);i++){
			for(j=0,po=1<<n;j<po;j++){
				if(__builtin_popcount(j)!=i)continue;
				v=g;
				curr=i;
				for(k=0,y=1;k<n;k++,y*=2){
					if((j&y)==0)continue;
					for(x=0;x<R &&(x+k)<n;x++){
						for(z=0;z<m;z++)v[k+x][z]='.';
					}
				}
				for(x=0;x<m;x++){
					for(y=0;y<n;y++)if(v[y][x]=='X')break;
					if(y==n)continue;
					curr++;
					for(k=0;k<C &&(x+k)<m;k++){
						for(y=0;y<n ;y++)v[y][x+k]='.';
					}
				}
				ans=min(ans,curr);
			}
		}
		return ans;
	}
};