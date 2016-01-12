#include <bits/stdc++.h>
using namespace std;
class CityMap{
	public:
	string getLegend(vector<string> g,vector<int>v){
		int i,j,k,n=g.size(),m=g[0].size(),Count[26];
		for(i=0;i<26;i++)Count[i]=0;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++)if(g[i][j]<='Z' && g[i][j]>='A')Count[g[i][j]-'A']++;
		}
		string ans="";
		for(i=0;i<v.size();i++){
			for(j=0;j<26;j++)if(Count[j]==v[i])break;
			ans=ans+(char)('A'+j);
		}
		return ans;
	}
};