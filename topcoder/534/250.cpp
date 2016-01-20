#include<bits/stdc++.h>
using namespace std;
class EllysCheckers{
	public:
	string getWinner(string s){
		int i,k=0,n=s.size();
		for(i=0;i<(n-1);i++){
			if(s[i]=='.')continue;
			k+=((n-1)-i);
		}
		return (k&1)?"YES":"NO";
	}
};