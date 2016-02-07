#include <bits/stdc++.h>
using namespace std;
class HyperKnight{
	public:
	long long countCells(int a,int b,int nR,int nC,int k){
		if(k==0||k==1||k==5||k==7)return 0;
		long long ans[9];
		if(a>b)swap(a,b);
		ans[2]=4LL*(1LL*a*a);
		ans[3]=8LL*(1LL*a*b - 1LL*a*a);
		ans[4]=2LL*(1LL*a*(nC-b)-1LL*a*b);
		ans[4]+=(2LL*(1LL*a*(nR-b)-1LL*a*b));
		ans[4]+=(4LL*(1LL*b*b + 1LL*a*a -2LL*a*b));
		ans[6]=2LL*(b-a)*(nR-2*b);
		ans[6]+=(2LL*(b-a)*(nC-2*b));
		ans[8]=1LL*nR*nC;
		ans[8]-=(ans[2]+ans[3]+ans[4]+ans[6]);
		return ans[k];
	}
};