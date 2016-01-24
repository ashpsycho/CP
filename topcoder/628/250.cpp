#include <bits/stdc++.h>
using namespace std;
class DivisorsPower{
	public:
	long long findArgument(long long n){
		long long i,j,k,curr;
		for(i=2;i<61;i++){
			j=(long long)roundl(powl(n,1.0/(long double)i));
			if(n!= (long long)roundl(powl(j,i)))continue;
			for(k=1,curr=0;(k*k)<=j;k++){
				if((j%k)==0){
					curr++;
					if((k*k)!=j)curr++;
				}
			}
			if(curr==i)return j;
		}
		return -1;
	}
};