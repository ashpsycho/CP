#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
using namespace std;
bool fn(T a,T b){	
	return (a.x+b.x-a.y)<(b.x+a.x-b.y);
}
class AlbertoTheAviator{
	public:
	int MaximumFlights(int F,vector<int>dur,vector<int>ref){
		static int i,j,k,n=dur.size(),dp[5001][51][2];
		vector<T>v;
		for(i=0;i<n;i++)v.push_back(T(dur[i],ref[i]));
		sort(v.begin(),v.end(),fn);
		for(i=0;i<5001;i++)
			for(j=0;j<51;j++)dp[i][j][0]=dp[i][j][1]=0;
		dp[F][0][0]=1;
		for(i=0;i<n;i++){
			for(j=v[i].x;j<=F;j++){
				for(k=0;k<n;k++)
					if(dp[j][k][0]==1)dp[j+v[i].y-v[i].x][k+1][1]=1;
			}
			for(j=0;j<=F;j++){
				for(k=0;k<=n;k++){
					dp[j][k][0]=max(dp[j][k][0],dp[j][k][1]);
					dp[j][k][1]=0;
				}
			}
		}
		for(i=n;i>=0;i--){
			for(j=0;j<=F;j++)if(dp[j][i][0]==1)break;
			if(j<=F)break;
		}
		return i;
	}
};