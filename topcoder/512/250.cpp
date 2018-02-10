#include <bits/stdc++.h>
using namespace std;

int val( char c){
	if(c<='9')return c-'0';
	if(c<='Z')return (10+c-'A');
	return 36+c-'a';
}

int minCost(vector<string> v){
	if(v.size()==0)return 0;
	int ans=1000000000, curr=0;
	for(int j=0;j<v[0].size();j++){
		for(int i=curr=0;i<v.size();i++){
			curr+=val(v[i][j]);
		}
		ans=min(ans, curr);
	}
	return ans;
}

bool isp(vector<string> p, int b, int d){
	vector<string> cur[7];
	for(int i=0;i<d;i++){
		cur[i%7].push_back(p[i]);
	}
	int sum=0;
	for(int i=0;i<7;i++){
		sum +=minCost(cur[i]);
	}
	return (sum<=b);
}

class MysteriousRestaurant{
public:
	int maxDays(vector<string> p, int b){
		for(int i=p.size();i>0;i--){
			if(isp(p,b,i))return i;
		}
		return 0;
	}
};