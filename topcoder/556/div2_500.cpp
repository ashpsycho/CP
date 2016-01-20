#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
#define MAX 100001
using namespace std;
long long mod=1000000007;
class XorTravelingSalesman{
	public:
	int maxProfit(vector<int> v,vector<string> g){
		int i,j,k,n=g.size(),dp[50][1024];
		for(i=0;i<n;i++)
			for(j=0;j<1024;j++)dp[i][j]=0;
		queue<T>q;
		T a;
		q.push(T(0,v[0]));
		dp[0][v[0]]=1;
		while(!q.empty()){
			a=q.front();
			q.pop();
			for(i=0;i<n;i++){
				if(a.x==i)continue;
				if(g[a.x][i]=='N')continue;
				if(dp[i][a.y^v[i]]==1)continue;
				q.push(T(i,a.y^v[i]));
				dp[i][a.y^v[i]]=1;
			}
		}
		for(i=1023;i>=0;i--){
			for(j=0;j<n;j++)if(dp[j][i]==1)return i;
		}
		return i;
	}	
};