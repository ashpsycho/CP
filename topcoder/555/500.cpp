#include <bits/stdc++.h>
using namespace std;
class XorBoard{
	public:
	int count(int H,int W,int rc,int cc,int s){
		static long long i,j,k,ans=0,mod=555555555,ncr[2500][2500];
		for(i=0;i<2500;i++)
			for(j=0;j<2500;j++)ncr[i][j]=0;
		for(i=0;i<2500;i++)ncr[i][0]=1;
		for(i=1;i<2500;i++)
			for(j=1;j<2500;j++)ncr[i][j]=(ncr[i-1][j]+ncr[i-1][j-1])%mod;
		for(i=rc&1;i<=rc && i<=H;i+=2){
			for(j=cc&1;j<=cc && j<=W;j+=2){
				k=i*(W-j) + j*(H-i);
				if(s!=k)continue;
				ans=ans+(((ncr[H][i]*ncr[W][j])%mod)*((ncr[H+((rc-i)/2)-1][H-1]*ncr[W+((cc-j)/2)-1][W-1])%mod))%mod;
				ans=ans%mod;
			}
		}
		return ans;
	}
};