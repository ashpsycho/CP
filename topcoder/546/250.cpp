#include <bits/stdc++.h>
using namespace std;
class KleofasTail{
	public:
	long long countGoodSequences(long long K,long long A,long long B){
		long long j,k,mi=K,ma=K,ans=0;
		while(mi<=B){
			if((ma%2LL)==0)ma++;
			j=max(A,mi);
			k=min(B,ma);
			ans+=max(0LL,k+1-j);
			mi=max(ma+1,mi*2);
			ma=1+(2*ma);
		}
		return ans;
	}
};