#include <bits/stdc++.h>
#include <fstream>
using namespace std;

class seg_tree{
public:
	long long add[2100000],sum[2100000],level;
	seg_tree(){
		for(int i=0;i<2100000;i++)add[i]=sum[i]=0;
	}
	long long ans(int x,int y)
	{
		int x1,i,j=x+(1<<level),k=y+(1<<level),start=j;
		long long ans=0,len=1;
		while((start+len-1)<=k){
			while(j%2==0&&(start+len*2-1)<=k)
			{
				j/=2;
				len*=2;
			}
			ans+=sum[j];
			for(i=(j/2);i>0;i/=2)
				ans+=(len*add[i]);
			j=j+1;
			start+=len;
		}
		while(start<=k)
		{
			while((start+len-1)>k&&len>1)
			{
				len/=2;
				j*=2;
			}
			ans+=sum[j];
			for(i=(j/2);i>0;i/=2)
				ans+=(len*add[i]);
			start+=len;
			j=j+1;
		}
		return ans;
	}
	void up(int x,int y,long long v)
	{
		int i,j=x+(1<<level),k=y+(1<<level),start=j;
		long long len=1;
		while((start+len-1)<=k){
			while(j%2==0&&(start+len*2-1)<=k)
			{
				j/=2;
				len*=2;
			}
			add[j]+=v;
			for(i=j;i>0;i/=2)
				sum[i]+=(v*len);
			j=j+1;
			start+=len;
		}
		while(start<=k)
		{
			while((start+len-1)>k&&len>1)
			{
				len/=2;
				j*=2;
			}
			add[j]+=v;
			for(i=j;i>0;i/=2)
				sum[i]+=(v*len);
			start+=len;
			j=j+1;
		}
	}
};

int main(){
	long long t,te,i,j,k,m,ans=0, aw, bw,ad,bd,as,bs,w1,d1,s1, mod=1e9+7;
	ofstream fout("output.txt");
	static long long w[1000001],s[1000001],d[1000001];
	cin>>t;
	for(te=0;te<t;te++){
		cin>>n>>m;
		cin>>w1>>aw>>bw;
		cin>>d1>>ad>>bd;
		cin>>s1>>as>>bs;
		for(i=0,j=w1;i<m;i++){
			w[i]=j;
			j=1+(j*aw + bw)%n;
		}
		for(i=0,j=d1;i<m;i++){
			d[i]= max(1LL,min ( n, w[i]+j-1));
			j=(j*ad + bd)%3;
		}
		for(i=0,j=s1;i<m;i++){
			s[i]=j;
			j=1+(j*as + bs)%1000000000;
		}
		for(i=0;i<m;i++){

		}
		fout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
		cout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
	}
	return 0;
}