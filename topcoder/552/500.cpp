#include <bits/stdc++.h>
using namespace std;
int l[31][1801],r[31][1801];
int calc(vector<string> g,int maxD){
	static int L[31][31][31][31],P[31][31][31][31],ans=0;
	int i,j,k,x,y,n=g.size(),m=g[0].size();
	for(i=0;i<31;i++){
		for(j=0;j<1801;j++)l[i][j]=r[i][j]=-1;
	}
	for(i=0;i<31;i++){	
		for(j=0;j<31;j++){
			for(x=0;x<31;x++){
				for(k=0;k<31;k++)L[i][j][x][k]=P[i][j][x][k]=0;
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			for(x=1;(x+i)<=n;x++){
				for(y=1;(y+j)<=m;y++){
					L[i][j][x][y]=L[i][j][x-1][y]+L[i][j][x][y-1]-L[i][j][x-1][y-1];
					P[i][j][x][y]=P[i][j][x-1][y]+P[i][j][x][y-1]-P[i][j][x-1][y-1];
					if(g[i+x-1][j+y-1]=='P')P[i][j][x][y]++;
					else if(g[i+x-1][j+y-1]=='L')L[i][j][x][y]++;
					l[j+y-1][900+L[i][j][x][y]-P[i][j][x][y]]=max(l[j+y-1][900+L[i][j][x][y]-P[i][j][x][y]],L[i][j][x][y]+P[i][j][x][y]);
				}
			}
		}
	}
	for(i=0;i<n;i++)reverse(g[i].begin(),g[i].end());
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			for(x=1;(x+i)<=n;x++){
				for(y=1;(y+j)<=m;y++){
					L[i][j][x][y]=L[i][j][x-1][y]+L[i][j][x][y-1]-L[i][j][x-1][y-1];
					P[i][j][x][y]=P[i][j][x-1][y]+P[i][j][x][y-1]-P[i][j][x-1][y-1];
					if(g[i+x-1][j+y-1]=='P')P[i][j][x][y]++;
					else if(g[i+x-1][j+y-1]=='L')L[i][j][x][y]++;
					r[j+y-1][900+L[i][j][x][y]-P[i][j][x][y]]=max(r[j+y-1][900+L[i][j][x][y]-P[i][j][x][y]],L[i][j][x][y]+P[i][j][x][y]);
				}
			}
		}
	}
	for(i=0;i<1801;i++){
		for(j=1;j<m;j++){
			l[j][i]=max(l[j][i],l[j-1][i]);
			r[j][i]=max(r[j][i],r[j-1][i]);
		}
	}
	for(i=0;i<1801;i++){
		for(j=0;j<1801;j++){
			x=i-900;
			y=j-900;
			if(abs(x+y)>maxD)continue;
			for(k=0;k<(m-1);k++){
				if(l[k][i]>=0 && r[m-(k+2)][j]>=0)
					ans=max(ans,l[k][i]+r[m-(k+2)][j]);
			}
			if(abs(i-900)<=maxD)ans=max(ans,l[m-1][i]);
			if(abs(j-900)<=maxD)ans=max(ans,r[m-1][j]);
		}
	}
	return ans;
}
class FoxAndFlowerShopDivOne{
	public:
	int theMaxFlowers(vector<string>g,int maxD){
		int i,j,n=g.size(),ans=0,lc=0,pc=0,m=g[0].size();
		ans=max(ans,calc(g,maxD));
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(g[i][j]=='P')pc++;
				else if(g[i][j]=='L')lc++;
			}
		}
		if((pc+lc)==0)return 0;
		vector<string>g1;
		g1.clear();
		for(i=0;i<m;i++){
			g1.push_back("");
			for(j=0;j<n;j++)g1[i]=g1[i]+g[j][i];
		}
		ans=max(ans,calc(g1,maxD));
		if(ans==0 && (lc+pc)>(n*m-2))return -1;
		if(ans==1 && (lc+pc)==(n*m))return -1;
		return ans;
	}
};