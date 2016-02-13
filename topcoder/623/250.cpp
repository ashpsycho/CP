#include <bits/stdc++.h>
using namespace std;
class UniformBoard{
	public:
	int getBoard(vector<string>g,int K){
		int i,j,x,y,k,m,n=g.size(),ac=0,ec=0,ans=0,pc;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(g[i][j]=='A')ac++;
				else if(g[i][j]=='.')ec++;
			}
		}
		if(ec==0)K=0;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				for(x=i;x<n;x++){
					for(y=j;y<n;y++){
						if(ac<((y+1-j)*(x+1-i)))continue;
						for(k=i,pc=ec=0;k<=x;k++){
							for(m=j;m<=y;m++){
								if(g[k][m]=='P')pc++;
								if(g[k][m]=='.')ec++;
							}
						}
						if(K>=(2*pc +ec))ans=max(ans,((y+1-j)*(x+1-i)));
					}
				}
			}
		}
		return ans;
	}
};