#include<bits/stdc++.h>
using namespace std;
long long mod=1000000007;
class ThePermutationGame{
	public:
	int findMin(int n){
		long long i,j,k,ans=1;
		for(i=2;i<=n;i++){
			for(j=2;(j*j)<=i;j++)if((i%j)==0)break;
			if((j*j)>i){
				for(k=1;(k*i)<=n;k*=i);	
				ans=ans*k;
				ans=ans%mod;}
		}
		return ans;
	}
};