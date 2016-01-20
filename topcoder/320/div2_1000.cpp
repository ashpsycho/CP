#include <bits/stdc++.h>
#include <sstream> 
using namespace std;
class T{
	public:
	int s,t,p;
	T(){}
	T(int s1,int t1,int p1){
		s=s1;
		t=t1;
		p=p1;
	}
};
bool fn(T a, T b){
	return (a.s<b.s);
}
class ContestSchedule{
	public:
	double expectedWinnings(vector<string> inp){
		int i,j,s,t,p,n=inp.size(),dp[n+1];
		T arr[n];
		for(i=0;i<n;i++){
			stringstream f1;
			f1<<inp[i];
			f1>>s>>t>>p;
			arr[i]=T(s,t,p);
		}
		sort(arr,arr+n,fn);
		double ans=0.0;
		dp[0]=0.0;
		for(i=0;i<n;i++){
			dp[i+1]=arr[i].p;
			for(j=0;j<i;j++){
				if(arr[j].t<=arr[i].s)
					dp[i+1]=max(dp[i+1],arr[i].p+dp[j+1]);
			}
			ans=max(ans,(double)dp[i+1]);
			cout<<dp[i+1]<<" ";
		}
		return (ans/100.0);
	}
};