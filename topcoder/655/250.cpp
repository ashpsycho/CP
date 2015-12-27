#include <bits/stdc++.h>
using namespace std;
class BichromePainting{
	public:
	string isThatPossible(vector<string> g,int K){
		int i,j,x,y,n=g.size(),countW[n][n],countB[n][n];
		for(i=0;i<n;i++){
			for(j=0;j<n;j++)if(g[i][j]!='*')break;
			if(j<n)break;
		}
		if(i==n)return "Possible";
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				countW[i][j]=countB[i][j]=0;
				if(g[i][j]=='B')countB[i][j]=1;
				if(g[i][j]=='W')countW[i][j]=1;
			}
		}
		for(i=1;i<n;i++){
			countW[i][0]+=countW[i-1][0];
			countW[0][i]+=countW[0][i-1];
			countB[i][0]+=countB[i-1][0];
			countB[0][i]+=countB[0][i-1];
		}		
		for(i=1;i<n;i++){
			for(j=1;j<n;j++){
				countW[i][j]+=(countW[i-1][j]+countW[i][j-1]-countW[i-1][j-1]);
				countB[i][j]+=(countB[i-1][j]+countB[i][j-1]-countB[i-1][j-1]);
			}
		}
		for(i=0;i<=(n-K);i++){
			for(j=0;j<=(n-K);j++){
				if(i==0 && j==0){
					x=countW[K-1][K-1];
					y=countB[K-1][K-1];
				}
				else if(i==0){
					x=countW[i+K-1][j+K-1]-countW[i+K-1][j-1];
					y=countB[i+K-1][j+K-1]-countB[i+K-1][j-1];
				}
				else if(j==0){
					x=countW[i+K-1][j+K-1]-countW[i-1][j+K-1];
					y=countB[i+K-1][j+K-1]-countB[i-1][j+K-1];
				}
				else{
					x=countW[i+K-1][j+K-1]+countW[i-1][j-1]-(countW[i+K-1][j-1]+countW[i-1][j+K-1]);
					y=countB[i+K-1][j+K-1]+countB[i-1][j-1]-(countB[i+K-1][j-1]+countB[i-1][j+K-1]);
				}
				if(x==0 && y==0)continue;
				if(x>0 && y>0)continue;
				break;
			}
			if(j<=(n-K))break;
		}
		if(i>(n-K))return "Impossible";
		for(x=0;x<K;x++)
			for(y=0;y<K;y++)g[i+x][j+y]='*';
		return isThatPossible(g,K);
	}
};