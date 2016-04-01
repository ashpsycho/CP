#include <bits/stdc++.h>
using namespace std;
long long mod=1000000007,ans=0;
long long modpow(long long b,long long e){
	long long ans=1;
	while(e){
		if(e&1)ans=(ans*b)%mod;
		b=(b*b)%mod;
		e/=2;
	}
	return ans;
}
class RandomGCD{
	public:
	int countTuples(int N,int K,int lo,int hi){
		int i,j,k,p[100001],isp[40000],x,y,po[30],co[1024];
		po[0]=1;
		lo=(lo+K-1)/K;
		hi=hi/K;
		for(i=0;i<1024;i++)co[i]=(__builtin_popcount(i)&1)?-1:1;
		for(i=1;i<30;i++)po[i]=po[i-1]*2;
		map<int,int> s;
		s[1]=1;
		map<int,int>::iterator it;
		vector<int> f[100001];
		for(i=lo,j=0;i<=hi;i++,j++)p[j]=i;
		for(i=0;i<40000;i++)isp[i]=0;
		for(i=2;i<40000;i++){
			if(isp[i]==1)continue;
			for(j=i*i;j<40000;j+=i)isp[j]=1;
			for(j=i*(1+((lo-1)/i));j<=hi;j+=i){
				f[j-lo].push_back(i);
				while((p[j-lo]%i)==0)
					p[j-lo]/=i;
			}
		}
		for(i=lo;i<=hi;i++){
			if(p[i-lo]!=1)f[i-lo].push_back(p[i-lo]);
			for(j=1,k=(1<<(f[i-lo].size()));j<k;j++){
				for(x=0,y=1;x<f[i-lo].size();x++)if(j&po[x])y*=f[i-lo][x];
				s[y]=co[j];
			}
		}
		for(it=s.begin();it!=s.end();++it){
			j=it->first;
			k=it->second;
			i=(hi/j)-((lo-1)/j);
			i=modpow(i,N);
			if(k==1)ans=(ans+i)%mod;
			else ans=(ans+mod-i)%mod;
		}
		return ans;
	}
};