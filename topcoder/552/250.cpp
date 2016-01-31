#include <bits/stdc++.h>
using namespace std;
class FoxPaintingBalls{
	public:
	long long theMax(long long R,long long G,long long B,int n){
		long long i=(1LL*n*(n+1))/2LL,j=(i/3),k=i-(j*2);
		if(n==1)return (R+G+B);
		if(k==j)return min((R/j),min((G/j),(B/j)));
		i=min((R/j),min((G/j),(B/j)));
		R-=(j*i);
		G-=(j*i);
		B-=(j*i);
		if(i>(R+G+B)){
			k=R+G+B;
			k=(i+j*3-k)/(j*3+1);
			i-=k;
		}
		return i;
	}
};