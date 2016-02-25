#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
using namespace std;
class TheBrickTowerMediumDivOne{	
	public:
	vector<int>find(vector<int> h){
		int i,j,n=h.size();
		vector<int>ans;
		vector<T>v;
		for(i=0;i<n;i++)v.push_back(T(h[i],i));
		for(i=0,j=10000;i<n;i++){
			if(v[i].x<=j){
				j=v[i].x;
				ans.push_back(i);
			}
		}
		for(i=ans.size()-1;i>=0;i--)v.erase(v.begin()+ans[i]);
		sort(v.begin(),v.end());
		for(i=0;i<v.size();i++)ans.push_back(v[i].y);
		return ans;
	}
};