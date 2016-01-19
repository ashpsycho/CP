#include <bits/stdc++.h>
using namespace std;
class CountryGroupHard{
	public:
	string solve(vector<int>v){
		int i,j,k,n=v.size(),isp[101];
		for(i=0;i<=n;i++)isp[i]=0;

		isp[0]=1;
		for(i=1;i<=n;i++){
			for(j=1;j<=i;j++){
				if(isp[i-j]==0)continue;
				for(k=i-j;k<i;k++){
					if(v[k]!=0 && v[k]!=j)break;
				}
				if(k==i)
					isp[i]+=isp[i-j];
			}
		}
		for(i=1,j=0;i<=n;i++)j+=dp[n][i];
		if(j==1)return "Sufficient";
		return "Insufficient";
	}
};