#include <bits/stdc++.h>
using namespace std;
class NewArenaPassword{
	public:
	int minChange(string s,int K){
		if(s.substr(0,K)==s.substr(s.size()-K))return 0;
		int i,n=s.size(),j=n-K,k,coun[26],ma,ans=0;
		vector<int> v;
		for(i=0;i<K;i++){
			v.clear();
			for(k=0;k<26;k++)coun[k]=0;
			for(k=i;k<K;k+=j){
				v.push_back(k);
				coun[s[k]-'a']++;
			}
			if(k<n){
				v.push_back(k);
				coun[s[k]-'a']++;
			}
			for(k=ma=0;k<26;k++)if(coun[k]>coun[ma])ma=k;
			ans+=(v.size()-coun[ma]);
			for(k=0;k<v.size();k++)s[v[k]]=(char)('a'+ma);
		}
		ans=min(ans,n-1);
		return ans+minChange(s,K);
	}
};