#include <bits/stdc++.h>
using namespace std;
class SplitStoneGame{
	public:
	string winOrLose(vector<int>v){
		int n=v.size();
		sort(v.begin(),v.end());
		if(v[n-1]==1 || n<3)return "LOSE";
		return ((n&1)==1)?"WIN":"LOSE";
	}
};