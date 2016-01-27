#include <bits/stdc++.h>
using namespace std;
class TheNumberGameDivOne{
	public:
	string find(long long n){
		string win="John",lose="Brus";
		if((n%2)==1)return lose;
		int i=0;
		while((n%2)==0){
			n/=2;
			i++;
		}
		if(n==1 && (i&1))return lose;
		return win;
	}
};