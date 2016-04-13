#include <bits/stdc++.h>
using namespace std;
class SumAndProductPuzzle{
	public:
	long long getSum(int A,int B){
		static bool isp[5000001];
		static int fac[5000001];
		long long i,j,k,n,ans=0,x;
		for(i=0;i<5000001;i++)isp[i]=0,fac[i]=1;
		for(i=2;i<5000001;i++){
			if(isp[i]==1)continue;
			for(j=i*i;j<5000001;j+=i)isp[j]=1;
			for(j=i;j<5000001;j+=i){
				for(k=j,x=1;(k%i)==0;x++)k/=i;
				fac[j]*=x;
			}
		}
		for(i=4;i<5000001;i++){
			if(isp[i-1]==1)continue;
			for(j=1;j<(i-j) && (j*(i-j))<5000001LL;j++)fac[j*(i-j)]-=2;
			if(j==(i/2))fac[(i/2)*(i/2)]--;
		}
		for(i=4;i<5000001;i++){
			if(fac[i]==2 && (i+1)>=A && (i+1)<=B)ans+=(i+1);
		}
		return ans;
	}
};