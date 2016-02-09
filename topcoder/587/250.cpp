#include <bits/stdc++.h>
using namespace std;
class JumpFurther{
	public:
	int furthest(int n,int K){
		int i,j,ans=(n*(n+1))/2;
		for(i=1,j=0;i<=n;i++){
			j+=i;
			if(j==K)break;
		}
		if(i<=n)ans--;
		return ans;
	}
};