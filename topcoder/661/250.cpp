#include <bits/stdc++.h>
using namespace std;
class MissingLCM{
	public:
	int getMin(int n){
		long long i,j,k,m=n+1,isp[1000001];
		for(i=0;i<1000001;i++)isp[i]=0;
		for(i=2;i<1000001;i++){
			if(isp[i])continue;
			for(j=i*i;j<=1000001;j+=i)isp[j]=1;
		}
		for(i=2;i<=n;i++){
			if(isp[i])continue;
			for(j=1;(j*i)<=n;j*=i);
			k=1+(n/j);
			m=max(m,k*j);
		}
		return m;
	}
};