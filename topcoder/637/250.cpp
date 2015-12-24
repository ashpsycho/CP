#include <bits/stdc++.h>
#define T pair<int,int>
#define x first
#define y second
#define MAX 100001
using namespace std;
class GreaterGame{
	public:
	double calc(vector<int>me,vector<int>hek){
		int i,j,k,n=me.size();
		vector<int> he,known;		// he basically contains what "he" has but position unknown
		for(i=0;i<n;i++)known.push_back(me[i]);
		for(i=0;i<n;i++)if(hek[i]!=-1)known.push_back(hek[i]);
		for(i=1;i<=(2*n);i++){
			for(j=0;j<known.size();j++){
				if(known[j]==i)break;
			}
			if(j==known.size())he.push_back(i);
		}
		double ans=0.0;
		sort(hek.begin(),hek.end());
		reverse(hek.begin(),hek.end());
		sort(me.begin(),me.end());
		for(i=0;i<n && hek[i]!=-1;i++){
			for(j=0;j<me.size();j++)if(me[j]>hek[i])break;
			if(j==me.size()){
				me.erase(me.begin());
			}
			else{
				me.erase(me.begin()+j);
				ans+=1.0;
			}
		}
		for(i=0;i<me.size();i++){
			for(j=k=0;j<he.size();j++)if(me[i]>he[j])k++;
			ans+=(((double)k)/((double)me.size()));
		}
		return ans;
	}	
};