#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
using namespace std;
class PairGame{
	public:
	int maxSum(int a,int b,int c,int d){
		if(__gcd(a,b)!=__gcd(c,d))return -1;
		vector<T> v1,v2;
		int k=2*__gcd(a,b);
		while(a!=b && c!=d){
			if(a==c && b==d)k=max(k,(a+b));
			if((a+b)>(c+d)){
				if(a<b)b-=a;
				else a-=b;
			}
			else{
				if(c>d)c-=d;
				else d-=c;
			}
		}	
		return k;
	}
};