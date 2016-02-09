#include <bits/stdc++.h>
using namespace std;
class LittleElephantAndBalls{
	public:
	int getNumber(string s){
		int a=0,b=0,i,k,ans=0,n=s.size();
		for(i=0;i<n;i++){
			if(s[i]=='R')k=1;
			else k=(s[i]=='G')?2:4;
			ans+=__builtin_popcount(a);
			ans+=__builtin_popcount(b);
			if((a&k)==0)
				a=a|k;
			else b=b|k;
		}
		return ans;
	}
};