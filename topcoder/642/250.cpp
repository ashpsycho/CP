#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
#define MAX 200002
using namespace std;
class WaitingForBus{
	public:
	double whenWillBusArrive(vector<int> t,vector<int> p,int s){
		int i,j,k,n=t.size();
		static double dp[MAX],ans;
		dp[0]=1.0;
		for(i=1;i<MAX;i++)dp[i]=0.0;
		for(i=0;i<s;i++){
			for(j=0;j<n;j++){
				dp[i+t[j]]+=(dp[i]*((double)p[j])/100.0);
			}
		}
		for(i=s;i<MAX;i++)ans+=((i-s)*dp[i]);
		return ans;
	}	
};