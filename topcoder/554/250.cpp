#include <bits/stdc++.h>
using namespace std;
class TheBrickTowerEasyDivOne{
	public:
	int find(int rC,int rH,int bC,int bH){
		if(rH==bH){
			rC=min(rC,bC+1);
			bC=min(bC,rC+1);
			return rC+bC;
		}
		int ans=min(rC,bC);
		if(rC<=bC)ans+=rC;
		else ans+=(bC+1);
		if(bC<=rC)ans+=bC;
		else ans+=(rC+1);
		return ans;
	}
};