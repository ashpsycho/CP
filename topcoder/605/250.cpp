#include <bits/stdc++.h>
using namespace std;
class AlienAndHamburgers{
	public:
	int getNumber(vector<int> t1,vector<int> t2){
		int i,j,k,n=t1.size(),ans=0;
		vector<int> v,t;
		for(i=0;i<101;i++){
			t.clear();
			for(j=0;j<n;j++)if(t1[j]==i)t.push_back(t2[j]);
			sort(t.begin(),t.end());
			reverse(t.begin(),t.end());
			if(t.size()==0)continue;
			if(t[0]<0){
				v.push_back(t[0]);
				continue;
			}
			for(j=k=0;j<t.size() && t[j]>0;j++)k+=t[j];
			v.push_back(k);
		}
		sort(v.begin(),v.end());
		reverse(v.begin(),v.end());
		for(i=j=k=0;i<v.size();i++){
			j++;
			k+=v[i];
			if((j*k)<ans)break;
			ans=(j*k);
		}
		return ans;
	}
};