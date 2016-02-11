#include <bits/stdc++.h>
using namespace std;
bool fn(int po,int x,int y){
	if(po==0 && x==0 && y==0)return 1;
	if(x<=(po/2) && y<=(po/2))return 0;
	if(x<y)swap(x,y);
	if(y>(po/2) || abs(x-po)>(po/2) )return 0;
	return fn(po/3,abs(x-po),y);
}
class PowerOfThree{
	public:
	string ableToGet(int x,int y){
		x=abs(x);
		y=abs(y);
		int i,j;
		string s1="Possible",s2="Impossible";
		if(x==0 && y==0)return s1;
		for(i=19,j=(int)round(powl(3,19));i>=0;i--,j/=3){	
			if(fn(j,x,y))break;
		}
		return (i>=0)?s1:s2;
	}
};