#include <bits/stdc++.h>
using namespace std;
class PlanarGraphShop{
	public:
	int bestCount(int N){
		int i,j,k,ans[50001],isp[50001];
		for(i=0;i<50001;i++)ans[i]=-1,isp[i]=0;
		ans[0]=0;
		for(i=0;i<40;i++){
			if(i<5)k=(i*(i-1))/2;
			else k=6+(3*(i-4));
			for(j=0;j<=k;j++){
				if((j*j + i*i*i)<=50000)isp[j*j + i*i*i]=ans[j*j + i*i*i]=1; 
			}
		}
		vector<int> p;
		for(i=0;i<=50000;i++)if(isp[i])p.push_back(i);
		cout<<p.size();
		for(i=0;i<=50000;i++){
			if(ans[i]>=0)continue;
			ans[i]=1000000;
			for(j=0;j<p.size()&&p[j]<=i;j++)ans[i]=min(ans[i],1+ans[i-p[j]]);
		}
		return ans[N];
	}	
};