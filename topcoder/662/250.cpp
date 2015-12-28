#include <bits/stdc++.h>
using namespace std;
#define T pair<int,int>
#define x first
#define y second
class FoxesOfTheRoundTable{
	public:
	vector<int> minimalDifference(vector<int> h){
		int i,n=h.size();
		vector<T> v;
		for(i=0;i<n;i++)v.push_back(T(h[i],i));
		sort(v.begin(),v.end());
		vector<int> ans;
		ans.push_back(v[0].y);
		ans.push_back(v[1].y);
		for(i=2;i<v.size();i++){
			if((v[i].x-h[ans[i-1]])<(v[i].x-h[ans[0]])){
				ans.insert(ans.begin(),v[i].y);
			}
			else ans.push_back(v[i].y);
		}
		for(i=0;i<ans.size();i++)cout<<ans[i]<<" ";
		cout<<"\n";
		for(i=0;i<ans.size();i++)cout<<h[ans[i]]<<" ";
		cout<<"\n";
		return ans;
	}
};