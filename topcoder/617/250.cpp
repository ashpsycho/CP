#include <bits/stdc++.h>
using namespace std;
class MyLongCake{
	public:
	int cut(int n){
		int i,ans=1;
		for(i=1;i<n;i++)if(__gcd(n,i)!=1)ans++;
		return ans;
	}
};