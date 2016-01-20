#include <bits/stdc++.h>
using namespace std;
class BagAndCards{
	public:
	int getHash(int n,int m,int x,int a,int b,int c,string check){
		static int i,j,k,inp[501][501],comp[501][501];
		long long mod=1000000007,ans=0,lol;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				inp[i][j]=x;
				x=(int)(((1LL*x*a + 1LL*b) ^ (1LL*c))%mod); 
			}
		}
		for(i=0;i<501;i++)
			for(j=0;j<501;j++)comp[i][j]=0;
		
		for(i=1;i<n;i++){
			for(j=0;j<m;j++){
				for(k=0;k<m;k++){
					if(check[j+k]=='N')continue;
					comp[i][j]=(comp[i][j]+inp[i][k])%mod;
				}
			}
		}
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				for(k=lol=0;k<m;k++){
					lol=lol+(1LL*inp[i][k]*comp[j][k])%mod;
				}
				lol=lol%mod;
				ans=ans^lol;
			}	
		}
		return ans;
	}
};