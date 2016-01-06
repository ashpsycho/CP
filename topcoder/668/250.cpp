#include <bits/stdc++.h>
using namespace std;
class PaintTheRoom{
	public:
	string canPaintEvenly(int r,int c,int k){
		if(k==1||(r%2)==0||(c%2)==0)return "Paint";
		return "Cannot paint";
	}
};