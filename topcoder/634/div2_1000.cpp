#include <bits/stdc++.h>
using namespace std;
class SpecialStrings{
	public:
	string findNext(string s){
		int i,j,k,n=s.size();
		for(i=n-1;i>=0;i--)if(s[i]=='0')break;
		if(i==0 && n>1)return "";
		else if(i==0){
			return "1";
		}
		else if(i<0)return ""; 
		s[i]='1';
		for(j=i+1;j<n;j++)s[j]='1';
		for(j=i+1;j<n;j++){
			s[j]='0';
			for(k=1;k<n;k++)
				if((s.substr(k,n-k)).compare(s.substr(0,k))<=0)break;
			if(k<n)s[j]='1';
		}
		return s;
	}
};