#include <bits/stdc++.h>
using namespace std;
class TheSquareRootDilemma{
	public:
	int countPairs(int N,int M){
		int i,j,k,ans=0,curr,n;
		for(i=1;i<=N;i++){
			for(j=2,curr=1,n=i;(j*j)<=n;j++){
				for(k=0;(n%j)==0;n/=j,k++);
				if(k&1)curr*=j;
				if(j!=2)j++;
			}
			curr*=n;
			for(j=1;(curr*j*j)<=M;j++);
			ans+=(j-1);
		}
		return ans;
	}
};