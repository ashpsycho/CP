#include <bits/stdc++.h>
using namespace std;
class LeftRightDigitsGame{
	public:
	string minNumber(string s){
		int i,j,k,n=s.size(),coun[256];
		string ans="",add;
		for(i=0;i<128;i++)coun[i]=0;
		for(i=0;i<n;i++)coun[(int)s[i]]++;
		for(i='1';i<='9';i++)if(coun[i]>0)break;
		add=(char)i;
		for(k=n-1;k>=0 && s[k]!=(char)i;k--);
		if(k==0)return s;
		ans=s[0];
		for(j=1;j<k;j++){
			if(s[j]<=ans[0])ans=s[j]+ans;
			else ans=ans+s[j];
		}
		for(j=k+1;j<n;j++)ans=ans+s[j];
		return add+ans;
	}
};