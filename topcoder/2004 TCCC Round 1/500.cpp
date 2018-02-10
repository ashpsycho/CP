#include <bits/stdc++.h>
using namespace std;
#define TT pair<int,int>
#define T pair<int, TT>
#define x first
#define y second
class FlowerGarden{
	public:
	vector<int> getOrdering(vector<int> h,vector<int> b, vector<int> w){
		int i,j,k,n=h.size();
		vector<int> ans;
		vector<T> arr;
		for(i=0;i<n;i++){
			arr.push_back(T(-h[i],TT(b[i],w[i])));
		}
		sort(arr.begin(),arr.end());
		for(i=0;i<n;i++){
			for(j=0;j<arr.size();j++){
				for(k=j+1;k<arr.size();k++){
					if(arr[k].y.y<arr[j].y.x || arr[j].y.y<arr[k].y.x)continue;
					break; 
				}
				if(k==arr.size())break;
			}
			ans.push_back(-arr[j].x);
			arr.erase(arr.begin()+j);
		}
		return ans;
	} 
};