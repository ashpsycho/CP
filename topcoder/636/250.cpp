#include <bits/stdc++.h>
using namespace std;
int sum[51][51];
class ChocolateDividingEasy{
	public:
	int findBest(vector<string> g){
		int i,j,x,y,n=g.size(),m=g[0].size(),ans=0;
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)sum[i][j]=g[i][j]-'0';
		for(i=1;i<n;i++)sum[i][0]+=sum[i-1][0];
		for(i=1;i<m;i++)sum[0][i]+=sum[0][i-1];
		for(i=1;i<n;i++)
			for(j=1;j<m;j++)
				sum[i][j]+=(sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]);
		for(i=0;i<n;i++){
			for(j=0;j<m;j++)cout<<sum[i][j]<<" ";
			cout<<"\n";
		}
		vector<int> v;
		for(i=0;i<n;i++){
			for(j=i+1;j<(n-1);j++){
				for(x=0;x<m;x++){
					for(y=x+1;y<(m-1);y++){
						v.clear();
						v.push_back(sum[i][x]);
						v.push_back(sum[j][x]-sum[i][x]);
						v.push_back(sum[n-1][x]-sum[j][x]);
						v.push_back(sum[i][y]-sum[i][x]);
						v.push_back(sum[i][m-1]-sum[i][y]);
						v.push_back(sum[j][y]+sum[i][x]-(sum[j][x]+sum[i][y]));
						v.push_back(sum[n-1][y]+sum[j][x]-(sum[n-1][x]+sum[j][y]));
						v.push_back(sum[j][m-1]+sum[i][y]-(sum[i][m-1]+sum[j][y]));
						v.push_back(sum[n-1][m-1]+sum[j][y]-(sum[n-1][y]+sum[j][m-1]));
						sort(v.begin(),v.end());
						ans=max(ans,v[0]);
					}
				}
			}
		}
		return ans;
	}
};