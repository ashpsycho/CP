#include <iostream>
#include <cstdio>
using namespace std;
class seg_tree{
public:
	static long long add[2100000],sum[2100000],level;
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
	return 0;
}