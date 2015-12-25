#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
#define MAX 100001
using namespace std;
long long mod=1000000007;
class OkonomiyakiParty{
	public:
	int count(vector<int> v,int M,int K){
		long long i,j,k,n=v.size(),ans=0LL,ncr[51][51];
		for(i=0;i<51;i++)
			for(j=0;j<51;j++)ncr[i][j]=0;
		for(i=0;i<51;i++)ncr[i][0]=1;
		for(i=1;i<51;i++){
			for(j=1;j<51;j++)ncr[i][j]=(ncr[i-1][j]+ncr[i-1][j-1])%mod;
		}
		sort(v.begin(),v.end());
		for(i=0;i<n;i++){
			for(j=i+1,k=0;j<n;j++){
				if((v[j]-v[i])<=K)k++;
			}
			if(k<(M-1))continue;
			ans=(ans+ncr[k][M-1])%mod;
		}
		return ans;
	}	
};