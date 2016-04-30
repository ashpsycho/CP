#include <bits/stdc++.h>
using namespace std;
class ThreeProgrammers{
	public:
	string validCodeHistory(string s){
		sort(s.begin(),s.end());
		int Count[3]={0,0,0},n=s.size(),i,j,k,tot=n;
		string fail="impossible";
		for(i=0;i<n;i++){
			Count[s[i]-'A']++;
		}
		if(Count[2]==0){
			string ans="";
			for(i=0;i<n;i++)ans+="x";
			for(i=0;i<n && Count[1]>0;i++){
				if(i==0 || ans[i-1]!='B'){
					ans[i]='B';
					Count[1]--;
				}
			}
			if(Count[1]>0)return fail;
			for(i=0;i<ans.size();i++){
				if(ans[i]=='x')ans[i]='A';
			}
			return ans;
		}
		vector<int>v;
		v.push_back(0);
		if(((n-1)/3)<(Count[2]-1))return fail;
		tot-=Count[2];
		for(i=0;i<(Count[2]-1);i++){
			v.push_back(2);
			tot-=2;
		}
		v.push_back(0);
		if(tot>0){
			v[0]=1;
			tot--;
		}
		if(tot>0){
			v[v.size()-1]=1;
			tot--;
		}
		for(i=1;i<(v.size()-1) && tot>0;i++){
			tot--;
			v[i]++;
		}
		v[v.size()-1]+=tot;
		string ans="";
		for(i=0;i<v[0];i++)ans+="x";
		for(i=1;i<v.size();i++){
			ans+="C";
			for(j=0;j<v[i];j++)ans+="x";
		}
		for(i=0;i<ans.size() && Count[1]>0;i++){
			if(ans[i]!='x')continue;
			if(i==0 || ans[i-1]!='B'){
				ans[i]='B';
				Count[1]--;
			}
		}
		if(Count[1]>0)return fail;
		for(i=0;i<ans.size();i++){
			if(ans[i]=='x')ans[i]='A';
		}
		return ans;
	}
};