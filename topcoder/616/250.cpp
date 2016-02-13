#include<bits/stdc++.h>
using namespace std;
class WakingUp{
	public:
	int maxSleepiness(vector<int>p,vector<int>st,vector<int>vol,int D){	
		int i,j,k,n=st.size(),m=1,z;
		for(i=0;i<n;i++)m=m*(p[i]/__gcd(m,p[i]));
		for(i=1,j=0,k=0;i<=m;i++){
			j+=D;
			for(z=0;z<n;z++)if((i>=st[z])&&((i-st[z])%p[z])==0)j-=vol[z];
			k=min(k,j);
		}
		if(j<0)return -1;
		return (k*(-1));
	}
};