#include <bits/stdc++.h>
using namespace std;
class TheDivisionGame{
	public:
	long long countWinningIntervals(int L,int R){
		static long long ans=0,ab=R+1-L,j,dp[32];
		ab=(ab*(ab+1))/2;
		static int i,k,isp[40001],arr[1000001],curr[1000001];
		for(i=0;i<1000001;i++)arr[i]=0;
		for(i=0;i<40001;i++)isp[i]=1;
		for(i=2;i<40001;i++){
			if(isp[i]==0)continue;
			for(j=i*i;j<40001;j+=i)isp[j]=0;
		}
		for(i=L;i<=R;i++)curr[i-L]=i;
		for(i=2;i<40001;i++){
			if(isp[i]==0)continue;
			for(j=i;j<=R;j*=i){
				for(k=((L+j-1)/j)*j;k<=R;k+=j){
					curr[k-L]/=i;
					arr[k-L]++;
				}
			}
		}
		for(i=L;i<=R;i++)if(curr[i-L]>1)arr[i-L]++;
		for(i=0;i<32;i++)dp[i]=0;
		dp[0]=1;
		for(i=L,j=0;i<=R;i++){
			j=j^arr[i-L];
			dp[j]++;
		}
		for(i=0;i<32;i++)ans=ans+(1LL*dp[i]*(dp[i]-1))/2LL;
		return ab-ans;
	}
};